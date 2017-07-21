#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define pss pair<int,int>
#define pdd pair<double,double>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define ff first
#define ss second
typedef long long int ll;
typedef long double ld;





const int N = 1000 + 5;

int gett(ll n, ll vol) {
    if(n == 1)
        return 0;
    if(n <= vol / 2)
        return gett(n, vol / 2);
    else
        return gett(n - vol / 2, vol / 2) + 1;
}

int main() {
    #ifdef ONLINE_JUDGE
        freopen("hat.in", "r", stdin);
        freopen("hat.out", "w", stdout);
    #endif // ONLINE_JUDGE

    int q;
    scanf("%d", &q);
    while(q--) {
        ll n, p;
        scanf("%I64d%I64d", &n, &p);
        ll vol = 1ll;
        while(vol < n)
            vol *= 2ll;
        printf("%d\n", gett(n, vol) % p);
    }
}








