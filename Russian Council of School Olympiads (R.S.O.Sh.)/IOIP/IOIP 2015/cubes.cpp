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
typedef unsigned long long int ll;
typedef long double ld;







int main() {
    freopen("cubes.in", "r", stdin);
    freopen("cubes.out", "w", stdout);

    int n;
    int ms[1000 + 5];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> ms[i];
    sort(ms, ms + n);
    reverse(ms, ms + n);
    int maxi = 1000000000;
    for(int i = 1; i <= 1000; i++) {
        int pl = 0;
        int ans = 0;
        for(int z = 0; z < n; z++) {
            if(ms[z] >= i) {
                pl += ms[z] - i;
                ans += ms[z] - i;
            } else {
                int meg = min(i - ms[z], pl);
                pl -= meg;
                ans += i - ms[z] - meg;
            }
        }
        maxi = min(maxi, ans);
    }
    cout << maxi;
}