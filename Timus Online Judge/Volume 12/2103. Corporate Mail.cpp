// The solution of the problem was written by Izaron
// Date: 01:58:02   28 Jul 2017
// Execution time: 0.046

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <limits.h>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

void gen(vector<pii>& vec, vector<int>& res, int v, int cur) {
    if (v == vec.size()) {
        res.push_back(cur);
        return;
    }
    gen(vec, res, v + 1, cur);
    pii pr = vec[v];
    for (int i = 0; i < pr.second; i++) {
        cur *= pr.first;
        gen(vec, res, v + 1, cur);
    }
}

vector<int> primer(int v) {
    vector<pii> vec;
    for (int i = 2; i <= sqrt(v); i++) {
        if (v % i == 0) {
            int cnt = 0;
            while (v % i == 0) {
                cnt++;
                v /= i;
            }
            vec.push_back({ i, cnt });
        }
    }
    if (v > 1)
        vec.push_back({ v, 1 });
    vector<int> res;
    gen(vec, res, 0, 1);
    return res;
}

const int maxn = 1e5 + 5;

int s, t;
vector<int> vec;
vector<pii> neig[maxn];

void calc_graph(set<int> st) {
    for (auto it : st)
        vec.push_back(it);

    for (int i = 0; i < vec.size(); i++) {
        for (int z = i + 1; z < vec.size(); z++) {
            if (vec[z] % vec[i] == 0) {
                neig[i].push_back({0, z});
            }
            if (vec[z] - 1 == vec[i]) {
                neig[z].push_back({1, i});
                if (vec[z] % vec[i] != 0)
                    neig[i].push_back({1, z});
            }
        }
    }

    for (int i = 0; i < maxn; i++) {
        if (!neig[i].empty()) {
            sort(neig[i].begin(), neig[i].end());
            //for (auto it : neig[i]) {
            //    cerr << "Edge " << vec[i] << " " << vec[it.second] << " cost " << it.first << endl;
            //}
        }
    }
}

vector<int> vert[100];
vector<int> last_vec[100];
vector<int> last_pos[100];

void calc_ans() {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == s) {
            s = i;
            break;
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == t) {
            t = i;
            break;
        }
    }

    vector<bool> used(vec.size());
    vert[0].push_back(s);
    last_vec[0].push_back(-1);
    last_pos[0].push_back(-1);

    for (int z = 0; z < 100; z++) {
        for (int i = 0; i < vert[z].size(); i++) {
            int v = vert[z][i];
            //cerr << "Found " << vec[v] << " cost " << z << endl;
            if (used[v]) continue;
            used[v] = true;

            if (v == t) {   // found answer!
                vector<int> res;
                int a = z, b = i;
                while (true) {
                    res.push_back(vert[a][b]);
                    int na = last_vec[a][b];
                    int nb = last_pos[a][b];
                    a = na; b = nb;
                    if (a == -1) break;
                }
                reverse(res.begin(), res.end());
                cout << z << endl;
                cout << res.size() << endl;
                for (auto it : res)
                    cout << vec[it] << " ";
                cout << endl;
                return;
            }

            for (auto it : neig[v]) {
                if (used[it.second]) continue;
                vert[z + it.first].push_back(it.second);
                last_vec[z + it.first].push_back(z);
                last_pos[z + it.first].push_back(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> t;

    set<int> st;
    for (int i = 1; i < 15; i++)
        st.insert(i);
    vector<int> v = primer(t);
    for (auto it : v) {
        //cerr << "Primer " << it << endl;
        for (int i = max(1, it - 2); i <= it + 2; i++)
            st.insert(i);
    }

    calc_graph(st);
    calc_ans();
}
