#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector<int> vint;

struct solver {
    int n;
    vint to;
    vector<vint> back;
    set<int> used;
    vector<bool> bused;

    void dfs(int v) {
        bused[v] = true;
        if (used.count(v))
            return;
        used.insert(v);
        for (auto it : back[v])
            dfs(it);
        dfs(to[v]);
    }

    int go_back(int v, int w) {
        if (back[v].empty())
            return 1;
        int r = 0;
        for (auto it : back[v])
            if (it != w)    
                r = max(r, go_back(it, w));
        return r + 1;
    }

    int calc(int st, int last, int v, int d) {
        if (to[v] == last)
            return d + go_back(v, last);
        if (st == v && d > 0)
            return -d;
        if (used.count(v))
            return 0;
        used.insert(v);
        return calc(st, v, to[v], d + 1);
    }

    void solve() {
        int n;
        cin >> n;
        to.resize(n);
        back.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> to[i];
            to[i]--;
            back[to[i]].push_back(i);
        }
        bused.resize(n);
        int ans = 0, g = 0;
        for (int i = 0; i < n; i++) {
            if (bused[i])
                continue;
            used.clear();
            dfs(i);
            int val = 0;
            vint vec;
            for (auto it : used)
                vec.push_back(it);
            for (auto it : vec) {
                used.clear();
                int cur = calc(it, it, it, 0);
                if (cur < 0)
                    g = max(g, -cur);
                val = max(val, cur);
            }
            ans += val;
        }
        cout << max(ans, g) << endl;
    }
};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": ";
        solver s;
        s.solve();
        cerr << "Case #" << i + 1 << " is done" << endl;
    }
}
