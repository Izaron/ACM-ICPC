#include <bits/stdc++.h>
using namespace std;
 
#define mt make_tuple
#define mkp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define pss pair<string,string>
#define pdd pair<ld,ld>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define ff first
#define ss second
typedef long long int ll;
typedef long double ld;
 
 
 
 
 
const int N = 2 * 1000000 + 5;
const ll MOD = 1000000007;
const int M = 101;
 
int main() {
    #ifdef ONLINE_JUDGE
        freopen("monument.in", "r", stdin);
        freopen("monument.out", "w", stdout);
    #endif // ONLINE_JUDGE
 
    ll n, k;
    cin >> n >> k;
 
    vector<ll> zn[N];
    ll plA[N];
    ll plB[N];
    fill(plA, plA + N, 0);
    fill(plB, plB + N, 0);
    vector<pii> vec;
 
    pii p;
    cin >> p.first >> p.second;
    pii tmp = p;
 
    for(ll i = 1; i <= n; i++) {
        pii np;
        if(i == n)
            np = tmp;
        else
            cin >> np.first >> np.second;
 
        if(np.second == p.second) {
            p = np;
            continue;
        }
 
        if(p.second > np.second) {
            for(int z = p.second; z > np.second; z--) {
                zn[z].pb(p.first);
            }
        } else {
            for(int z = np.second; z > p.second; z--) {
                zn[z].pb(p.first);
            }
        }
 
        p = np;
    }
 
    ll as = 0, bs = 0;
 
    for(ll i = 0; i < N; i++) {
        if(zn[i].size() == 0) continue;
        sort(zn[i].begin(), zn[i].end());
        zn[i][0]++;
        zn[i][0] += 2 * N;
        zn[i][1] += 2 * N;
        zn[i][0] -= i;
        zn[i][1] -= i;
        vec.pb(mkp(zn[i][0], zn[i][1]));
        as += zn[i][0] / k;
        bs += zn[i][1] / k;
    }
 
    ll mini = -1;
 
    for(ll i = 0; i < vec.size(); i++) {
        ll a = vec[i].ff;
        ll b = vec[i].ss;
 
        ll x = a % k;
        plA[k - x]++;
 
        x = b % k;
        plB[k - x]++;
    }
 
    for(ll i = -1; i <= k; i++) {
        if(i >= 0) {
            as += plA[i];
            bs += plB[i];
        }
        ll ans = bs - as;
        if(mini == -1)
            mini = ans;
        else
            mini = min(mini, ans);
    }
 
    /*for(int pl = 0; pl <= k; pl++) {
        int ans = 0;
        for(int i = 0; i < vec.size(); i++) {
            int a = vec[i].ff + pl, b = vec[i].ss + pl;
            ans += a / k - b / k;
        }
 
        if(mini == -1)
            mini = ans;
        else
            mini = min(mini, ans);
    }*/
 
    cout << mini + (ll)vec.size();
}