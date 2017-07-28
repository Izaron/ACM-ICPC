// The solution of the problem was written by Izaron
// Date: 15:42:46   26 Jul 2017
// Execution time: 0.093

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
typedef pair<ll, ll> pll;

const int maxn = 1e4 + 5;

int n, m;
vector<int> to[maxn];
vector<ll> to_add[maxn];
vector<int> to_type[maxn];
// 0 - pirated, 1 - cracked, 2 - licensed

ll calced[maxn][2];

ll dp(int v, int pirate) {
    if (v == n)
        return 0;
    ll& ans = calced[v][pirate];
    if (ans != -1)
        return ans;
    ans = LLONG_MAX / 2;
    for (int i = 0; i < to[v].size(); i++) {
        int next = to[v][i];
        int type = to_type[v][i];
        ll add = to_add[v][i];
        if (type == 2) {
            if (pirate == 1) {
                continue;
            } else {
                ans = min(ans, add + dp(next, 0));
            }
        } else if (type == 1) {
            ans = min(ans, add + dp(next, pirate));
        } else if (type == 0) {
            ans = min(ans, add + dp(next, 1));
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    memset(calced, -1, sizeof(calced));

    for (int i = 0; i < m; i++) {
        int x, y, d;
        string s;
        cin >> x >> y >> d >> s;
        to[x].push_back(y);
        to_add[x].push_back(d);
        if (s == "Pirated")
            to_type[x].push_back(0);
        else if (s == "Cracked")
            to_type[x].push_back(1);
        else
            to_type[x].push_back(2);
    }

    ll ans = dp(1, 0);
    if (ans >= LLONG_MAX / 2) {
        cout << "Offline" << endl;
    } else {
        cout << "Online" << endl << ans << endl;
    }
}
