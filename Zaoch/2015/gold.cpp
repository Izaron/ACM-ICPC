#include <bits/stdc++.h>
using namespace std;

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



ll n, k, c, d;
vector<pii> l;
vector<ll> zd;

int main() {
    cin >> n >> k >> c >> d;
    ll plus = 0;

    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        plus += (y - x) * d;
        l.pb(mkp(x,y));
    }

    for(int i = 1; i < n; i++)
        zd.pb(l[i].first - l[i - 1].second);

    ll bigg = 0;
    ll tmp = 0;

    for(int i = 0; i < zd.size(); i++) {
        zd[i] *= d;
        bigg += zd[i];
    }
    tmp = bigg;
    sort(zd.begin(), zd.end());
    reverse(zd.begin(), zd.end());

    int lamps = 1, kk = k - 1;
    ll ans = bigg;
    for(int i = 0; i < zd.size(); i++) {
        kk--;
        if(kk < 0) {
            lamps++;
            kk = k - 1;
        }
        tmp -= zd[i];
        ans = min(ans, tmp + c * lamps - c);
    }

    cout << plus + ans;
}

