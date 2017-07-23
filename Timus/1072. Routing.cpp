// The solution of the problem was written by Izaron
// Date: 20:50:30   20 May 2016
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
typedef tuple<int, int, int> tt;

const int N = 90 + 5;


int n;
map<int, vector<int> > mp;
int cnt[N][N];

int getInt(string s) {
    int curr = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            ans <<= 8;
            ans += curr;
            curr = 0;
        } else {
            curr *= 10;
            curr += s[i] - '0';
        }
    }
    ans <<= 8;
    ans += curr;
    return ans;
}

int getConf() {
    string a, b;
    cin >> a >> b;
    return (getInt(a) & getInt(b));
}

void vosst(int a, int b, int kz) {
    if (kz == 0)
        return;
    for (int v = 0; v < n; v++) {
        if (cnt[a][v] == 1 && cnt[v][b] == kz - 1) {
            cout << v + 1 << " ";
            vosst(v, b, kz - 1);
            return;
        }
    }
}

int main() {
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int z = 0; z < k; z++)
            mp[getConf()].pb(i);
    }

    for (int i = 0; i < n; i++) {
        for (int z = 0; z < n; z++) {
            cnt[i][z] = 1000000;
        }
        cnt[i][i] = 0;
    }

    for (auto it : mp) {
        vector<int> vec = it.second;
        for (int i = 0; i < vec.size(); i++) {
            for (int z = i + 1; z < vec.size(); z++) {
                cnt[vec[i]][vec[z]] = 1;
                cnt[vec[z]][vec[i]] = 1;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int z = 0; z < n; z++) {
                cnt[i][z] = min(cnt[i][z], cnt[i][k] + cnt[k][z]);
            }
        }
    }

    int a, b;
    cin >> a >> b;
    a--;
    b--;

    if (cnt[a][b] == 1000000) {
        cout << "No";
    } else {
        cout << "Yes" << endl;
        cout << a + 1 << " ";
        vosst(a, b, cnt[a][b]);
    }
}
