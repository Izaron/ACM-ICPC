#include <stdio.h>
#include <random>
#include <string.h>
#include <iostream>
#include <map>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef long double ld;

const int maxn = 19;

int k;
map<string, ll> mp;
ll mask[maxn];
int cnt = 0;
map<pair<int, ll>, int> ank;

int dp(int v, ll msk, int cur) {
    if (v == k)
        return cur;
    pair<int, ll> pr = mkp(v, msk);
    if (ank.count(pr))
        return ank[pr];
    int ans = 0;
    ans = max(ans, dp(v + 1, msk, cur));
    if ((msk & mask[v]) == 0)
        ans = max(ans, dp(v + 1, msk | mask[v], cur + 1));
    ank[pr] = ans;
    return ans;
}

int main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    cin >> k;
    for (int i = 0; i < k; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        if (!mp.count(a))
            mp[a] = cnt++;
        if (!mp.count(b))
            mp[b] = cnt++;
        if (!mp.count(c))
            mp[c] = cnt++;
        int a1 = mp[a], b1 = mp[b], c1 = mp[c];
        mask[i] = (1LL << a1) + (1LL << b1) + (1LL << c1);
    }

    cout << dp(0, 0, 0);
}
