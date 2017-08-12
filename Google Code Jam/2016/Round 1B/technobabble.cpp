#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef vector<int> vint;

struct solver {
    int solve(int n, vector<string> ass, vector<string> bss) {
        int ans = 0;
        set<pair<string, string>> st;
        map<string, int> as, bs;
        vector<string> va, vb;
        for (int i = 0; i < n; i++) {
            string a, b;
            a = ass[i];
            b = bss[i];
            if (st.count({a, b})) {
                ans++;
                continue;
            }
            st.insert({a, b});
            as[a]++; bs[b]++;
            va.push_back(a);
            vb.push_back(b);
        }
        vector<pair< pair<int, int>, int>> srt;
        for (int i = 0; i < va.size(); i++)
            srt.push_back({ {as[va[i]], bs[vb[i]]}, i});
        sort(srt.begin(), srt.end());
        set<string> aset, bset;
        for (auto it : srt) {
            int i = it.second;
            if (aset.count(va[i]) && bset.count(vb[i]))
                ans++;
            aset.insert(va[i]);
            bset.insert(vb[i]);
        }
        return ans;
    }
};

struct solver_stupid {
    int solve(int n, vector<string> as, vector<string> bs) {
        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            set<string> aset, bset;
            if (__builtin_popcount(mask) <= ans)
                continue;
            set<int> ost;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0) {
                    aset.insert(as[i]);
                    bset.insert(bs[i]);
                } else {
                    ost.insert(i);
                }
            }
            bool can = true;
            while (!ost.empty()) {
                int ind = -1;
                for (auto it : ost) {
                    if (aset.count(as[it]) && bset.count(bs[it])) {
                        ind = it;
                        break;
                    }
                }
                if (ind == -1) {
                    can = false;
                    break;
                }
                aset.insert(as[ind]);
                bset.insert(bs[ind]);
                ost.erase(ind);
            }
            if (can)
                ans = max(ans, __builtin_popcount(mask));
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": ";

        int n;
        cin >> n;
        vector<string> as(n), bs(n);
        for (int z = 0; z < n; z++)
            cin >> as[z] >> bs[z];

        solver s1;
        int r1 = s1.solve(n, as, bs);
        solver_stupid s2;
        int r2 = s2.solve(n, as, bs);

        cout << r2 << endl;
        if (r1 != r2) {
            cerr << "ERROR!" << endl;
            cerr << r1 << " is wrong" << endl;
            cerr << r2 << " is right" << endl;
            cerr << n << endl;
            for (int z = 0; z < n; z++)
                cerr << as[z] << " " << bs[z] << endl;
        }

        cerr << "Case #" << i + 1 << " is done" << endl;
    }
}
