#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;

int n;
vector<pii> vec;
map<pii, int> mpi;

ll squar(pii a, pii b, pii c) {
    ll res = a.first * (b.second - c.second) +
             b.first * (c.second - a.second) +
             c.first * (a.second - b.second);
    return res;
}

ll sqAbs(pii a, pii b, pii c) {
    return abs(squar(a, b, c));
}

vector<pii> convex_hull(vector<pii> p) {
    sort(p.begin(), p.end());
    int n = p.size();

    vector<pii> h(2 * n);
    int cnt = 0;
    for (int i = 0; i < n; h[cnt++] = p[i++])
        while (cnt > 1 && squar(h[cnt - 2], h[cnt - 1], p[i]) >= 0)
            cnt--;
    for (int i = n - 2, t = cnt; i >= 0; h[cnt++] = p[i--])
        while (cnt > t && squar(h[cnt - 2], h[cnt - 1], p[i]) >= 0)
            cnt--;

    int len = cnt - 1 - (h[0].first == h[1].first && h[0].second == h[1].second ? 1 : 0);
    while (h.size() > len)
        h.pop_back();
    return h;
}

bool tiger_in(vector<pii> & vec, int a, int b) {
    cout << "? " << b - a + 1 << " ";
    for (int i = a; i <= b; i++)
        cout << mpi[vec[i]] + 1 << " ";
    cout << endl;
    string s;
    cin >> s;
    return s == "Yes";
}

bool tiger_in(pii a, pii b, pii c) {
    vector<pii> vec = { a, b, c };
    return tiger_in(vec, 0, 2);
}

void tiger_ans(pii a, pii b, pii c) {
    cout << "! 3 " << mpi[a] + 1 << " " << mpi[b] + 1 << " " << mpi[c] + 1 << endl;
}

bool is_in(pii a, pii b, pii c, pii n) {
    return sqAbs(a, b, c) ==
                sqAbs(a, b, n) + sqAbs(a, n, c) + sqAbs(n, b, c);
}

vector<pii> hull;
vector<int> shrek;

void find2() {
    if (hull.size() == 0)
        hull = convex_hull(vec);
    int a = 0, b = 1, c;

    int l = 2, r = hull.size() - 1;
    while (l != r) {
        int la = l, lb = r;
        int mid = (l + r) / 2;
        if (tiger_in(hull, 0, mid))
            r = mid;
        else
            l = mid;
        if (l == la && r == lb) {
            if (tiger_in(hull, 0, l))
                r = l;
            else
                l = r;
        }
    }
    c = l;
    b = c - 1;


    pii pa = hull[a], pb = hull[b], pc = hull[c];

    if (shrek.size() == 0) {
        for (int i = 0; i < n; i++)
            shrek.push_back(i);
        srand(228);
        random_shuffle(shrek.begin(), shrek.end());
    }

    for (int i = 0; i < n; i++) {
        pii pn = vec[shrek[i]];
        if (pn == pa || pn == pb || pn == pc)
            continue;
        if (!is_in(pa, pb, pc, pn))
            continue;
        if (tiger_in(pa, pb, pn))
            pc = pn;
        else if (tiger_in(pa, pn, pc))
            pb = pn;
        else
            pa = pn;
    }

    tiger_ans(pa, pb, pc);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
        mpi[vec[i]] = i;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
        find2();
}
