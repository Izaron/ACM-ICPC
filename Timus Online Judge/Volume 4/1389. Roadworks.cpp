// The solution of the problem was written by Izaron
// Date: 21:12:00   25 Jul 2017
// Execution time: 0.343

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

const int maxn = 1e5 + 5;

set<int> neig[maxn];
map<pii, pair< int, pii> > mp;
vector< pair< int, pii > > res;
int calc[2][maxn];
int n, m;

// a - number
// road - 0: can erase, 1: can't
int dp(int a, int road) {
    if (calc[road][a] != -1)
        return calc[road][a];
    int ans = 0;
    for (auto it : neig[a])
        ans += dp(it, 0);
    int rel = ans;
    if (road == 0) {
        for (auto it : neig[a]) {
            int tmp = ans;
            tmp -= dp(it, 0);
            tmp += dp(it, 1);
            tmp++;

            rel = max(rel, tmp);
        }
    }
    calc[road][a] = rel;
    return rel;
}

void vosst(int a, int road) {
    int ans = 0;
    for (auto it : neig[a])
        ans += dp(it, 0);

    if (ans == dp(a, road)) {
        for (auto it : neig[a])
            vosst(it, 0);
        return;
    }

    if (road == 0) {
        for (auto it : neig[a]) {
            int tmp = ans;
            tmp -= dp(it, 0);
            tmp += dp(it, 1);
            tmp++;

            if (tmp == dp(a, road)) {
                res.push_back(mp[{a, it}]);
                for (auto itt : neig[a]) {
                    if (itt == it)
                        continue;
                    vosst(itt, 0);
                }
                vosst(it, 1);
                return;
            }
        }
    }
}

void dfs(int v, int last) {
    if (neig[v].count(last))
        neig[v].erase(last);
    for (auto it : neig[v])
        dfs(it, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        mp[{ a, b }] = { i, { a + 1, b + 1 } };
        mp[{ b, a }] = { i, { a + 1, b + 1 } };
        neig[a].insert(b);
        neig[b].insert(a);
    }
    dfs(0, -1);

    memset(calc, -1, sizeof(calc));
    cout << dp(0, 0) << endl;
    vosst(0, 0);
    sort(res.begin(), res.end());
    for (auto it : res)
        cout << it.second.first << " " << it.second.second << endl;
    if (res.size() != dp(0, 0))
        throw 0;
}
