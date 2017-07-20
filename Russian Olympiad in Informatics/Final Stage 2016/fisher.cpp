#include <bits/stdc++.h>
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tt;


const int N = 320000 + 5;

int n, m;
ll p;
ll pos = 0;
ll allFish = 0;
ll prodFish = 0;
ll navar = 0;
int linksSize = 0;
ll linksVal[N];
ll linksMn[N];
int xs[N];
int as[N];
int ys[N];
int bs[N];
int cs[N];

map<ll, int> links;

ll tree[4*N];
ll treeAns[4*N];

void add(int v, int l, int r, int pos, ll plus, ll mn) {
    if (l == r) {
        tree[v] += plus;
        treeAns[v] += plus * mn;
    } else {
        if (pos <= (l + r) / 2)
            add(v * 2, l, (l + r) / 2, pos, plus, mn);
        else
            add(v * 2 + 1, (l + r) / 2 + 1, r, pos, plus, mn);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
        treeAns[v] = treeAns[v * 2] + treeAns[v * 2 + 1];
    }
}

int getMinPos(int v, int l, int r, ll all) {
    if (l == r)
        return l;
    if (tree[v * 2] >= all)
        return getMinPos(v * 2, l, (l + r) / 2, all);
    else
        return getMinPos(v * 2 + 1, (l + r) / 2 + 1, r, all - tree[v * 2]);
}

ll getVals(int v, int l, int r, int L, int R) {
    if (l > R || L > r)
        return 0;
    if (l >= L && r <= R)
        return tree[v];
    return getVals(v * 2, l, (l + r) / 2, L, R) +
           getVals(v * 2 + 1, (l + r) / 2 + 1, r, L, R);
}

ll getAns(int v, int l, int r, int L, int R) {
    if (l > R || L > r)
        return 0;
    if (l >= L && r <= R)
        return treeAns[v];
    return getAns(v * 2, l, (l + r) / 2, L, R) +
           getAns(v * 2 + 1, (l + r) / 2 + 1, r, L, R);
}

ll getAns() {
    if (allFish >= prodFish)
        return navar - p * pos;
    if (allFish <= linksVal[0])
        return allFish * linksMn[0] - p * pos;

    ll ans = 0, curr = allFish;
    ll mini;

    int a = 0, b = N - 1, v = 1;
    ll fish = allFish;

    while (a != b) {
        if (tree[v * 2] > fish) {
            b = (a + b) / 2;
            v = v * 2;
        } else {
            a = (a + b) / 2 + 1;
            fish -= tree[v * 2];
            v = v * 2 + 1;
        }
    }

    if (a - 2 >= 0) {
        curr -= getVals(1, 0, N - 1, 0, a - 2);
        ans += getAns(1, 0, N - 1, 0, a - 2);
    }

    for (int i = max(0, a - 1); i <= a + 3; i++) {
        mini = min(curr, linksVal[i]);
        ans += mini * linksMn[i];
        curr -= mini;
    }

    return ans - pos * p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("fisher.in", "r", stdin);
    //freopen("fisher.out", "w", stdout);

    memset(linksVal, 0, sizeof(linksVal));
    memset(linksMn, 0, sizeof(linksMn));
    memset(tree, 0, sizeof(tree));
    memset(treeAns, 0, sizeof(treeAns));

    scanf("%d%d%lld", &n, &m, &p);
    vector<tt> sobs;

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &xs[i], &as[i]);
        sobs.pb(mt(xs[i], 1, i));  // FISH
    }

    set<ll> st;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &ys[i], &bs[i], &cs[i]);
        sobs.pb(mt(ys[i], 2, i));  // PROD
        st.ins(-cs[i]);
    }
    for (auto it : st) {
        linksMn[linksSize] = -it;
        links[-it] = linksSize;
        linksSize++;
    }
    for (int i = 0; i < m; i++)
        cs[i] = links[cs[i]];

    sort(sobs.begin(), sobs.end());

    ll ans = 0;
    for (int i = 0; i < sobs.size(); i++) {
        pos = get<0>(sobs[i]);
        int type = get<1>(sobs[i]);
        int index = get<2>(sobs[i]);
        if (type == 1) {
            allFish += as[index];
        } else {
            prodFish += bs[index];
            navar += bs[index] * linksMn[cs[index]];
            linksVal[cs[index]] += bs[index];
            add(1, 0, N - 1, cs[index], bs[index], linksMn[cs[index]]);
        }
        ans = max(ans, getAns());
    }

    cout << ans;
}