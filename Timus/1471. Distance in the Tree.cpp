// The solution of the problem was written by Izaron
// Date: 15:55:59   17 Aug 2016
// Execution time: 0.405

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define gv(v, i) get<i>(v)
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int maxn = 50000 + 5;
const int infi = 1e9;
const int power = 20;

int n, m;
vector<pii> neig[maxn];
int dep[maxn];
int parent[maxn][power];
int weight[maxn][power];

void dfs(int v, int p, int d) {
    dep[v] = d;
    for (int i = 1; i < power; i++) {
        parent[v][i] = parent[parent[v][i - 1]][i - 1];
        weight[v][i] = weight[v][i - 1] + weight[parent[v][i - 1]][i - 1];
    }

    for (auto it : neig[v]) {
        int to = it.first, w = it.second;
        if (to == p)
            continue;
        parent[to][0] = v;
        weight[to][0] = w;
        dfs(to, v, d + 1);
    }
}

int get(int a, int b) {
    if (dep[a] < dep[b])
        swap(a, b);
    int ans = 0;
    for (int i = power - 1; i >= 0; i--) {
        if (dep[a] - (1 << i) >= dep[b]) {
            ans += weight[a][i];
            a = parent[a][i];
        }
    }

    if (a == b)
        return ans;

    for (int i = power - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            ans += weight[a][i];
            ans += weight[b][i];
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    ans += weight[a][0];
    ans += weight[b][0];

    return ans;
}

int main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #endif

    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        neig[a].push_back(mkp(b, c));
        neig[b].push_back(mkp(a, c));
    }

    memset(parent, 0, sizeof(parent));
    memset(weight, 0, sizeof(weight));

    dfs(0, 0, 0);

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", get(a, b));
    }
}
