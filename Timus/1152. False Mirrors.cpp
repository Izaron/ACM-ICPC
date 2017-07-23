#include <stdio.h>
#include <map>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define eb emplace_back
#define pb push_back
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define mem0(m) memset((m), 0, sizeof(m));
#define memb(m) memset((m), false, sizeof(m));
typedef long long int ll;
typedef long double ld;



const int N = 20;

int n;
int m[N];
map<pii, int> mp;

int dfs(int curr, int mask, int sum) {
    if(mp.count(mkp(curr, mask))) {
        return mp[mkp(curr, mask)];
    }
    if(sum == 0) {
        mp[mkp(curr, mask)] = 0;
        return 0;
    }
    int ans = 10000000;
    for(int i = 0; i < n; i++) {
        int a = i, b = (i + 1) % n, c = (i + 2) % n;
        int sm = sum;
        int tmask = mask;
        if((tmask & (1 << a)) != 0 && (tmask & (1 << b)) != 0 &&
                (tmask & (1 << c)) != 0)
            continue;
        if((tmask & (1 << a)) == 0)
            sm -= m[a];
        if((tmask & (1 << b)) == 0)
            sm -= m[b];
        if((tmask & (1 << c)) == 0)
            sm -= m[c];
        tmask |= (1 << a);
        tmask |= (1 << b);
        tmask |= (1 << c);

        ans = min(ans, sm + dfs(curr + 1, tmask, sm));
    }
    mp[mkp(curr, mask)] = ans;
    return ans;
}

int main() {
    scanf("%d", &n);

    int sum = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
        sum += m[i];
    }

    printf("%d", dfs(0, 0, sum));
}



















