// The solution of the problem was written by Izaron
// Date: 20:11:55   28 Jul 2017
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <vector>
#include <string.h>
#include <iostream>
#include <map>
#include <limits.h>
#include <set>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

ll get_del(ll a, ll v, ll num) {
    if (num < v)
        return 0;
    return num / v + get_del(a, v * a, num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> simple(n + 1);
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (simple[i] > 0) continue;
        for (int z = 2 * i; z <= n; z += i)
            simple[z] = 1;
        int a = get_del(i, i, n);
        int b = get_del(i, i, m) + get_del(i, i, n - m);
        if (a > b) ans++;
    }
    cout << ans << endl;
}
