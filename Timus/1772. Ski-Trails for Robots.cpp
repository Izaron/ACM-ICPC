#include <bits/stdc++.h>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;

const int maxn = 100000 + 5;

int n, s, k;
vector<int> nxt[2];
vector<pii> robots;

struct tree {
    int n;
    vector<int> delta;
    vector<int> tree;

    void push(int v, int l, int r) {
        if (delta[v] != -1) {
            tree[v] = delta[v];
            if (l != r) {
                delta[v * 2] = delta[v];
                delta[v * 2 + 1] = delta[v];
            }
            delta[v] = -1;
        }
    }

    void change(int v, int l, int r, int L, int R, int d) {
        push(v, l, r);
        if (r < L || R < l)
            return;
        if (l >= L && r <= R) {
            delta[v] = d;
            return;
        }
        change(v * 2, l, (l + r) / 2, L, R, d);
        change(v * 2 + 1, (l + r) / 2 + 1, r, L, R, d);
    }

    int get(int v, int l, int r, int pos) {
        push(v, l, r);
        if (l == r) {
            return tree[v];
        } else {
            if (pos <= (l + r) / 2)
                return get(v * 2, l, (l + r) / 2, pos);
            else
                return get(v * 2 + 1, (l + r) / 2 + 1, r, pos);
        }
    }

    void init(int n) {
        this->n = n;
        delta.resize(4 * n);
        tree.resize(4 * n);
        fill(delta.begin(), delta.end(), -1);
        fill(tree.begin(), tree.end(), -1);
    }
} t;

int find_next(int v, int pos) {
    int val = t.get(1, 0, t.n - 1, pos);
    if (val == -1)
        return k + 1;
    return val;

    /*
    for (int i = v + 1; i <= k; i++) {
        if (pos >= robots[i].first && pos <= robots[i].second) {
            return i;
        }
    }
    return k + 1;
    */
}

int go(int v1, int pos1, int v2, int pos2) {
    if (max(v1, v2) > k)
        return 0;
    int a = 0, b = 0;
    if (v1 == 0)
        a = s;
    else if (pos1 == 0)
        a = robots[v1].first - 1;
    else
        a = robots[v1].second + 1;
    if (v2 == 0)
        b = s;
    else if (pos2 == 0)
        b = robots[v2].first - 1;
    else
        b = robots[v2].second + 1;
    return abs(a - b);
}

int64_t ank[maxn][2];

int64_t dp(int v, int pos) {
    // v - num, pos - [up/down]
    if (v > k)
        return 0;
    if (ank[v][pos] != -1)
        return ank[v][pos];
    int64_t ans = LLONG_MAX;
    if (robots[nxt[pos][v]].first != 0)
        ans = min(ans, go(v, pos, nxt[pos][v], 0) + dp(nxt[pos][v], 0));
    if (robots[nxt[pos][v]].second != n - 1)
        ans = min(ans, go(v, pos, nxt[pos][v], 1) + dp(nxt[pos][v], 1));
    ank[v][pos] = ans;
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);

    for (int i = 0; i < maxn; i++) {
        ank[i][0] = -1;
        ank[i][1] = -1;
    }
    scanf("%d%d%d", &n, &s, &k);
    s--;
    nxt[0].resize(k + 1);
    nxt[1].resize(k + 1);
    robots.resize(k + 1);
    robots[0].first = s;
    robots[0].second = s;
    t.init(n);
    for (int i = 1; i <= k; i++) {
        scanf("%d%d", &robots[i].first, &robots[i].second);
        robots[i].first--;
        robots[i].second--;
    }

    //for (int i = 0; i <= k; i++) {
    //    cerr << "POSITION: " << robots[i].first << " " << robots[i].second << endl;
    //}

    for (int i = k; i >= 0; i--) {
        if (i == 0) {
            nxt[0][i] = find_next(i, robots[i].first);
            nxt[1][i] = nxt[0][i];
            continue;
        }
        if (robots[i].first != 0)
            nxt[0][i] = find_next(i, robots[i].first - 1);
        if (robots[i].second != n - 1)
            nxt[1][i] = find_next(i, robots[i].second + 1);

        t.change(1, 0, t.n - 1, robots[i].first, robots[i].second, i);
        //for (int z = 0; z < t.n; z++) {
        //    cerr << t.get(1, 0, t.n - 1, z) << " ";
        //}
        //cerr << endl;
    }

    /*for (int i = 0; i <= k; i++) {
        cerr << i << endl;
        cerr << "NEXT0: " << nxt[0][i] << endl;
        cerr << "NEXT1: " << nxt[1][i] << endl;
        cerr << endl;
    }*/

    cout << dp(0, 0);
}
