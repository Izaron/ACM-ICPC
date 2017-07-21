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
typedef unsigned long long int ll;
typedef long double ld;







const int N = 100000 + 5;
const int M = sqrt(N) + 1;

typedef tuple<ll, ll, ll> tt;

int main() {
    freopen("cakes.in", "r", stdin);
    freopen("cakes.out", "w", stdout);

    int n;
    ll t;
    cin >> n >> t;

    pii ms[N];

    for(int i = 0; i < n; i++)
        cin >> ms[i].ff >> ms[i].ss;
    sort(ms, ms + n);
    tt tm[N];
    for(int i = 0; i < n; i++)
        tm[i] = mt(ms[i].ss, ms[i].ff, i);
    sort(tm, tm + n);
    int pos[N];
    for(int i = 0; i < n; i++)
        pos[get<2>(tm[i])] = i;

    ll a[N];
    pii sq[M];  // stoim - size

    fill(a, a + N, 0);

    int ans = 0;

    for(int i = 0; i < n; i++) {    // i-oe vsegda s'est
        int nt = t - ms[i].ff - ms[i].ss;
        if(nt < 0) {
            // end...
            int pp = pos[i];
            sq[pp / M].ff += ms[i].ss;
            sq[pp / M].ss++;
            a[pp] = ms[i].ss;
            continue;
        }
        int curr = 1;
        for(int z = 0; z < M; z++) {
            if(nt >= sq[z].ff) {
                curr += sq[z].ss;
                nt -= sq[z].ff;
            } else for(int k = z * M; ; k++) {
                if(nt >= a[k]) {
                    if(a[k] > 0)
                        curr += 1;
                    nt -= a[k];
                } else {
                    break;
                }
            }
        }
        ans = max(ans, curr);
        // end...
        int pp = pos[i];
        sq[pp / M].ff += ms[i].ss;
        sq[pp / M].ss++;
        a[pp] = ms[i].ss;
    }

    cout << ans;
}