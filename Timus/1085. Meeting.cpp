// The solution of the problem was written by Izaron
// Date: 19:19:41   20 May 2016
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
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

const int N = 100 + 5;


int cnt[N][N];
int n, m, k;
int money[N], place[N], pr[N];

int gett(int v) {
    int ans = 0;
    for (int i = 0; i < k; i++) {
        if (cnt[place[i]][v] == 100000000)
            return -1;
        int cost = cnt[place[i]][v] * 4;
        if (money[i] < cost && pr[i] != 1)
            return -1;
        if (pr[i] != 1)
            ans += max(0, cnt[place[i]][v]);
    }
    return ans;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int z = 0; z < n; z++)
            cnt[i][z] = 100000000;
        cnt[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int l;
        cin >> l;
        vector<int> vec;
        for (int z = 0; z < l; z++) {
            int tmp;
            cin >> tmp;
            vec.pb(tmp - 1);
        }
        for (int a = 0; a < l; a++) {
            for (int b = a + 1; b < l; b++) {
                cnt[vec[a]][vec[b]] = 1;
                cnt[vec[b]][vec[a]] = 1;
            }
        }
    }

    for (int kk = 0; kk < n; kk++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cnt[i][j] = min(cnt[i][j], cnt[i][kk] + cnt[kk][j]);
            }
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> money[i] >> place[i] >> pr[i];
        place[i]--;
    }

    int mini = 100000000, ans = -1;
    for (int i = 0; i < n; i++) {
        int curr = gett(i);
        if (curr == -1)
            continue;
        if (curr < mini) {
            mini = curr;
            ans = i;
        }
    }

    if (ans == -1) {
        cout << 0;
    } else {
        cout << ans + 1 << " " << mini * 4;
    }
}
