#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

struct solver {
    int f, p;
    vector<int> in_count, out_count;
    vector<pii> pairs;
    vector<int> ans;

    vector< set<pii> > to;
    vector< set<pii> > back;

    vector<bool> good;

    vector<int> find_cycle(int v, bool straight) {
        // shall go to pairs[v].first
        vector<int> bfs = { pairs[v].second };
        vector<int> path = { v + 1 };
        vector<int> from = { -1 };
        vector<bool> used(f);
        used[pairs[v].second] = true;

        for (int i = 0; i < bfs.size(); i++) {
            int cur = bfs[i];
            if (cur == pairs[v].first) {
                vector<int> ans;
                int index = i;
                while (index >= 0) {
                    ans.push_back(path[index]);
                    index = from[index];
                }
                reverse(ans.begin(), ans.end());
                return ans;
            }
            for (auto it : to[cur]) {
                int vert = it.first, num = it.second;
                if (used[vert])
                    continue;
                used[vert] = true;
                bfs.push_back(vert);
                path.push_back(num + 1);
                from.push_back(i);
            }

            if (straight) {
                for (auto it : back[cur]) {
                    int vert = it.first, num = it.second;
                    if (good[num])
                        continue;
                    if (used[vert])
                        continue;
                    used[vert] = true;
                    bfs.push_back(vert);
                    path.push_back(-num - 1);
                    from.push_back(i);
                }
            }
        }

        return vector<int>(0);
    }

    void swapp(int v) {
        int a = pairs[v].first, b = pairs[v].second;
        to[a].erase({ b, v });
        back[b].erase({ a, v });
        
        swap(a, b);
        swap(pairs[v].first, pairs[v].second);
        to[a].insert({ b, v });
        back[b].insert({ a, v });
    }

    vector<int> solve() {
        cin >> f >> p;
        in_count.resize(f);
        out_count.resize(f);
        pairs.resize(p);
        ans.resize(p);

        to.resize(f);
        back.resize(f);

        for (int i = 0; i < p; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            pairs[i].first = a; pairs[i].second = b;
            to[a].insert({ b, i });
            back[b].insert({ a, i });
        }

        #ifdef CERR
        for (int i = 0; i < p; i++) {
           cerr << "pair " << pairs[i].first << " " << pairs[i].second << endl;
        }
        #endif
        
        good.resize(p);

        vector<int> swapped(p, 1);

        for (int i = 0; i < p; i++) {
            vector<int> cycle = find_cycle(i, false);
            good[i] = !cycle.empty();

            #ifdef CERR
            cerr << "cycle for " << i << ": ";
            for (auto it : cycle)
                cerr << it << " ";
            cerr << endl;
            #endif

            for (auto it : cycle) {
                if (it < 0)
                    ans[-it - 1] -= swapped[-it-1];
                else
                    ans[it - 1] += swapped[it-1];
            }
        }

        #ifdef CERR
        cerr << "goods: ";
        for (auto it : good)
            cerr << (it ? 1 : 0) << " ";
        cerr << endl;
        #endif

        for (int i = 0; i < p; i++) {
            if (good[i])
                continue;

            good[i] = true;

            vector<int> cycle = find_cycle(i, true);
            if (cycle.empty()) {
                swapp(i);
                cycle = find_cycle(i, true);
            }
            if (cycle.empty())
                return vector<int>(0);

            for (auto it : cycle) {
                if (it < 0)
                    ans[-it - 1] -= swapped[-it-1];
                else
                    ans[it - 1] += swapped[it-1];
            }

            for (auto it : cycle) {
                if (it < 0) {
                    swapp(-it-1);
                    swapped[-it-1] *= -1;
                    good[-it-1] = true;
                } else {
                    good[it-1] = true;
                }
            }

            #ifdef CERR
            cerr << "bad cycle for " << i << ": ";
            for (auto it : cycle)
                cerr << it << " ";
            cerr << endl;
            #endif
        }

        #ifdef CERR
        cerr << "ANS: ";
        for (auto it : ans)
            cerr << it << " ";
        cerr << endl;
        #endif

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cerr << "Case #" << i + 1 << " is being solved..." << endl;
        cout << "Case #" << i + 1 << ": ";
        solver s;
        vector<int> ans = s.solve();
        if (ans.size() == 0)
            cout << "IMPOSSIBLE" << endl;
        else {
            for (auto it : ans)
                cout << it << " ";
            cout << endl;
        }
    }
}
