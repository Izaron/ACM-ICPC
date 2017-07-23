#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int N = 3 * 100000 + 5;
const int SQ = sqrt(N) + 1;

int n;
ll delta[SQ];
bool isDel[N];
int dell[N];
ll val[N];
ll nach[N];
ll anss;
vector<int> keki[N];
int delVec[N]; int cdel;
int vecA[N];
int vecB[N];
int cvec;

void add(int l, int r, ll d) {
    for (int i = l; i <= r;) {
        if (isDel[i] && i + SQ - 1 <= r) {
            delta[dell[i]] += d;
            i += SQ;
        } else {
            val[i] += d;
            i++;
        }
    }
}

ll gett(int v) {
    return val[v] + delta[dell[v]];
}

void dfs(int v, int curr, int pos) {
    if (pos >= cvec)
        return;
    delVec[cdel++] = curr;
    for (int i = 0; i <= vecB[pos]; i++) {
        if (i > 0) {
            curr *= vecA[pos];
            delVec[cdel++] = curr;
        }
        dfs(v, curr, pos + 1);
    }
}

int main() {
    memset(isDel, false, sizeof(isDel));
    memset(dell, 0, sizeof(dell));
    for (int i = 0; i < N; i++) {
        if (i % SQ == 0)
            isDel[i] = true;
        dell[i] = i / SQ;
    }

    for (int i = 1; i < N; i++) {
        cvec = 0;
        cdel = 0;
        vecA[cvec] = 1;
        vecB[cvec] = 1;
        cvec++;
        int t = i;
        for (int z = 2; z <= sqrt(t); z++) {
            while (t % z == 0) {
                if (vecA[cvec - 1] == z)
                    vecB[cvec - 1]++;
                else {
                    vecA[cvec] = z;
                    vecB[cvec] = 1;
                    cvec++;
                }
                t /= z;
            }
        }
        if (t > 1) {
            vecA[cvec] = t;
            vecB[cvec] = 1;
            cvec++;
        }

        dfs(i, 1, 0);
        sort(delVec, delVec + cdel);
        keki[i].pb(delVec[0]);
        for (int z = 1; z < cdel; z++) {
            if (delVec[z] != delVec[z - 1]) {
                keki[i].pb(delVec[z]);
            }
        }
    }

    scanf("%d", &n);
    for (int i = 0; i < SQ; i++)
        delta[i] = 0;
    for (int i = 0; i < N; i++)
        val[i] = 0;

    for (int i = 1; i <= n; i++)
        scanf("%d", &nach[i]);

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int com;
        scanf("%d", &com);
        if (com == 1) {
            int v;
            scanf("%d", &v);
            anss = nach[v];

            for (auto it : keki[v])
                anss += gett(it);

            printf("%I64d\n", anss);
        } else {
            int l, r;
            ll d;
            scanf("%d%d%I64d", &l, &r, &d);
            add(l, r, d);
        }
    }
}
