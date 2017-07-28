// The solution of the problem was written by Izaron
// Date: 14:39:20   25 Jul 2017
// Execution time: 0.001

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;

int main() {
    ll l, t, a, b;
    cin >> l >> t >> a >> b;
    ll res = (a + b) * t;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll kek, shrek, illuminat;
        cin >> kek >> shrek >> illuminat;
        if (kek == 1)
            res -= illuminat * a;
        else
            res -= illuminat * b;
    }
    
    cout << res / l << endl;
}
