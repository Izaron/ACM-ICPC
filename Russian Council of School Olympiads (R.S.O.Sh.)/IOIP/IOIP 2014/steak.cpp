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







int main() {
    freopen("steak.in", "r", stdin);
    freopen("steak.out", "w", stdout);

    ll k;
    cin >> k;
    ll tmp = k / 5;
    ll kek = tmp * (tmp + 1) / 2 * 5;
    tmp *= 5;
    kek += (tmp / 5 + 1) * (k - tmp);
    cout << kek * 30;
}



