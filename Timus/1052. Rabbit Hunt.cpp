#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define eb emplace_back
#define pb push_back
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define mem0(m) memset((m), 0, sizeof(m));
#define mem0d(m) memset((m), 0.0, sizeof(m));
#define memb(m) memset((m), false, sizeof(m));
typedef unsigned int uint;
typedef long long int ll;
typedef long double ld;



int main() {
    int n;
    cin >> n;
    pdd a[205];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int z = i + 1; z < n; z++) {
            double x = a[z].first - a[i].first,
                    y = a[z].second - a[i].second;
            y /= x;
            int cnt = 2;
            for(int k = 0; k < n; k++) {
                if(k == i || k == z) continue;
                double xx = a[k].first - a[i].first,
                        yy = a[k].second - a[i].second;
                yy /= xx;
                if(y == yy) {
                    cnt++;
                }
            }

            ans = max(ans, cnt);
        }
    }

    cout << ans;
}















