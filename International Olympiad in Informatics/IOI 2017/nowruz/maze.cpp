#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vint;

double total = 0.0;
vector<double> best;

struct solver {
    int test;
    int n, m, k;
    vector<string> vec;
    vint ma = { 1, 0, -1, 0 };
    vint mb = { 0, 1, 0, -1 };
    int ans = 0;
    vector< vector<bool> > used;

    bool is_free(int a, int b) {
        if (a < 0 || b < 0 || a >= n || b >= m)
            return false;
        return vec[a][b] == '.';
    }

    bool is_wall(int a, int b) {
        if (a < 0 || b < 0 || a >= n || b >= m)
            return false;
        return vec[a][b] == '#';
    }

    bool is_bush(int a, int b) {
        if (a < 0 || b < 0 || a >= n || b >= m)
            return false;
        return vec[a][b] == 'X';
    }

    bool possible(int a, int b) {
        if (a < 0 || b < 0 || a >= n || b >= m)
            return false;
        if (!is_bush(a, b))
            return false;
        return true;
    }

    int dfs(int a, int b, int la, int lb) {
        if (a < 0 || b < 0 || a >= n || b >= m)
            return 0;
        int ans = 0, cnt = 0;
        for (int i = 0; i < 4; i++) {
            int na = a + ma[i], nb = b + mb[i];
            if (na < 0 || nb < 0 || na >= n || nb >= m)
                continue;
            if (!is_free(na, nb))
                continue;
            cnt++;
            if (na != la || nb != lb)
                ans += dfs(na, nb, a, b);
        }
        if (cnt <= 1)
            ans++;
        return ans;
    }

    int bfs(vector<pii>& pos, int a, int b) {
        vector<pii> prev;
        pos.push_back({a, b});
        prev.push_back({a, b});
        for (int z = 0; z < pos.size(); z++) {
            int a = pos[z].first, b = pos[z].second;
            int la = prev[z].first, lb = prev[z].second;
            //if (a == n - 1 && b == 0) continue;
            //if (a == 0 && b == m - 1) continue;
            if (a < 0 || b < 0 || a >= n || b >= m)
                continue;
            if (!is_bush(a, b))
                continue;
            bool fre = true;
            for (int i = 0; i < 4; i++) {
                int na = a + ma[i], nb = b + mb[i];
                if (is_free(na, nb) && (na != la || nb != lb)) {
                    fre = false;
                    break;
                }
            }
            if (!fre)
                continue;

            vec[a][b] = '.';

            vector<int> to = { 0, 1, 2, 3 };
            random_shuffle(to.begin(), to.end());
            for (int i = 0; i < 4; i++) {
                int na = a + ma[to[i]], nb = b + mb[to[i]];
                if (possible(na, nb)) {
                    pos.push_back({na, nb});
                    prev.push_back({a, b});
                }
            }
        }
        return dfs(a, b, a, b);
    }

    void print_points() {
        double a = min(ans, k), b = k;
        double res = (a / b * 10.0);
        res *= 100;
        int lol = res;
        res = (double)(lol) / 100.0;

        total += res;
        cout << fixed << setprecision(2) << res << " ";
        cout << fixed << setprecision(2) << total << endl;

        if (res > best[test]) {
            cout << "BETTER ANSWER! Was " << best[test] << " now " << res << endl;
            best[test] = res;

            string file_out;
            if (test < 10) {
                file_out = "max/0" + to_string(test) + ".out";
            } else {
                file_out = "max/" + to_string(test) + ".out";
            }

            ofstream fout(file_out);
            for (int i = 0; i < n; i++)
                fout << vec[i] << endl;
            fout.close();
        }
    }

    void solve(int t) {
        test = t;
        cout << "Test " << t << endl;

        string file_in, file_out;
        if (t < 10) {
            file_in = "0" + to_string(t) + ".in";
            file_out = "0" + to_string(t) + ".out";
        } else {
            file_in = to_string(t) + ".in";
            file_out = to_string(t) + ".out";
        }

        ifstream fin(file_in);
        ofstream fout(file_out);

        fin >> n >> m >> k;
        vec.resize(n);
        for (int i = 0; i < n; i++)
            fin >> vec[i];

        used.resize(n);
        for (int i = 0; i < n; i++)
            used[i].resize(m);

        vector<pii> pos;
        for (int i = 0; i < n; i++) {
            for (int z = 0; z < m; z++) {
                if (vec[i][z] == '.') {
                    pos.push_back({i, z});
                    vec[i][z] = 'X';
                }
            }
        }

        random_shuffle(pos.begin(), pos.end());

        int res;
        ans = 0;
        int ind = 0;
        vector< vector<pii> > curs;
        for (auto it : pos) {
            int aa = it.first;
            int bb = it.second;
            if (!is_bush(aa, bb))
                continue;
            bool can = true;
            for (int i = 0; i < 4; i++) {
                int na = aa + ma[i], nb = bb + mb[i];
                if (na < 0 || nb < 0 || na >= n || nb >= m)
                    continue;
                if (is_free(na, nb)) {
                    can = false;
                    break;
                }
            }
            if (!can)
                continue;
            vector<pii> cur;
            res = bfs(cur, aa, bb);
            curs.push_back(cur);
            if (ans < res) {
                ind = curs.size() - 1;
                ans = res;
            }
        }

        for (int i = 0; i < curs.size(); i++) {
            if (i == ind)
                continue;
            for (auto it : curs[i])
                vec[it.first][it.second] = 'X';
        }

        //for (int i = 0; i < n; i++)
        //    fout << vec[i] << endl;
        print_points();

        fin.close();
        fout.close();
    }
};

int main() {
    ifstream fbest("best");
    best.resize(11);
    for (int i = 1; i <= 10; i++)
        fbest >> best[i];
    fbest.close();

    srand(time(0));

    ifstream fin("in");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        fin >> t;
        solver s;
        s.solve(t);
    }
    fin.close();

    double sum = 0;
    ofstream obest("best");
    for (int i = 1; i <= 10; i++) {
        obest << best[i] << endl;
        sum += best[i];
    }
    obest << endl << "Sum is " << sum << endl;
    obest.close();
}
