// The solution of the problem was written by Izaron
// Date: 17:54:51   29 Jul 2017
// Execution time: 0.124

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <limits.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int dfs(vector<int>& to, vector<bool>& used, vector<int>& res, int v) {
    if (used[v] && res[v] == -1)
        return 1;
    if (used[v])
        return res[v];
    if (to[v] == -1) {
        used[v] = true;
        res[v] = 0;
        return 0;
    }
    used[v] = true;
    res[v] = dfs(to, used, res, to[v]);
    return res[v];
}

bool test() {
    int n;
    cin >> n;
    vector<int> to(n);
    vector<int> res(n, -1);
    vector<bool> used(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> to[i];
        to[i]--;
        if (to[i] == i)
            to[i] = -1;
        if (to[i] < 0) cnt++;
    }
    if (cnt > 1)
        return true;

    for (int i = 0; i < n; i++) {
        if (dfs(to, used, res, i) == 1) {
            //cerr << "i " << i << " cycle" << endl;
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cout << (test() ? "NO" : "YES") << endl;
    }
}
