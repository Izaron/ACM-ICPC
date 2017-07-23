// The solution of the problem was written by Izaron
// Date: 12:15:05   17 Aug 2016
// Execution time: 0.109

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

const int maxn = 100000 + 5;

int n, m, p;

struct node {
    int link;
    int pch;
    int parent;
    bool leaf;
    bool used;
    bool bad;
    vector<int> child;
    vector<int> next;

    node() {
        leaf = false;
        used = false;
        bad = false;
        link = -1;
        pch = 0;
        parent = -1;
        child.resize(50);
        fill(child.begin(), child.end(), -1);
        next.resize(50);
        fill(next.begin(), next.end(), -1);
    }
};

vector<node*> nodes;
map<char, int> indexer;

void add_string(string s) {
    node * nd = nodes[0];
    int num = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        int c = indexer[s[i]];
        if (nd->child[c] == -1) {
            nd->child[c] = (int)nodes.size();
            node * nnode = new node();
            nnode->pch = c;
            nnode->parent = num;
            nodes.push_back(nnode);
        }
        num = nd->child[c];
        nd = nodes[nd->child[c]];
    }
    nd->leaf = true;
}

int trans(int v, int c);

int get_link(int v) {
    node * nd = nodes[v];
    if (nd->link == -1)
        nd->link = nd->parent == 0 ? 0 : trans(get_link(nd->parent), nd->pch);
    return nd->link;
}

int trans(int v, int c) {
    node * nd = nodes[v];
    if (nd->next[c] == -1)
        nd->next[c] = nd->child[c] != -1 ? nd->child[c] : (v == 0 ? 0 : trans(get_link(v), c));
    return nd->next[c];
}

bool bad(int v) {
    node * nd = nodes[v];
    if (!nd->used) {
        nd->used = true;
        if (nd->leaf)
            nd->bad = true;
        else if (v == 0)
            nd->bad = false;
        else
            nd->bad = bad(get_link(v));
    }
    return nd->bad;
}

const int PARTS = 10;
const int64_t INFI = 10000000000;
const int POW = 10;

struct my_int {
    vector<int64_t> vec;
    my_int() {
        vec.resize(PARTS);
    }
};

my_int zero() {
    my_int ans;
    return ans;
}

my_int one() {
    my_int ans;
    ans.vec[PARTS - 1] = 1;
    return ans;
}

my_int add(my_int & a, my_int b) {
    int64_t carry = 0;
    for (int i = PARTS - 1; i >= 0; i--) {
        a.vec[i] += b.vec[i] + carry;
        carry = a.vec[i] / INFI;
        a.vec[i] %= INFI;
    }
    return a;
}

my_int ans[150][150];
bool used[150][150];

my_int dp(int v, int pos) {
    if (bad(pos))
        return zero();
    if (v == m)
        return one();
    if (used[v][pos])
        return ans[v][pos];
    used[v][pos] = true;
    for (int i = 0; i < n; i++)
        add(ans[v][pos], dp(v + 1, trans(pos, i)));
    return ans[v][pos];
}

string modify(int64_t v) {
    string s = "";
    while (v > 0) {
        s += (char)(v % 10 + '0');
        v /= 10;
    }
    reverse(s.begin(), s.end());
    while ((int)s.size() < POW)
        s = "0" + s;
    return s;
}

int main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> m >> p;
    int cnt = 0;
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++)
        indexer[s[i]] = cnt++;
    nodes.push_back(new node());

    for (int i = 0; i < p; i++) {
        cin >> s;
        add_string(s);
    }

    my_int ans = dp(0, 0);
    bool show = false;
    for (int i = 0; i < PARTS; i++) {
        if (!show && ans.vec[i] > 0) {
            show = true;
            cout << ans.vec[i];
        } else if (show) {
            cout << modify(ans.vec[i]);
        }
    }

    if (!show)
        cout << 0;
}
