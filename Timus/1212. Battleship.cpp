// The solution of the problem was written by Izaron
// Date: 17:46:32   25 May 2016
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <vector>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tt;

const int N = 100000 + 5;


int n, m, l;
vector<pii> vecV[N];
vector<pii> vecH[N];

int main() {
    cin >> n >> m >> l;
    for (int i = 0; i < l; i++) {
        int x, y, len;
        string s;
        cin >> x >> y >> len >> s;
        x--;
        y--;

        if (s == "V") {
            for (int z = y - 1; z <= y + len; z++) {
                if (z < 0) continue;
                vecH[z].pb(mkp(x - 1, x + 1));
            }
            for (int z = x - 1; z <= x + 1; z++) {
                if (z < 0) continue;
                vecV[z].pb(mkp(y - 1, y + len));
            }
        } else {
            for (int z = y - 1; z <= y + 1; z++) {
                if (z < 0) continue;
                vecH[z].pb(mkp(x - 1, x + len));
            }
            for (int z = x - 1; z <= x + len; z++) {
                if (z < 0) continue;
                vecV[z].pb(mkp(y - 1, y + 1));
            }
        }
    }

    int k;
    cin >> k;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (vecH[i].size() == 0) {
            ans += max(0, m - k + 1);
        } else {
            sort(vecH[i].begin(), vecH[i].end());
            vector<pii> vec;
            int lef = -100, rig = -100;
            for (auto it : vecH[i]) {
                if (rig >= it.first - 1) {
                    rig = it.second;
                } else {
                    if (rig != -100)
                        vec.pb(mkp(lef, rig));
                    lef = it.first;
                    rig = it.second;
                }
            }
            if (rig != -100)
                vec.pb(mkp(lef, rig));
            vecH[i].clear();
            for (auto it : vec)
                vecH[i].pb(it);

            int l = 0;
            for (auto it : vecH[i]) {
                ans += max(0, (it.first - l) - k + 1);
                l = it.second + 1;
            }
            ans += max(0, (m - l) - k + 1);
        }
    }

    if (k != 1) {
        for (int i = 0; i < m; i++) {
            if (vecV[i].size() == 0) {
                ans += max(0, n - k + 1);
            } else {
                sort(vecV[i].begin(), vecV[i].end());
                vector<pii> vec;
                int lef = -100, rig = -100;
                for (auto it : vecV[i]) {
                    if (rig >= it.first - 1) {
                        rig = it.second;
                    } else {
                        if (rig != -100)
                            vec.pb(mkp(lef, rig));
                        lef = it.first;
                        rig = it.second;
                    }
                }
                if (rig != -100)
                    vec.pb(mkp(lef, rig));
                vecV[i].clear();
                for (auto it : vec)
                    vecV[i].pb(it);

                int l = 0;
                for (auto it : vecV[i]) {
                    ans += max(0, (it.first - l) - k + 1);
                    l = it.second + 1;
                }
                ans += max(0, (n - l) - k + 1);
            }
        }
    }

    cout << ans;
}
