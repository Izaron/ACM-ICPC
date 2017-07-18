#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define mt make_tuple
#define mkp make_pair
#define eb emplace_back
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define pii pair<ll,ll>
#define pss pair<int,int>
#define pdd pair<double,double>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define mem0(m) memset((m), 0, sizeof(m));
#define mem0d(m) memset((m), 0.0, sizeof(m));
#define memb(m) memset((m), false, sizeof(m));
#define For(i,st,n) for(int (i) = (st); (i) < (n); (i)++)
#define rof(i,st,n) for(int (i) = (st); (i) > (n); (i)--)
#define rep(i,st) for(auto &(i) : (st))
typedef long long int ll;
typedef long double ld;
 
 
 
template <typename T> using ordered_set = tree<T, null_type,
    less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main() {
    freopen("river.in", "r", stdin);
    freopen("river.out", "w", stdout);
 
    int n, p;
    scanf("%d%d", &n, &p);
    ll ans = 0;
    ll sum = 0;
    ordered_set<pii> st;
    for(int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        st.insert(mkp(sum, tmp));
        ans += tmp * tmp;
        sum += tmp;
    }
    int k;
    scanf("%d", &k);
    ll anses[100005];
    int ns = 0;
    anses[ns] = ans;
    ns++;
    int curr = n;
    while(k--) {
        int e, v;
        scanf("%d%d", &e, &v);
        v--;
        if(e == 1) {
            if(v == 0) {
                pii a = *st.find_by_order(0);
                pii b = *st.find_by_order(1);
                ans -= a.second * a.second;
                ans -= b.second * b.second;
                pii p = mkp(a.first, a.second + b.second);
                ans += p.second * p.second;
                st.erase(a);
                st.erase(b);
                st.insert(p);
 
                curr--;
            } else if(v == curr - 1) {
                pii a = *st.find_by_order(curr - 2);
                pii b = *st.find_by_order(curr - 1);
                ans -= a.second * a.second;
                ans -= b.second * b.second;
                pii p = mkp(a.first, a.second + b.second);
                ans += p.second * p.second;
                st.erase(a);
                st.erase(b);
                st.insert(p);
                curr--;
            } else {
                pii a = *st.find_by_order(v - 1);
                pii b = *st.find_by_order(v);
                pii c = *st.find_by_order(v + 1);
 
                ans -= a.second * a.second;
                ans -= b.second * b.second;
                ans -= c.second * c.second;
 
                ll lft = b.second / 2;
                ll rgt = b.second - lft;
 
                pii aa = mkp(a.first, a.second + lft);
                pii bb = mkp(c.first - rgt, c.second + rgt);
 
                ans += aa.second * aa.second;
                ans += bb.second * bb.second;
 
                st.erase(a);
                st.erase(b);
                st.erase(c);
                st.insert(aa);
                st.insert(bb);
 
                curr--;
            }
        } else {
            // razval
            pii p = *st.find_by_order(v);
            ans -= p.second * p.second;
            pii a, b;
            ll lft = p.second / 2;
            ll rgt = p.second - lft;
            a = mkp(p.first, lft);
            b = mkp(p.first + p.second - rgt, rgt);
            ans += lft * lft;
            ans += rgt * rgt;
            st.erase(p);
            st.insert(a);
            st.insert(b);
 
            curr++;
        }
 
 
        //for(int z = 0; z < curr; z++)
        //    cout << (*st.find_by_order(z)).second << " ";
        //cout << endl;
 
        anses[ns] = ans;
        ns++;
    }
 
    for(int i = 0; i < ns; i++) {
        printf("%I64d\n", anses[i]);
    }
} 
