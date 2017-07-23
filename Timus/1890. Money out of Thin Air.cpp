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

const int maxn = 100;

struct Node;

vector<Node*> nodes;
vector<ll> zp;
vector<ll> delta;
vector<ll> add;
vector<ll> sizer;

struct Node {
    ll s;
    vector<int> childs;
    int size;
    int pointer;
    int l, r;

    int calcSize() {
        size = 1;
        for (int i = 0; i < childs.size(); i++) {
            size += nodes[childs[i]]->calcSize();
        }
        return size;
    }

    void build(int l) {
        this->l = l;
        this->r = l + size - 1;
        int tl = l;
        for (int i = 0; i < childs.size(); i++) {
            nodes[childs[i]]->build(tl);
            tl += nodes[childs[i]]->size;
        }
        pointer = zp.size();
        zp.push_back(s);
    }
};

int n, q, s0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    nodes.push_back(new Node());
    cin >> n >> q >> s0;
    nodes[0]->s = s0;

    for (int i = 1; i < n; i++) {
        int p, s;
        cin >> p >> s;
        nodes[p]->childs.push_back(i);
        nodes.push_back(new Node());
        nodes[i]->s = s;
    }

    nodes[0]->calcSize();
    nodes[0]->build(0);

    add.resize(zp.size());
    delta.resize(zp.size());
    int SQ = 228;

    for (int i = 0; i < zp.size(); i++) {
        add[i / SQ] += zp[i];
    }

    for (int i = 0; i < q; i++) {
        string s;
        int x;
        ll y, z;
        cin >> s >> x >> y >> z;
        Node * node = nodes[x];
        if (s == "employee") {
            if (zp[node->pointer] + delta[node->pointer / SQ]  < y) {
                zp[node->pointer] += z;
                add[node->pointer / SQ] += z;
            }
        } else {
            int a = node->l, b = node->r;
            ll alls = 0, sz = b - a + 1;

            for (int s = a; s <= b;) {
                if (s % SQ == 0 && s + SQ - 1 <= b) {
                    alls += add[s / SQ];
                    alls += delta[s / SQ] * SQ;
                    s += SQ;
                } else {
                    alls += zp[s];
                    alls += delta[s / SQ];
                    s++;
                }
            }

            if (alls < y * sz) {
                for (int s = a; s <= b;) {
                    if (s % SQ == 0 && s + SQ - 1 <= b) {
                        delta[s / SQ] += z;
                        s += SQ;
                    } else {
                        zp[s] += z;
                        add[s / SQ] += z;
                        s++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << zp[nodes[i]->pointer] + delta[nodes[i]->pointer / SQ] << endl;
}
