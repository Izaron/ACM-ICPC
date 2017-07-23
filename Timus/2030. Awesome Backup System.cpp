#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int N = 100000 + 5;
const int SQ = sqrt(N) + 1;
const int MOD = 1000000000 + 7;

int n;
vector<int> neig[N];
vector<int> heavis[N];
int heavisVal[N];
int as[N];
int added[N];
int havyAs[N];
bool isHeavy[N];
bool hasUpd[N];


void upd(int v) {
    added[v] = 0;
    for (auto it : heavis[v]) {
        added[v] += heavisVal[it];
        added[v] %= MOD;
    }
}

int gett(int v) {
    upd(v);
    return (as[v] + added[v]) % MOD;
}

int add(int v) {
    if (isHeavy[v]) {
        heavisVal[v] += gett(v);
        heavisVal[v] %= MOD;
    } else {
        int gt = gett(v);
        for (auto it : neig[v]) {
            as[it] += gt;
            as[it] %= MOD;
        }
    }
}

void calc(int v) {
    if (neig[v].size() >= SQ) {
        isHeavy[v] = true;
        for (auto it : neig[v])
            heavis[it].pb(v);
    }
}

int main() {
    fill(isHeavy, isHeavy + N, false);
    fill(hasUpd, hasUpd + N, false);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
        havyAs[i] = 0;
        heavisVal[i] = 0;
        added[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        neig[x].pb(y);
        neig[y].pb(x);
    }

    for (int i = 0; i < n; i++)
        calc(i);

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int t, v;
        scanf("%d%d", &t, &v);
        v--;
        if (t == 2) {
            printf("%d\n", gett(v));
        } else {
            add(v);
        }
    }
}
