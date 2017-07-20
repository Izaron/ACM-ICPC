#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

struct solver {
    int n, c, m;
    vector<int> buyer;
    vector<int> pos;

    int calc(int rides) {
        int promoted = 0, cur_promoted = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (pos[i] + cur_promoted > rides)
                promoted += max(0, pos[i] - rides);
            cur_promoted = max(0, pos[i] + cur_promoted - rides);
        }

        return (cur_promoted == 0 ? promoted : -1);
    }

    void solve() {
        cin >> n >> c >> m;
        buyer.resize(c);
        pos.resize(n);
        for (int i = 0; i < m; i++) {
            int p, b;
            cin >> p >> b;
            b--; p--;
            buyer[b]++;
            pos[p]++;
        }

        int cnt = 0;
        for (auto it : buyer)
            cnt = max(cnt, it);

        int l = cnt, r = 3000000;
        while (l != r) {
            int la = l, lb = r;
            int mid = (l + r) / 2;
            if (calc(mid) >= 0)
                r = mid;
            else
                l = mid;
            if (la == l && lb == r) {
                if (calc(l) >= 0)
                    r = l;
                else
                    l = r;
            }
        }

        int ans = l;
        cout << ans << " " << calc(ans) << endl;
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
