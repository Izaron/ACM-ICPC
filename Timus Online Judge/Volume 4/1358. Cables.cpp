// The solution of the problem was written by Izaron
// Date: 20:25:18   21 Aug 2016
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <stdio.h>
#include <random>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef long double ld;

const int maxn = 1000 + 5;

int n;
vector<int> neig[maxn];
vector<int> deeps[maxn];
int xs[maxn];
int ys[maxn];

void dfs(int v, int p, int deep) {
    deeps[deep].push_back(v);
    for (auto it : neig[v]) {
        if (it == p)
            continue;
        dfs(it, v, deep + 1);
    }
}

void set_deep(int v) {
    int x = -1000, y = 1000 - v * 2;
    for (auto it : deeps[v]) {
        xs[it] = x;
        ys[it] = y;
        x += 2;
    }
}

int main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        neig[a].push_back(b);
        neig[b].push_back(a);
    }

    dfs(0, 0, 0);

    int val = 0;
    for (int i = 0; i < maxn; i++) {
        if (deeps[i].size() == 0)
            break;
        val = i;
    }

    if (val == 1000 - 1) {
        deeps[998].push_back(deeps[999][0]);
        deeps[999].clear();
    }

    for (int i = 0; i < maxn; i++) {
        if (deeps[i].size() == 0)
            break;
        set_deep(i);
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", xs[i], ys[i]);
    }
}
