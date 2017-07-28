// The solution of the problem was written by Izaron
// Date: 19:09:48   27 Jul 2017
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

const int maxn = 100 + 5;

string s;
int n;

int calced[maxn][maxn];
int folds[maxn][maxn];

int gnum(int v) {
    if (v < 10)
        return 1;
    if (v < 100)
        return 2;
    return 3;
}

int dp(int a, int b) {
    if (a == b)
        return 1;
    int& ans = calced[a][b];
    if (ans != -1)
        return ans;

    ans = INT_MAX / 2;
    ans = min(ans, 1 + dp(a + 1, b));
    ans = min(ans, 1 + dp(a, b - 1));

    for (int i = a; i < b; i++)
        ans = min(ans, dp(a, i) + dp(i + 1, b));

    if (folds[a][b] > 1)
        ans = min(ans, gnum(folds[a][b]) + 1 + dp(a, a + (b - a + 1) / folds[a][b] - 1) + 1);

    //cerr << a << " " << b << " ans is " << ans << endl;
    return ans;
}

void vosst(int a, int b) {
    if (a == b) {
        cout << s[a];
        return;
    }

    int ans = calced[a][b];
    if (ans == 1 + dp(a + 1, b)) {
        cout << s[a];
        vosst(a + 1, b);
        return;
    }
    if (ans == 1 + dp(a, b - 1)) {
        vosst(a, b - 1);
        cout << s[b];
        return;
    }

    for (int i = a; i < b; i++) {
        if (ans == dp(a, i) + dp(i + 1, b)) {
            vosst(a, i);
            vosst(i + 1, b);
            return;
        }
    }

    if (folds[a][b] > 1) {
        if (ans == gnum(folds[a][b]) + 1 + dp(a, a + (b - a + 1) / folds[a][b] - 1) + 1) {
            cout << folds[a][b] << "(";
            vosst(a, a + (b - a + 1) / folds[a][b] - 1);
            cout << ")";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    n = s.size();

    memset(calced, -1, sizeof(calced));
    memset(folds, 0, sizeof(folds));

    for (int i = 0; i < n; i++) {
        for (int z = i; z < n; z++) {
            int len = z - i + 1;
            int sub = len;
            folds[i][z] = max(folds[i][z], 1);
            for (int r = z + 1; r < n; r++) {
                if (s[r] == s[i + (r - i) % len]) {
                    sub++;
                    if (sub % len == 0)
                        folds[i][r] = max(folds[i][r], sub / len);
                } else {
                    break;
                }
            }
        }
    }

    // cerr folds
    /*
    for (int i = 0; i < n; i++) {
        for (int z = i; z < n; z++) {
            for (int r = i; r <= z; r++)
                cerr << s[r];
            cerr << ": " << folds[i][z] << endl;
        }
    }
    */

    dp(0, n - 1);
    vosst(0, n - 1);
    cout << endl;
}
