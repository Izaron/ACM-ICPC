// The solution of the problem was written by Izaron
// Date: 17:18:20   25 May 2016
// Execution time: 0.327

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

int n;
string s;
int type[N];
int add[N];

int nxt[N];
int lst[N];

map<tt, set<int>> nxtMp;
tt nxtSum[N];

int getNxt(int v) {
    tt tup;

    if (v - 1 < 0) {
        tup = mt(0, 0, 0, 0);
    } else {
        tup = nxtSum[v - 1];
    }

    set<int>::iterator iter = nxtMp[tup].upper_bound(v);
    if (iter == nxtMp[tup].end())
        return 1000000000;
    return *iter;
}


int ansTree[N * 4][4];
int ans[N][4];

void ansBuild(int v, int L, int R, int t) {
    if (L == R) {
        ansTree[v][t] = ans[L][t];
    } else {
        ansBuild(v * 2, L, (L + R) / 2, t);
        ansBuild(v * 2 + 1, (L + R) / 2 + 1, R, t);
        ansTree[v][t] = min(ansTree[v * 2][t], ansTree[v * 2 + 1][t]);
    }
}

int ansGet(int v, int L, int R, int t, int l, int r) {
    if (R < l || r < L)
        return 1000000000;
    if (L >= l && R <= r)
        return ansTree[v][t];
    return min(
            ansGet(v * 2, L, (L + R) / 2, t, l, r),
            ansGet(v * 2 + 1, (L + R) / 2 + 1, R, t, l, r)
    );
}


int nxtTree[4 * N];
void nxtBuild(int v, int L, int R) {
    if (L == R) {
        nxtTree[v] = nxt[L];
        if (s[L] >= 'a' && s[L] <= 'z')
            nxtTree[v] = L;
    } else {
        nxtBuild(v * 2, L, (L + R) / 2);
        nxtBuild(v * 2 + 1, (L + R) / 2 + 1, R);
        nxtTree[v] = max(nxtTree[v * 2], nxtTree[v * 2 + 1]);
    }
}
int nxtGet(int v, int L, int R, int l, int r) {
    if (r < L || R < l)
        return -1;
    if (L >= l && R <= r)
        return nxtTree[v];
    return max(
            nxtGet(v * 2, L, (L + R) / 2, l, r),
            nxtGet(v * 2 + 1, (L + R) / 2 + 1, R, l, r)
    );
}

int lstTree[4 * N];
void lstBuild(int v, int L, int R) {
    if (L == R) {
        lstTree[v] = lst[L];
        if (s[L] >= 'A' && s[L] <= 'Z')
            lstTree[v] = L;
    } else {
        lstBuild(v * 2, L, (L + R) / 2);
        lstBuild(v * 2 + 1, (L + R) / 2 + 1, R);
        lstTree[v] = min(lstTree[v * 2], lstTree[v * 2 + 1]);
    }
}
int lstGet(int v, int L, int R, int l, int r) {
    if (r < L || R < l)
        return 1000000000;
    if (L >= l && R <= r)
        return lstTree[v];
    return min(
            lstGet(v * 2, L, (L + R) / 2, l, r),
            lstGet(v * 2 + 1, (L + R) / 2 + 1, R, l, r)
    );
}

int findNext(int v) {
    int nxt = getNxt(v);
    if (nxt >= n)
        return nxt;

    for (int t = 0; t < 4; t++) {
        int mini = ansGet(1, 0, n - 1, t, v, nxt - 1);
        if (v > 0)
            mini -= ans[v - 1][t];
        if (mini < 0)
            return 1000000000;
    }

    return nxt;
}

int main() {
    cin >> s;
    fill(nxt, nxt + N, -1);
    fill(lst, lst + N, -1);
    n = (int)s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            add[i] = 1;
        else
            add[i] = -1;
        if (tolower(s[i]) == 'a')
            type[i] = 0;
        if (tolower(s[i]) == 'c')
            type[i] = 1;
        if (tolower(s[i]) == 'g')
            type[i] = 2;
        if (tolower(s[i]) == 't')
            type[i] = 3;
    }

    int anss[4] = { 0, 0, 0, 0 };
    for (int i = 0; i < n; i++) {
        anss[type[i]] += add[i];
        tt tup = mt(anss[0], anss[1], anss[2], anss[3]);
        nxtMp[tup].ins(i);
        nxtSum[i] = tup;

        ans[i][0] = anss[0];
        ans[i][1] = anss[1];
        ans[i][2] = anss[2];
        ans[i][3] = anss[3];
    }

    ansBuild(1, 0, n - 1, 0);
    ansBuild(1, 0, n - 1, 1);
    ansBuild(1, 0, n - 1, 2);
    ansBuild(1, 0, n - 1, 3);

    for (int i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            nxt[i] = findNext(i);
            if (nxt[i] < n)
                lst[nxt[i]] = i;
        }
    }

    nxtBuild(1, 0, n - 1);
    lstBuild(1, 0, n - 1);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if ((b - a + 1) % 2 == 1) {
            cout << 0;
            continue;
        }

        bool can = true;

        int big = nxtGet(1, 0, n - 1, a, b);
        int low = lstGet(1, 0, n - 1, a, b);

        if (big > b || low < a)
            can = false;

        /*for (int z = a; z <= b; z++) {
            if (s[z] >= 'A' && s[z] <= 'Z') {
                if (nxt[z] > b) {
                    can = false;
                    break;
                }
            } else {
                if (lst[z] < a) {
                    can = false;
                    break;
                }
            }
        }*/

        if (can)
            cout << 1;
        else
            cout << 0;
    }
}
