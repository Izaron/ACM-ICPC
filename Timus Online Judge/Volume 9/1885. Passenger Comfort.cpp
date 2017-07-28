// The solution of the problem was written by Izaron
// Date: 15:28:56   25 Jul 2017
// Execution time: 0.001

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;

int main() {
    double h, t, v, x;
    cin >> h >> t >> v >> x;

    // minimal
    double min_time = (h - t * x) / (v - x);
    min_time = max(0.0, min_time);
    cout << fixed << setprecision(12) << min_time;

    // maximal
    double max_time = h / x;
    max_time = min(t, max_time);
    cout << " ";
    cout << fixed << setprecision(12) << max_time << endl;
}
