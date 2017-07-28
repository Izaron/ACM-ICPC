// The solution of the problem was written by Izaron
// Date: 14:29:55   25 Jul 2017
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;

const int maxn = 256;

int aa, bb, cc;
bool used[maxn][maxn][maxn];
bool can[maxn + maxn + maxn];

void dp(int a, int b, int c) {
    if (used[a][b][c])
        return;
    used[a][b][c] = true;

    //cerr << "looking at " << a << " " << b << " " << c << endl;

    can[a] = true;
    can[b] = true;
    can[c] = true;
    can[a + b] = true;
    can[a + c] = true;
    can[b + c] = true;
    can[a + b + c] = true;

    // add
    dp(aa, b, c);
    dp(a, bb, c);
    dp(a, b, cc);

    // remove
    //dp(0, b, c);
    //dp(a, 0, c);
    //dp(a, b, 0);

    // a -> b
    if (a + b <= bb)
        dp(0, a + b, c);
    else
        dp(a - (bb - b), bb, c);

    // a -> c
    if (a + c <= cc)
        dp(0, b, a + c);
    else
        dp(a - (cc - c), b, cc);

    // b -> c
    if (b + c <= cc)
        dp(a, 0, b + c);
    else
        dp(a, b - (cc - c), cc);


    // b -> a
    if (a + b <= aa)
        dp(a + b, 0, c);
    else
        dp(aa, b - (aa - a), c);

    // c -> a
    if (a + c <= aa)
        dp(a + c, b, 0);
    else
        dp(aa, b, c - (aa - a));

    // c -> b
    if (b + c <= bb)
        dp(a, b + c, 0);
    else
        dp(a, bb, c - (bb - b));
}

int main() {
    cin >> aa >> bb >> cc;
    memset(used, false, sizeof(used));
    memset(can, false, sizeof(can));
    dp(0, 0, 0);
    int cnt = 0;
    for (int i = 1; i < 3 * maxn; i++) {
        if (can[i]) {
            cnt++;
            //cerr << i << endl;
        }
    }
    cout << cnt << endl;
}
