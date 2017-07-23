// The solution of the problem was written by Izaron
// Date: 23:15:39   22 Jan 2017
// Execution time: 0.265

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

const int maxn = 5e5 + 5;
const int maxp = 20;

int n;
vector<int> vec;

int gv(int a, int b) {
    int ret = vec[b];
    if (a > 0)
        ret -= vec[a - 1];
    return ret;
}

int dp(int l, int r, int p) {
    int sum = gv(l, r);
    int len = r - l + 1;
    if (sum == 0)
        return 0;   // ALISE
    else if (sum == len)
        return 2;   // BOB
    if (len % 4 != 0)
        return 1;

    int a = dp(l, l + len / 2 - 1, 1 - p);
    int b = dp(r - len / 2 + 1, r, 1 - p);
    if (p == 0)
        return min(a, b);
    else
        return max(a, b);
}

int main() {
    cin >> n;
    string a, b;
    cin >> a >> b;
    vec.resize(2 * n);
    for (int i = 0; i < n; i++)
        vec[i] = a[i] - 'A';
    for (int i = n; i < 2 * n; i++)
        vec[i] = b[i - n] - 'A';
    for (int i = 1; i < 2 * n; i++)
        vec[i] += vec[i - 1];
    int res = dp(0, 2 * n - 1, 0);
    vector<string> ot = { "Alice", "Draw", "Bob" };
    cout << ot[res];
}
