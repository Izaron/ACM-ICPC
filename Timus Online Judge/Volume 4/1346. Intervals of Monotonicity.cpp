// The solution of the problem was written by Izaron
// Date: 23:11:25   25 Jul 2017
// Execution time: 0.031

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

int a, b, n;
vector<int> vals;
vector<int> dp[2];
vector<int> ank;

void def() {
    dp[0].resize(n);    // increase
    dp[1].resize(n);    // decrease
    for (int i = n - 1; i >= 0; i--) {
        dp[0][i] = 1;
        dp[1][i] = 1;
        if (i + 1 < n && vals[i] <= vals[i + 1])
            dp[0][i] = 1 + dp[0][i + 1];
        if (i + 1 < n && vals[i] >= vals[i + 1])
            dp[1][i] = 1 + dp[1][i + 1];
    }
}

int calced[maxn];

int calc(int v) {
    if (v == n)
        return 0;
    if (calced[v] != -1)
        return calced[v];
    int res = INT_MAX / 2;
    res = min(res, 1 + calc(dp[0][v] + v));
    res = min(res, 1 + calc(dp[1][v] + v));
    calced[v] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;
    n = b - a + 1;

    vals.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vals[i];
    def();

    memset(calced, -1, sizeof(calced));

    cout << calc(0) << endl;
}
