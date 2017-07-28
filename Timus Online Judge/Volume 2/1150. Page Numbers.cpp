// The solution of the problem was written by Izaron
// Date: 17:30:01   25 Jul 2017
// Execution time: 0.001

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<int> vint;

string s;
vint some[10][2][2];

vint combine(vint a, vint b) {
    vint res(11);
    for (int i = 0; i < 11; i++)
        res[i] = a[i] + b[i];
    return res;
}

vint dp(int v, int zero, int skip) {
    if (v == s.size()) {
        vint res(11);
        res[10] = 1;
        return res;
    }
    if (some[v][zero][skip].size() > 0)
        return some[v][zero][skip];

    vint res(11);
    if (skip == 1) {
        for (int i = 0; i < 10; i++) {
            vint add = dp(v + 1, max(zero, min(i, 1)), 1);
            if (max(zero, min(i, 1)) != 0)
                res[i] += add[10];
            res = combine(res, add);
        }
    } else {
        for (int i = 0; i <= s[v] - '0'; i++) {
            vint add = dp(v + 1, max(zero, min(i, 1)), (i == (s[v] - '0') ? 0 : 1));
            if (max(zero, min(i, 1)) != 0)
                res[i] += add[10];
            res = combine(res, add);
        }
    }

    some[v][zero][skip] = res;
    return res;
}

int main() {
    cin >> s;
    vint res(11);
    //for (int i = 0; i <= s.size(); i++)
    //    res = combine(res, dp(i, (i == 0 ? 0 : 1), 0));
    res = dp(0, 0, 0);

    res.pop_back();
    for (auto it : res)
        cout << it << endl;
}
