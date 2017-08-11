#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

const int maxn = 100 + 5;

struct solver {
    int n, p;
    vector<int> vec;
    vector<int> cnt;
    vector< vector< vector<int> > > calced[4];

    int gost(int v) {
        v %= p;
        v += p;
        v %= p;
        return v;
    }

    int calc(int ost, int a, int b, int c) {
        if (a + b + c == 0)
            return 0;
        if (calced[ost][a][b][c] != -1)
            return calced[ost][a][b][c];
        
        int & ans = calced[ost][a][b][c];
        ans = 0;

        if (a > 0)
            ans = max(ans, calc(gost(ost - 1), a - 1, b, c) + (ost == 0 ? 1 : 0));
        if (b > 0)
            ans = max(ans, calc(gost(ost - 2), a, b - 1, c) + (ost == 0 ? 1 : 0));
        if (c > 0)
            ans = max(ans, calc(gost(ost - 3), a, b, c - 1) + (ost == 0 ? 1 : 0));

        return ans;
    }

    void fill_zeroes() {
        for (int i = 0; i < 4; i++) {
            for (int z = 0; z < maxn; z++) {
                for (int s = 0; s < maxn; s++) {
                    fill(calced[i][z][s].begin(),
                        calced[i][z][s].end(), -1);
                }
            }
        }
    }

    void init() {
        cnt.resize(4);
        for (int i = 0; i < 4; i++) {
            calced[i].resize(maxn);
            for (int z = 0; z < maxn; z++) {
                calced[i][z].resize(maxn);
                for (int s = 0; s < maxn; s++) {
                    calced[i][z][s].resize(maxn);
                }
            }
        }
    }

    void solve() {
        cin >> n >> p;
        vec.resize(p);

        fill(cnt.begin(), cnt.end(), 0);
        fill_zeroes();

        for (int i = 0; i < n; i++) {
            cin >> vec[i];
            cnt[vec[i] % p]++;
        }

        cout << calc(0, cnt[1], cnt[2], cnt[3]) + cnt[0] << endl;
    }
} s;

int main() {
    s.init();

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cerr << "Case #" << i + 1 << " is being solved..." << endl;
        cout << "Case #" << i + 1 << ": ";
        s.solve();
    }
}
