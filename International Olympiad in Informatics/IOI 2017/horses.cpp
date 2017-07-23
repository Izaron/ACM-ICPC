#include "horses.h"
#include <bits/stdc++.h>
#define mkp make_pair
using namespace std;

const int64_t mod = (int)1e9 + 7;

typedef pair<int64_t, int64_t> pii;

int n;
vector<int64_t> mods;
vector<int64_t> cost;
set<int> mods_pos;

struct {
    int n;
    vector<int64_t> tree;

    void init(int n) {
        this->n = n;
        tree.resize(4 * n);
    }

    void change(int v, int l, int r, int pos, int64_t val) {
        if (l == r) {
            tree[v] = val;
        } else {
            if (pos <= (l + r) / 2)
                change(v * 2, l, (l + r) / 2, pos, val);
            else
                change(v * 2 + 1, (l + r) / 2 + 1, r, pos, val);
            tree[v] = (tree[v * 2] * tree[v * 2 + 1]) % mod;
        }
    }

    void change(int pos, int64_t val) {
        change(1, 0, n - 1, pos, val);
    }

    int64_t get(int v, int l, int r, int L, int R) {
        if (r < L || R < l)
            return 1;
        if (l >= L && r <= R)
            return tree[v];
        return (get(v * 2, l, (l + r) / 2, L, R) * get(v * 2 + 1, (l + r) / 2 + 1, r, L, R)) % mod;
    }

    int64_t get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
} t;

struct {
    int n;
    vector<pii> tree;

    void init(int n) {
        this->n = n;
        tree.resize(4 * n);
    }

    void change(int v, int l, int r, int pos, int64_t val) {
        if (l == r) {
            tree[v] = mkp(val, l);
        } else {
            if (pos <= (l + r) / 2)
                change(v * 2, l, (l + r) / 2, pos, val);
            else
                change(v * 2 + 1, (l + r) / 2 + 1, r, pos, val);
            tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    void change(int pos, int64_t val) {
        change(1, 0, n - 1, pos, val);
    }

    pii get(int v, int l, int r, int L, int R) {
        if (r < L || R < l)
            return mkp(-1, -1);
        if (l >= L && r <= R)
            return tree[v];
        return max(get(v * 2, l, (l + r) / 2, L, R), get(v * 2 + 1, (l + r) / 2 + 1, r, L, R));
    }

    pii get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
} tCost;

int query() {
    int64_t cur = 1;
    int z = 0;

    int last_pos = n;
    for (set<int>::iterator it = mods_pos.begin(); it != mods_pos.end(); it++) {
        int pos = -(*it);

        pii maxi = tCost.get(pos, last_pos - 1);
        if (maxi.first >= cur) {
            z = maxi.second;
            cur = maxi.first;
        }

        cur *= mods[pos];
        cur = max(cur, mods[pos] * cost[pos]);
        last_pos = pos;
        if (cur >= mod)
            break;
    }

    int64_t ans = t.get(0, z);
    ans *= cost[z];
    ans %= mod;

    return ans;
}

int init(int N, int X[], int Y[]) {
    n = N;
	mods.resize(N + 1);
	cost.resize(N + 1);
	for (int i = 0; i < N; i++) {
        mods[i] = X[i];
        cost[i] = Y[i];
        if (mods[i] > 1)
            mods_pos.insert(-i);
	}
    mods_pos.insert(0);

	mods[N] = 1;
	cost[N] = 1;

	t.init(n);
	for (int i = 0; i < n; i++)
        t.change(i, mods[i]);

    tCost.init(n);
    for (int i = 0; i < n; i++)
        tCost.change(i, cost[i]);

	return query();
}

int updateX(int pos, int val) {
    if (mods[pos] > 1)
        mods_pos.erase(-pos);
    mods[pos] = val;
    if (mods[pos] > 1)
        mods_pos.insert(-pos);
    mods_pos.insert(0);

    t.change(pos, val);
	return query();
}

int updateY(int pos, int val) {
    cost[pos] = val;
    tCost.change(pos, val);
	return query();
}
