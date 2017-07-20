#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

struct solver {
    int n, m;
    vector< vector<int> > pies;
    int calced[305][305];

    int calc(int v, int p) {
        if (p < 0)
            return INT_MAX / 2;
        if (p > n)
            return INT_MAX / 2;
        if (v == n)
            return 0;
        if (calced[v][p] != -1)
            return calced[v][p];
        int& ans = calced[v][p];
        ans = calc(v + 1, p - 1);
        int add = 0;
        for (int i = 0; i < m; i++) {
            add += pies[v][i];
            ans = min(ans, add + (i + 1) * (i + 1) + calc(v + 1, p + i));
        }
        return ans;
    }

    void solve() {
        cin >> n >> m;
        pies.resize(n);
        for (int i = 0; i < n; i++) {
            pies[i].resize(m);
            for (int z = 0; z < m; z++)
                cin >> pies[i][z];
            sort(pies[i].begin(), pies[i].end());
        }
        memset(calced, -1, sizeof(calced));
        cout << calc(0, 0) << endl;
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
 
