#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define mkp make_pair
#define pb push_back
using namespace std;
 
 
ll maxis[200000];
 
ll brute(ll n) {
    ll maxi = 0;
    for (ll a = 0; a <= n; a++) {
        for (ll b = a; b <= n - a; b++) {
            ll c = n - a - b;
            if (c < b)
                break;
            ll curr = (a & b & c);
            maxi = max(maxi, curr);
        }
    }
    return maxi;
}
 
ll cool(ll n) {
    ll maxi = 0;
    for (ll a = 0; a <= n; a++) {
        ll c = n - 2 * a;
        if (c < 0)
            break;
        ll curr = (a & c);
        maxi = max(maxi, curr);
    }
    return maxi;
}
 
void solve() {
    ll n, aa = 0, bb = 0, cc = 0, maxi = -1;
    cin >> n;
    for (ll a = 0; a <= n; a++) {
        ll c = n - 2 * a;
        if (c < 0)
            break;
        ll curr = (a & c);
        if (curr > maxi) {
            maxi = curr;
            aa = a;
            bb = a;
            cc = c;
        }
    }
    cout << aa << " " << bb << " " << cc << endl;
}
 
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
 
    for (ll n = 0; n < (1 << 17); n++) {
        if (cool(n) != brute(n)) {
            cout << "ERROR " << n << endl;
            return 0;
        }
        if (n % 1000 == 0)
            cout << n << endl;
    }
}