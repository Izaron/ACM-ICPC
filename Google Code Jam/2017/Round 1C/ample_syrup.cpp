#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct solver {
    int n, k;
    vector<pll> vec;
    vector< vector<ll> > res;

    ll solve(int a, int b) {
        if (a == n) {
            return (b == 0 ? 0 : LLONG_MIN / 2);
        }
        if (res[a][b] != -1)
            return res[a][b];
        ll& cur = res[a][b];
        cur = solve(a + 1, b);
        if (b > 0)
            cur = max(cur, solve(a + 1, b - 1) + 2 * vec[a].first * vec[a].second);
        return cur;
    }

    void solve() {
        cin >> n >> k;
        vec.resize(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i].first >> vec[i].second;
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        res.resize(n);
        for (int i = 0; i < n; i++)
            res[i].resize(k, -1);
        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, solve(i + 1, k - 1) + vec[i].first * vec[i].first
                + 2 * vec[i].first * vec[i].second);

        long double ld = ans;
        ld *= (long double)(3.141592653589793238462);
        cout << fixed << setprecision(12) << ld << endl;
    }
} s;

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
