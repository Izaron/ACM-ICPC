#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
 
const int maxk = 22 / 2;
 
int n, v;
vector<pii> bounds;
vector<int> cost;
vector<int> prec;
 
struct tree {
    int n;
    vector<pii> t[maxk];
 
    void build() {
        for (int i = 0; i < maxk; i++)
            t[i].resize(n, { INT_MAX, INT_MAX });
    }

    pii calc_real(int pos, int pow) {
        pii res = { INT_MAX, INT_MAX };

        for (int i = 0; i < 4; i++) {
            if (pos < n) {
                res = min(res, t[pow - 1][pos]);
                pos += (1 << (pow * 2 - 2));
            }
        }

        return res;
    }
 
    void add(int pos, pii val) {
        t[0][pos] = val;
        for (int i = 1; i < maxk; i++)
            if (pos - (1 << (2 * i)) + 1 >= 0)
                t[i][pos - (1 << (2 * i)) + 1] = calc_real(pos - (1 << (2 * i)) + 1, i);
                //t[i][pos - (1 << i) + 1] = min(t[i - 1][pos - (1 << i) + 1], t[i - 1][pos - (1 << (i - 1)) + 1]);
            else
                break;
    }
 
    void init(int n) {
        this->n = n;
        build();
    }
 
    void change(int pos, pii val) {
        val.first += n - 1 - pos;
        add(pos, val);
    }
 
    pii get(int v, int l, int r) {
        /*
        pii kek = { INT_MAX, INT_MAX };
        for (int i = l; i <= r; i++)
            kek = min(kek, t[0][i]);
        return kek;
        */

        int pow = prec[v];
        //cerr << "l = " << l << " r = " << r << " pow = " << pow << endl;
        if (pow % 2 == 1)
            pow--;

        if (l + (1 << pow) - 1 < r - (1 << pow) + 1)
            return min( t[pow / 2][l], get(v, l + (1 << pow), r));
        else {
            return min(
                t[pow / 2][l],
                t[pow / 2][r - (1 << pow) + 1]
            );
        }
    }
} t;
 
pii pr;
 
void dp(int a) {
    pr = { 0, 0 };
    for (int b = 0; b < n; b++) {
        if (a >= bounds[b].second) {
            pii pdd = t.get(b, a - bounds[b].second, a - bounds[b].first);
            pdd.first -= v - a;
            pdd.second -= cost[b];
            pr = max(pr, pdd);
        }
    }
 
    t.change(a, pr);
}
 
int main() {
    freopen("anti.in", "r", stdin);
    freopen("anti.out", "w", stdout);
 
    scanf("%d%d", &n, &v);
    t.init(v + 1);
    for (int i = 0; i < n; i++) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        bounds.push_back({l, r});
        cost.push_back(c);
    }

    prec.resize(n);
    for (int i = 0; i < n; i++) {
        int pow = 0;
        while ((1 << (pow + 1)) <= (bounds[i].second - bounds[i].first))
            pow++;
        prec[i] = pow;
    }
 
    for (int i = 0; i <= v; i++)
        dp(i);
    ll ank = pr.first;
    ank *= 1000000000LL;
    ank += pr.second;
    printf("%lld\n", ank);
}
