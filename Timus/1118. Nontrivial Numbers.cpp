#include <bits/stdc++.h>
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
#define mem0d(m) memset((m), 0.0, sizeof(m));
#define memb(m) memset((m), false, sizeof(m));
typedef long long int ll;
typedef long double ld;




int main() {
    ld sum[1000005];
    for(int i = 0; i < 1000005; i++) {
        sum[i] = 0;
    }

    for(int i = 1; i <= 1000000; i++) {
        for(int z = i * 2; z <= 1000000; z += i) {
            sum[z] += i;
        }
    }

    int i, j;
    scanf("%d%d", &i, &j);

    ld mini = 1000000000.0;
    int ans;
    for(ld n = i; n <= j; n++) {
        if(sum[(int)n] / n < mini) {
            mini = sum[(int)n] / n;
            ans = (int)n;
        }
    }

    printf("%d", ans);
}



















