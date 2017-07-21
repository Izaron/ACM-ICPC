#include <bits/stdc++.h>
using namespace std;

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







const int N = 100000 + 5;

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);

    int n;
    cin >> n;
    ll ms[N];
    for(int i = 0; i < n; i++)
        cin >> ms[i];
    multiset<ll> st;
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        if(st.find(i) != st.end())
            st.erase(i);
        ans += ms[i] * (ll)st.size();
        if(ms[i] > 0)
            st.insert(i + ms[i]);
    }
    cout << ans;
}

