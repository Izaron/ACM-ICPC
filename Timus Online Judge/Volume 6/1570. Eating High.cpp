// The solution of the problem was written by Izaron
// Date: 20:15:55   25 Jul 2017
// Execution time: 0.156

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
vector<string> names;
vector<ll> costs;
vector<double> syts;
vector<int> syts_i;
vector<int> ans;

pii calced[2][100][20 * 1000 + 5];

pii combine(pii a, pii b) {
    return { a.first + b.first, a.second + b.second };
}

pii dp(int v, int s, int rep) {
    rep = min(rep, 1);
    if (s <= 0)
        return { 0, 0 };
    if (v == n)
        return { INT_MAX / 2, 0 };
    if (calced[rep][v][s].first != -1)
        return calced[rep][v][s];

    pii& res = calced[rep][v][s];
    res = { INT_MAX / 2, 0 };
    res = min(res, combine(
        { costs[v], rep - 1 },
        dp(v, s - syts_i[v], rep + 1)
    ));
    res = min(res, dp(v + 1, s, 0));

    return res;
}

void vosst(int v, int s, int rep) {
    rep = min(rep, 1);
    if (s <= 0)
        return;
    if (v == n)
        return;

    if (dp(v, s, rep) == dp(v + 1, s, 0))
        vosst(v + 1, s, 0);
    else {
        ans[v]++;
        vosst(v, s - syts_i[v], rep + 1);
    }
}

int main() {
    cin >> n >> m;
    names.resize(n);
    costs.resize(n);
    syts.resize(n);
    syts_i.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i] >> costs[i] >> syts[i];
        syts_i[i] = (int)(syts[i] * 1000.0 + 0.1);
    }

    for (int i = 0; i < 2; i++) {
        for (int z = 0; z < 100; z++) {
            for (int s = 0; s < 20 * 1000 + 5; s++) {
                calced[i][z][s] = { -1, -1 };
            }
        }
    }

    pii res = dp(0, m * 1000, 0);
    cout << res.first << endl;
    vosst(0, m * 1000, 0);
    for (int i = 0; i < n; i++) {
        if (ans[i] > 0) {
            cout << names[i] << " " << ans[i] << endl;
        }
    }
}
