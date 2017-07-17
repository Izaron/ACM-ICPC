#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

struct path {
    int e, l, d;
    path() {

    }
    path(int e, int l, int d) {
        this->e = e;
        this->l = l;
        this->d = d;
    }
};

struct solver {
    int c;
    vector<vector<int>> from;
    vector<path> paths;
    int ans;

    int calc_time(int hour, int p) {
        int h = paths[p].l;
        if (hour <= h)
            return h - hour;
        else
            return 24 - hour + h;
    }

    void calc(int mask, int pos, int hour, int sum) {
        if (mask == (1 << (2 * c)) - 1) {
            if (pos == 0)
                ans = min(ans, sum);
            return;
        }

        for (int p = 2 * pos; p <= 2 * pos + 1; p++) {
            if ((mask & (1 << p)) != 0)
                continue;
            calc(mask | (1 << p), paths[p].e,
                (paths[p].l + paths[p].d) % 24, sum + calc_time(hour, p));
        }
    }

    void solve() {
        cin >> c;
        from.resize(c);
        paths.resize(2 * c);
        for (int i = 0; i < 2 * c; i++) {
            int f = i / 2;
            int e, l, d;
            cin >> e >> l >> d;
            e--;
            from[f].push_back(i);
            paths[i] = path(e, l, d);
        }

        ans = INT_MAX;
        calc(0, 0, 0, 0);
        for (auto p : paths)
            ans += p.d;
        cout << ans << endl;
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
