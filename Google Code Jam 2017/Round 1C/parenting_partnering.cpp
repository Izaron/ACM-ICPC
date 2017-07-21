#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 720 + 5;

struct solver {
    vector<int> daily;
    vector< vector<int> > calc[2][2];

    // a is Cameron's time
    // b is Jamie's time
    // cur is the current parent (0-1)
    // f is the first parent from midnight (0-1)
    int dp(int a, int b, int cur, int f) {
        if (min(a, b) < 0)
            return INT_MAX / 2;
        if (a + b == 0)
            return (cur == f ? 0 : INT_MAX / 2);

        if (daily[1440 - a - b] == 1 && cur != 0)
            return INT_MAX / 2;
        if (daily[1440 - a - b] == 2 && cur != 1)
            return INT_MAX / 2;

        if (calc[cur][f][a][b] != INT_MAX)
            return calc[cur][f][a][b];

        int& ret = calc[cur][f][a][b];
        ret = INT_MAX / 2;
        if (cur == 0) {
            ret = min(ret, dp(a - 1, b, 0, f) + 0); 
            ret = min(ret, dp(a - 1, b, 1, f) + 1); 
        } else {
            ret = min(ret, dp(a, b - 1, 0, f) + 1); 
            ret = min(ret, dp(a, b - 1, 1, f) + 0); 
        }
        return ret;
    }

    void solve() {
        for (int i = 0; i < 2; i++) {
            for (int z = 0; z < 2; z++) {
                calc[i][z].resize(maxn);
                for (int s = 0; s < maxn; s++)
                    calc[i][z][s].resize(maxn, INT_MAX);
            }
        }
        daily.resize(1440);
        int c, j;
        cin >> c >> j;
        for (int i = 0; i < c; i++) {
            int a, b;
            cin >> a >> b;
            for (int z = a; z < b; z++)
                daily[z] = 1;
        }
        for (int i = 0; i < j; i++) {
            int a, b;
            cin >> a >> b;
            for (int z = a; z < b; z++)
                daily[z] = 2;
        }

        int ret = INT_MAX / 2;
        ret = min(ret, dp(720, 720, 0, 0));
        ret = min(ret, dp(720, 720, 1, 1));
        cout << ret << endl;
    }
};

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cerr << "Case #" << i + 1 << " is being solved..." << endl;
        cout << "Case #" << i + 1 << ": ";
        solver s;
        s.solve();
    }
}
