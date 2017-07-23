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
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        ll a, b;
        cin >> a >> b;
        if(b % a != 0) {
            cout << 0 << endl;
            continue;
        }
        b /= a;
        int ans = 1;
        for(int z = 2; z <= sqrt(b); z++) {
            while(b % z == 0) {
                b /= z;
                ans++;
            }
        }
        if(b > 1) ans++;
        cout << ans << endl;
    }
}








