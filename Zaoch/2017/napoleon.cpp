#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

#ifdef USE_CERR
#define CERR(a) cerr << a << endl
#else
#define CERR(a)
#endif

const int maxn = 3000 + 5;
const int maxn2 = 1e5 + 5;

int n, k;
vector<tt> vec_s;
vector<pii> vec;
vector<int> cost;
int calc[maxn][maxn];
int nxt[maxn][maxn];

bool inter(int a, int b) {
    return vec[a].second + 1 >= vec[b].first;
}

bool inside(int a, int b) {
    if (b == n)
        return false;
    return vec[b].second <= vec[a].second;
}

bool ending(int a) {
    return vec[a].second == k;
}

bool starting(int a) {
    return vec[a].first == 1;
}

int dp(int a, int b) {
    if (calc[a][b] != -1)
        return calc[a][b];
    int & lol = calc[a][b];
    lol = INT_MAX;

    if (b < n && vec[a].second + 1 < vec[b].first)
        return lol;

    if (ending(a)) {
        lol = cost[a];
        return lol;
    }
    if (inside(a, b)) {
        lol = dp(a, b + 1);
        return lol;
    }
    if (b + 1 < n && inter(a, b + 1))
        lol = min(lol, dp(a, b + 1));

    // get this!
    if (vec[a].second < vec[b].first) {
        int c = lol, d = cost[a], e = cost[b], f = dp(b, nxt[a][b]);
        int val = 0;
        //val = max(val, c);
        val = max(val, d);
        val = max(val, e);
        val = max(val, f);

        lol = min(lol, val);
    } else {
        int c = lol, d = cost[a], e = cost[b], f = dp(b, nxt[a][b]), g = cost[a] + cost[b];
        int val = 0;
        //val = max(val, c);
        val = max(val, d);
        val = max(val, e);
        val = max(val, f);
        val = max(val, g);

        lol = min(lol, val);
    }

    return lol;
}

int calc_next(int a) {
    if (vec[n - 1].first <= vec[a].second)
        return n;
    int l = 0, r = n - 1;
    while (l != r) {
        int la = l, lb = r;
        int mid = (l + r) / 2;
        if (vec[mid].first > vec[a].second)
            r = mid;
        else
            l = mid;
        if (la == l && lb == r) {
            if (vec[l].first > vec[a].second)
                r = l;
            else
                l = r;
        }
    }
    return l;
}

void solvep1(int n, int k, vector<pii> pos) {
    map<int, vector<int> > mp;
    map<int, int> sum;
    bool can = false;
    bool meme = true;

    for (int i = 0; i < n; i++) {
        if (pos[i].first == 1 && pos[i].second == k)
            can = true;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (pos[i].second == k) {
            sum[pos[i].first] = 1;
            meme = false;
        } else {
            int val = sum[pos[i].second + 1];
            if (val == 1) {
                sum[pos[i].first] = 1;
            }
        }
    }

    if (meme) {
        cout << -1;
        return;
    }

    if (sum[1] == 1)
        can = true;

    int maximan = 0;
    for (int i = 0; i < n - 1; i++) {
        maximan = max(maximan, pos[i].second);
        if (pos[i + 1].first > maximan + 1) {
            cout << -1;
            return;
        }
    }

    if (pos[0].first != 1) {
        cout << -1;
        return;
    }

    cout << (can ? 1 : 2);
}

int main() {
    scanf("%d%d", &n, &k);
    vec_s.resize(n);
    vec.resize(n);
    cost.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        vec_s[i] = make_tuple(a, b, c);
    }
    sort(vec_s.begin(), vec_s.end());
    bool p1 = true;
    for (int i = 0; i < n; i++) {
        vec[i].first = get<0>(vec_s[i]);
        vec[i].second = get<1>(vec_s[i]);
        cost[i] = get<2>(vec_s[i]);
        if (cost[i] != 1)
            p1 = false;
    }

    if (p1) {
    solvep1(n, k, vec);
    return 0;
    }
    //////

    memset(nxt, 0, sizeof(nxt));
    memset(calc, -1, sizeof(calc));

    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            if (inside(a, b))
                continue;
            nxt[a][b] = calc_next(a);
            int lal = nxt[a][b];
            int kek = 0;
        }
    }

    int val = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!starting(i))
            continue;
        int lil = dp(i, nxt[i][i]);
        val = min(val, dp(i, nxt[i][i]));
    }

    if (val == INT_MAX)
        val = -1;

    printf("%d\n", val);
}

/*
 3 4
 1 3 1
 3 4 2
 1 4 5

 1 3
 1 2 1

 4 5
 1 4 3
 4 5 5
 1 1 3
 1 2 1

 4 5
 1 4 1
 4 5 1
 3 4 1
 5 5 1
 */