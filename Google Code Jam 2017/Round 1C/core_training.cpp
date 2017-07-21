#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct solver {
    void solve() {
        int n, k;
        cin >> n >> k;
        double u;
        cin >> u;
        vector<double> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];
        sort(vec.begin(), vec.end());
        vec.push_back(1.0);

        int cur = 1;
        while (true) {
            if (cur == n + 1)
                break;
            if (vec[cur] > vec[cur - 1]) {
                double diff = vec[cur] - vec[cur - 1];
                double cnt = cur;
                double add = min(diff, u / cnt);
                u -= add * cnt;
                for (int i = 0; i < cur; i++)
                    vec[i] += add;
                if (u <= 0.00000001)
                    break;
            } else {
                cur++;
            }
        }

        double ans = 1.0;
        for (auto it : vec)
            ans *= it;
        cout << fixed << setprecision(12) << ans << endl;
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
