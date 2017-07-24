// The solution of the problem was written by Izaron
// Date: 21:52:07   28 Apr 2016
// Execution time: 0.327

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
#include <map>
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int N = 100000 + 5;


int n;
int ms[N];
map<int, int> indexes;
set<int> vals;
int mleft[N];
int mright[N];
int cnt;
ll ans[N][2];

ll dp(int v, int kray) {
    if (v == cnt)
        return 0;

    if (ans[v][kray] != -1)
        return ans[v][kray];

    ll fir, sec;

    if (kray == 0) {
        fir = dp(v + 1, 0) + max(0, mright[v] - mleft[v - 1]) + max(mright[v], mleft[v - 1]) - mleft[v];
        sec = dp(v + 1, 1) + max(0, mleft[v - 1] - mleft[v]) + mright[v] - min(mleft[v], mleft[v - 1]);
    } else {
        fir = dp(v + 1, 0) + max(0, mright[v] - mright[v - 1]) + max(mright[v], mright[v - 1]) - mleft[v];
        sec = dp(v + 1, 1) + max(0, mright[v - 1] - mleft[v]) + mright[v] - min(mleft[v], mright[v - 1]);
    }

    ans[v][kray] = min(fir, sec);
    return min(fir, sec);
}

int main() {
    memset(ans, -1, sizeof(ans));

    fill(mleft, mleft + N, 2 * N);
    fill(mright, mright + N, 0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ms[i];
        vals.ins(ms[i]);
    }
    cnt = 0;
    for (int it : vals)
        indexes[it] = cnt++;

    for (int i = 0; i < n; i++) {
        ms[i] = indexes[ms[i]];
        mleft[ms[i]] = min(mleft[ms[i]], i);
        mright[ms[i]] = max(mright[ms[i]], i);
    }

    ll fir = dp(1, 1) + mright[0];
    ll sec = dp(1, 0) + mright[0] + (mright[0] - mleft[0]);

    cout << min(fir, sec) + n;
}
