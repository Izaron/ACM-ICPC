#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define mt make_tuple
#define mkp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define pss pair<int,int>
#define pdd pair<double,double>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define ff first
#define ss second
typedef long long int ll;
typedef long double ld;





const int N = 3 * 100000 + 5;


template<typename T> using ordered_set = tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

typedef tuple<ll, ll, pii, pii> info;

int main() {
    #ifdef ONLINE_JUDGE
        freopen("split.in", "r", stdin);
        freopen("split.out", "w", stdout);
    #endif // ONLINE_JUDGE

    ordered_set<pii> ms;
    set<info> st;
    int ish[N];

    int n;
    scanf("%d", &n);
    for(int i = 0; i < 2 * n; i++) {
        int tmp;
        scanf("%d", &tmp);
        ish[i] = tmp;
    }

    sort(ish, ish + 2 * n);

    for(int i = 0; i < 2 * n; i++) {
        int tmp = ish[i];
        ms.insert(mkp(i, tmp));
        if(i) {
            st.insert(mt( ish[i] - ish[i - 1], - ish[i] - ish[i - 1],
                mkp(i - 1, ish[i - 1]), mkp(i, ish[i]) ));
        }
    }

    vector<int> a, b;

    while(st.size() > 0) {
        info t = (*st.begin());
        st.erase(st.begin());
        pii ap = get<2>(t), bp = get<3>(t);
        a.pb(ap.ss);
        b.pb(bp.ss);

        int kek = ms.order_of_key(ap);
        int kek2 = ms.order_of_key(bp);

        if(kek - 1 >= 0) {
            pii tmp = (*ms.find_by_order(kek - 1));
            int ia = tmp.ff;
            int ib = ap.ff;
            st.erase(mt( ish[ib] - ish[ia], - ish[ib] - ish[ia],
                tmp, ap ));
        }

        if(kek2 + 1 < ms.size()) {
            pii tmp = (*ms.find_by_order(kek2 + 1));
            int ib = tmp.ff;
            int ia = bp.ff;
            st.erase(mt( ish[ib] - ish[ia], - ish[ib] - ish[ia],
                bp, tmp ));
        }

        if(kek - 1 >= 0 && kek2 + 1 < ms.size()) {
            pii ib = (*ms.find_by_order(kek2 + 1));
            pii ia = (*ms.find_by_order(kek - 1));
            st.insert(mt( ib.ss - ia.ss, -ib.ss - ia.ss,
                ia, ib ));
        }

        ms.erase(ap);
        ms.erase(bp);
    }

    for(auto it : b)
        printf("%d ", it);
    printf("\n");
    for(auto it : a)
        printf("%d ", it);
}










