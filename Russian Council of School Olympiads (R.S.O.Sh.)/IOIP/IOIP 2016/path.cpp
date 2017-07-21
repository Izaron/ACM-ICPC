#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

#ifdef USE_CERR
#define CERR(a) cerr << "dump: " << a << endl;
#else
#define CERR(a)
#endif

int main() {
    #ifndef HOME
    #define FILE "path"
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
    #endif // HOME

    ll n, m;
    cin >> n >> m;

    ll x, y;
    cin >> x >> y;

    ll len = x;
    len = min(len, y);
    len = min(len, n - x + 1);
    len = min(len, m - y + 1);

    ll ans = (2 * len - 1) * (2 * len - 1);

    // right
    if (x + len <= n) {
        ans += 2 * len - 1;
        // down
        if (y - len > 0) {
            ans += 2 * len;
            // left
            if (x - len > 0) {
                ans += 2 * len;
                if (y + len <= m) {
                    ans += 2 * len;

                }
            }
        }
    }

    cout << ans;
}