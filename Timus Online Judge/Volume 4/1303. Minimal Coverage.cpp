// The solution of the problem was written by Izaron
// Date: 13:27:23   25 Jul 2017
// Execution time: 0.327

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;

int m;
vector<int> maxi;
vector<int> really;
vector<pii> vec;
vector<int> calc;

int dp(int v) {
    if (v == m)
        return 0;
    if (calc[v] != -1)
        return calc[v];
    int cur = INT_MAX / 2;
    for (int i = v + 1; i <= maxi[v]; i++)
        cur = min(cur, 1 + dp(i));
    calc[v] = cur;
    return cur;
}

void vosst(int v) {
    if (v == m)
        return;
    pii pr = vec[really[v]];
    cout << pr.first << " " << pr.second << endl;
    for (int i = v + 1; i <= maxi[v]; i++)
        if (1 + dp(i) == calc[v]) {
            vosst(i);
            return;
        }
}

int main() {
    cin >> m;
    int a, b;
    calc.resize(m, -1);
    maxi.resize(m);
    really.resize(m);
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        if (b <= 0 || a >= m)
            continue;
        vec.push_back({ a, b });
        b = min(b, m);
        a = max(a, 0);
        maxi[a] = max(maxi[a], b);
        if (maxi[a] == b)
            really[a] = vec.size() - 1;
    }
    int res = dp(0);
    if (res >= INT_MAX / 2) {
        cout << "No solution" << endl;
    } else {
        cout << res << endl;
        vosst(0);
    }
}
