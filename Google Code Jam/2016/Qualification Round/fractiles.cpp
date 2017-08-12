#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <limits.h>
using namespace std;

void solve() {
    int k, c, s;
    cin >> k >> c >> s;
    if (k != s) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (int i = 1; i <= s; i++)
        cout << i << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
