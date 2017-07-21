#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

#ifdef USE_CERR
#define CERR(a) cerr << "dump: " << a << endl;
#else
#define CERR(a)
#endif

const int maxn = 4e3 + 5;
const int infi = 1e9 + 7;

int n;
int ans[maxn][maxn];
int ms[maxn];

int dp(int v, int sum) {
    if (sum < 0)
        sum = maxn - 1;
    if (v == n)
        return sum == (maxn - 1) ? 1 : 0;
    if (ans[v][sum] != -1)
        return ans[v][sum];
    if (sum != maxn - 1)
        ans[v][sum] = (dp(v + 1, sum) + dp(v + 1, sum - ms[v])) % infi;
    else
        ans[v][sum] = (dp(v + 1, sum) + dp(v + 1, sum)) % infi;
    return ans[v][sum];
}

int main() {
    #ifndef HOME
    #define FILE "polygon"
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
    #endif // HOME

    cin >> n;
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < n; i++)
        cin >> ms[i];
    sort(ms, ms + n);
    reverse(ms, ms + n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += dp(i + 1, ms[i]);
        sum %= infi;
    }
    cout << sum;
}