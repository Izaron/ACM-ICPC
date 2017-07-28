// The solution of the problem was written by Izaron
// Date: 23:48:48   24 Jul 2017
// Execution time: 0.093

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 2000 + 5;
const int inf = 1e9 + 7;

string as, bs;
pii res[maxn][maxn];

pii combine(pii a, pii b) {
    return { a.first + b.first, (a.second + b.second) % inf };
}

// (len, cnt)
pii dp(int a, int b) {
    if (a == as.size() && b == bs.size())
        return { 0, 1 };
    if (res[a][b].first != -1)
        return res[a][b];
    pii& ans = res[a][b];
    if (a < as.size() && b < bs.size() && as[a] == bs[b]) {
        ans = combine(
            { 1, 0 },
            dp(a + 1, b + 1)
        );
    } else {
        pii aa = { INT_MAX / 2, 0 };
        pii bb = { INT_MAX / 2, 0 };
        if (a < as.size()) aa = dp(a + 1, b);
        if (b < bs.size()) bb = dp(a, b + 1);
        if (aa.first < bb.first) {
            ans = combine(
                { 1, 0 },
                aa
            );
        } else if (bb.first < aa.first) {
            ans = combine(
                { 1, 0 },
                bb
            );
        } else {
            ans = aa;
            ans.first++;
            ans.second += bb.second;
            ans.second %= inf;
        }
    }
    return ans;
}

int main() {
    cin >> as >> bs;
    for (int i = 0; i < maxn; i++)
    for (int z = 0; z < maxn; z++)
        res[i][z] = { -1, -1 };
    cout << dp(0, 0).second << endl;
}
