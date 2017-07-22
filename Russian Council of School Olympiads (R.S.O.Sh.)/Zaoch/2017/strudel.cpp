#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#ifdef USE_CERR
#define CERR(a) cerr << a << endl
#else
#define CERR(a)
#endif

template<typename T> using ordered_set = tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

int n;
ll m;
vector<pll> vec;

ll calc(ll v, ll f, ll s) {
    ll l = v, r = v + (s - f) / 2 + 1;
    while (l != r) {
        ll la = l, lb = r;
        ll mid = (l + r) / 2;
        if (mid - (min(mid, s) - f) / 2 - 1 >= v)
            r = mid;
        else
            l = mid;
        if (la == l && lb == r) {
            if (l - (min(l, s) - f) / 2 - 1 >= v)
                r = l;
            else
                l = r;
        }
    }
    return l;
}

ll go(ll v) {
    for (int i = vec.size() - 1; i >= 0; i--) {
        if (vec[i].first > v)
            continue;
        v = calc(v, vec[i].first, vec[i].second);
    }
    return v;
}

void solve1() {
    ordered_set<int> st;
    int l, r;
    for (int i = 0; i < m; i++)
        st.insert(i + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        printf("%d %d\n", (*st.find_by_order(l - 1)), (*st.find_by_order(r - 1)));
        for (int z = r - 1; z >= l - 1; z -= 2) {
            st.erase((*st.find_by_order(z)));
        }
    }
}

void solve2() {
    ll a, b;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a, &b);
        printf("%lld %lld\n", go(a), go(b));
        vec.push_back({ a, b });
    }
}

int main() {
    scanf("%d%lld", &n, &m);

    if (m <= 1000000) {
        solve1();
    } else {
        solve2();
    }
}
