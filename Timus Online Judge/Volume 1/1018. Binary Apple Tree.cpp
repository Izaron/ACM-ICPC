// The solution of the problem was written by Izaron
// Date: 16:15:00   26 Jul 2017
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
typedef pair<ll, ll> pll;

const int maxn = 100 + 5;

int n;
set<pii> neig[maxn];
vector<int> sub_size;
vector<int> from_par;

int calc[maxn][maxn];

int dp(int v, int del) {
    if (sub_size[v] == del)
        return 0;
    if (sub_size[v] < del)
        return INT_MIN / 3;
    if (sub_size[v] == 1 && del == 0)
        return from_par[v];

    int& ans = calc[v][del];
    if (ans != -1)
        return ans;
    ans = INT_MIN / 3;

    if (neig[v].size() == 1) {
        int a = (*neig[v].begin()).first;
        ans = max(ans, dp(a, del) + from_par[v]);
    } else if (neig[v].size() == 2) {
        int a = (*neig[v].begin()).first;
        int b = (*neig[v].rbegin()).first;
        for (int i = 0; i <= del; i++)
            ans = max(ans, dp(a, i) + dp(b, del - i) + from_par[v]);
    }

    return ans;
}

int dfs(int v, int last) {
    //cerr << v << " is" << endl;
    if (last != -1) {
        //cerr << v << " " << last << " go" << endl;
        pii res;
        for (auto it : neig[v]) {
            if (it.first == last) {
                res = it;
                //cerr << v << " da" << endl;
                break;
            }
        }
        from_par[v] = res.second;
        neig[v].erase(res);
    }

    int sz = 1;

    for (auto it : neig[v]) {
        //cerr << "from " << v + 1 << " to " << it.first + 1 << endl;
        sz += dfs(it.first, v);
    }

    sub_size[v] = sz;
    return sz;
}

int main() {
    cin >> n;
    int q;
    cin >> q;

    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        neig[a].insert({ b, c });
        neig[b].insert({ a, c });
    }
    from_par.resize(n);
    sub_size.resize(n);

    memset(calc, -1, sizeof(calc));
    dfs(0, -1);

    //for (int i = 0; i < n; i++)
    //    cerr << "sub " << i << ": " << sub_size[i] << endl;

    int res = dp(0, n - 1 - q);
    cout << res << endl;
}
