// The solution of the problem was written by Izaron
// Date: 01:21:47   28 Jul 2017
// Execution time: 0.124

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <limits.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

const int maxn = 4000 + 5;

int n, m;
bitset<maxn / 4> need[maxn];
bitset<maxn / 4> give[maxn];
int cnt[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(cnt, 0, sizeof(cnt));

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        for (int z = 0; z < n; z++) {
            if (s[z] == '1') {
                need[i].set(z);
                cnt[i]++;
            }
        }
        cin >> s;
        for (int z = 0; z < n; z++) {
            if (s[z] == '1')
                give[i].set(z);
        }
    }

    set<int> have;
    string s;
    cin >> s;
    for (int z = 0; z < n; z++) {
        if (s[z] == '1')
            have.insert(z);
    }

    for (int i = 0; i < m; i++) {
        if (cnt[i] == 0) {
            for (int z = 0; z < n; z++) {
                if (give[i][z])
                    have.insert(z);
            }
        }
    }

    string res = "";
    for (int z = 0; z < n; z++)
        res += "0";

    while (!have.empty()) {
        int h = (*have.begin());
        have.erase(h);
        res[h] = '1';
        for (int i = 0; i < m; i++) {
            if (need[i][h]) {
                need[i].set(h, 0);
                cnt[i]--;
                if (cnt[i] == 0) {
                    for (int z = 0; z < n; z++) {
                        if (give[i][z] && res[z] == '0')
                            have.insert(z);
                    }
                }
            }
        }
    }

    cout << res << endl;
}
