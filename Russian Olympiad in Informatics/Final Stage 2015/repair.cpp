#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef pair<int, int> pii;

#ifdef USE_CERR
#define CERR(a) cerr << "dump: " << a << endl;
#else
#define CERR(a)
#endif

template<typename T> using ordered_set = tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 2e5 + 10;

int n;
map<pii, int> vert_map;
vector<pii> pos;
vector<pii> ignor;
vector<int> neig[maxn];
vector<int> rneig[maxn];

int vert(int a, int b) {
    pii p = { a, b };
    if (vert_map.count(p))
        return vert_map[p];
    int cur = vert_map.size();
    vert_map[p] = cur;
    pos.push_back(p);
    return cur;
}

void append(int a, int b) {
    neig[a].push_back(b);
    neig[b].push_back(a);
}

vector<ordered_set<int>> to_right;
vector<ordered_set<int>> to_left;
vector<ordered_set<int>> to_up;
vector<ordered_set<int>> to_down;

void add_set(ordered_set<int> & st, int v) {
    st.insert(v);
}

void add_val(int v, pii a, pii b) {
    if (a.first + 1 == b.first)
        add_set(to_right[a.first], a.second);
    if (a.first - 1 == b.first)
        add_set(to_left[a.first], a.second);
    if (a.second + 1 == b.second)
        add_set(to_down[a.second], a.first);
    if (a.second - 1 == b.second)
        add_set(to_up[a.second], a.first);
}

void dfs(int v, int last) {
    for (auto it : neig[v]) {
        if (it == last)
            continue;
        rneig[v].push_back(it);
        dfs(it, v);
    }
}

void calc() {
    for (int i = 0; i < n; i++) {
        for (auto it : rneig[i]) {
            add_val(i, pos[i], pos[it]);
        }
    }
}

pii as, bs;

int get_in_bounds(ordered_set<int> & st, int a, int b) {
    int cnt_b = st.order_of_key(b + 1);     // all nums <= b
    int cnt_a = st.order_of_key(a);     // all nums < a
    return cnt_b - cnt_a;
}

int find() {
    int ans = 0;

    ans += get_in_bounds(to_right[as.first - 1], as.second, bs.second);
    ans += get_in_bounds(to_left[bs.first + 1], as.second, bs.second);
    ans += get_in_bounds(to_down[as.second - 1], as.first, bs.first);
    ans += get_in_bounds(to_up[bs.second + 1], as.first, bs.first);

    // root in place
    pii root = pos[0];
    if (root.first >= as.first && root.first <= bs.first && root.second >= as.second && root.second <= bs.second) {
        ans++;
    }

    return ans;
}

int main() {
    #ifndef HOME
    #define FILE "repair"
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
    #endif // HOME

    int a, b;
    scanf("%d%d", &a, &b);
    int q;
    scanf("%d%d", &n, &q);
    char ch;
    for (int i = 0; i < n - 1; i++) {
        cin >> ch;
        int x, y;
        scanf("%d%d", &x, &y);
        int aa, bb;
        if (ch == 'v') {
            aa = vert(x, y);
            bb = vert(x, y + 1);
        } else {
            aa = vert(x, y);
            bb = vert(x + 1, y);
        }
        append(aa, bb);
    }

    ignor.resize(n);
    dfs(0, 0);

    to_right.resize(max(a, b) + 2);
    to_left.resize(max(a, b) + 2);
    to_up.resize(max(a, b) + 2);
    to_down.resize(max(a, b) + 2);

    calc();

    for (int i = 0; i < q; i++) {
        scanf("%d%d", &as.first, &as.second);
        scanf("%d%d", &bs.first, &bs.second);
        printf("%d\n", find());
    }
}