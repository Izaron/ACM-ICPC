// The solution of the problem was written by Izaron
// Date: 23:07:10   27 Jul 2017
// Execution time: 1.388

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#pragma comment(linker, "/STACK:36777216")
#include <vector>
#include <string.h>
#include <iostream>
#include <map>
#include <limits.h>
#include <set>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

const int maxn = 2e5 + 5;

int n, q;
vector<int> neig[maxn];
vector<pii> vec;
vector<pii> gens;
vector<int> first;
vector<pii> rili;

void dfs(int v, int last, int d) {
    vec[v] = { d, v };
    first[v] = gens.size();
    gens.push_back({ d, v });
    for (auto it : neig[v]) {
        if (it == last)
            continue;
        dfs(it, v, d + 1);
        gens.push_back({ d, v });
    }
}

struct tree {
    vector<pii> src;
    int n;
    vector<pii> t;

    void build(int v, int l, int r) {
        if (l == r) {
            t[v] = src[l];
        } else {
            build(v * 2, l, (l + r) / 2);
            build(v * 2 + 1, (l + r) / 2 + 1, r);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }

    void init(vector<pii>& vec) {
        src = vec;
        n = src.size();
        t.resize(4 * n);
        build(1, 0, n - 1);
    }

    pii get(int v, int L, int R, int l, int r) {
        if (r < L || R < l)
            return { INT_MAX / 2, INT_MAX / 2 };
        if (l >= L && r <= R)
            return t[v];
        return min(
            get(v * 2, L, R, l, (l + r) / 2),
            get(v * 2 + 1, L, R, (l + r) / 2 + 1, r)
        );
    }

    pii get(int l, int r) {
        return get(1, l, r, 0, n - 1);
    }

    void clear() {
        src.clear();
        t.clear();
    }
};

struct sparse_table {
    vector<pii> t[20];
    vector<int> logs;

    void init(vector<pii>& vec) {
        int n = vec.size();
        logs.resize(n + 1);
        for (int i = 2; i <= n; i++)
            logs[i] = logs[i >> 1] + 1;
        int lg = logs[n] + 1;

        for (int i = 0; (1 << i) < n; i++) {
            t[i].resize(n);
            if (i == 0) {
                for (int z = 0; z < n; z++)
                    t[i][z] = vec[z];
            } else {
                for (int z = 0; z + (1 << i) <= n; z++)
                    t[i][z] = min(
                        t[i - 1][z],
                        t[i - 1][z + (1 << (i - 1))]
                    );
            }
        }
    }

    pii get(int l, int r) {
        int k = logs[r - l];
        return min(
            t[k][l],
            t[k][r - (1 << k) + 1]
        );
    }
} st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    scanf("%d", &n);

    if (n == 1) {
        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++)
            printf("1\n");
        return 0;
    }

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        a--; b--;
        neig[a].push_back(b);
        neig[b].push_back(a);
    }

    vec.resize(n);
    first.resize(n);
    dfs(0, 0, 0);

    tree t;
    t.init(gens);

    rili.resize(n - 1);
    for (int i = 0; i < n - 1; i++)
        rili[i] = t.get(min(first[i], first[i + 1]), max(first[i], first[i + 1]));

    st.init(rili);

    int q;
    scanf("%d", &q);
    int l, r;
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &l, &r);
        l--; r--;
        if (l == r)
            printf("%d\n", l + 1);
        else
            printf("%d\n", st.get(l, r - 1).second + 1);
    }
}
