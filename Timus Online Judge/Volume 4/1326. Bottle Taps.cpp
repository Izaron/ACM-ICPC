// The solution of the problem was written by Izaron
// Date: 18:13:32   27 Jul 2017
// Execution time: 0.998

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

const int maxv = 20;
const int maxn = (1 << maxv);

int n, m;
vector<int> sub;
vector<int> add_masks;
vector<int> add_costs;
int target;
int calced[maxn];

int dp(int mask) {
    if ((mask | target) == mask)
        return 0;
    int& ans = calced[mask];
    if (ans != -1)
        return ans;
    ans = INT_MAX / 2;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) != 0)
            continue;
        ans = min(ans, dp(mask | (1 << i)) + sub[i]);
    }
    for (int i = 0; i < m; i++) {
        if ((mask | add_masks[i]) == mask)
            continue;
        ans = min(ans, dp(mask | add_masks[i]) + add_costs[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    sub.resize(n);
    for (int i = 0; i < n; i++)
        cin >> sub[i];

    cin >> m;
    add_masks.resize(m);
    add_costs.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> add_costs[i];
        int k;
        cin >> k;
        int mask = 0;
        for (int z = 0; z < k; z++) {
            int tmp;
            cin >> tmp;
            mask |= (1 << (tmp - 1));
        }
        add_masks[i] = mask;
    }

    int k;
    cin >> k;
    for (int z = 0; z < k; z++) {
        int tmp;
        cin >> tmp;
        target |= (1 << (tmp - 1));
    }

    memset(calced, -1, sizeof(calced));
    cout << dp(0) << endl;
}
