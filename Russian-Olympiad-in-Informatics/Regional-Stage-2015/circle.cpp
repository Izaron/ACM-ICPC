#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define pss pair<int,int>
#define pdd pair<double,double>
#define pldd pair<ld,ld>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define ff first
#define ss second
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;





int main() {
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);

    ll n;
    cin >> n;

    if(n % 2 == 1) {
        cout << n * (n - 1);
    } else {
        cout << n * (n - 1) - n;
    }
}
 
