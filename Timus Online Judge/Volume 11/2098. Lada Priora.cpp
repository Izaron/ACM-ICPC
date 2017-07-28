// The solution of the problem was written by Izaron
// Date: 15:38:22   25 Jul 2017
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pii;

ld b, c, d, p;
ll k;

ld cash() {
    ld ans = b + c * k + (ld)(k * (k + 1) / 2) * d;
    return ans;
}

ld insurance() {
    ld ans = (c * k + (ld)(k * (k + 1) / 2) * d) * (100.0 + p) / 100.0;
    return ans;
}

int main() {
    cin >> b >> c >> d >> k >> p;
    ld a = cash(), b = insurance();
    if (a < b) {
        cout << "Cash" << endl;
    } else {
        cout << "Insurance" << endl;
    }
    //cerr << a << endl << b << endl;
    cout << fixed << setprecision(12) << abs(a - b) << endl;
}
