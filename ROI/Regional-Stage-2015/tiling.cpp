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





const int N = 100000 + 5;
const ll MOD = 1000000007;



int n;

ll ank[N][2][2];
int trabla[N][2];

ll gett(int v, int a, int b) {
    if(v == n) {
        return (a == 0 && b == 0);
    }

    if(a == 1 && trabla[v][0] == 1) {
        return 0;
    }

    if(b == 1 && trabla[v][1] == 1) {
        return 0;
    }

    a = max(a, trabla[v][0]);
    b = max(b, trabla[v][1]);

    if(ank[v][a][b] != -1)
        return ank[v][a][b];

    // 1 - est, 0 - netu
    ll ans = 0;
    if(a == 0 && b == 1) {
        ans += gett(v + 1, 0, 0);
        ans += gett(v + 1, 1, 0);
    } else if(a == 1 && b == 0) {
        ans += gett(v + 1, 0, 0);
        ans += gett(v + 1, 0, 1);
    } else if(a == 0 && b == 0) {
        ans += gett(v + 1, 0, 0);
        ans += gett(v + 1, 0, 0);
        ans += gett(v + 1, 1, 0);
        ans += gett(v + 1, 0, 1);
        ans += gett(v + 1, 1, 1);
    } else {
        ans += gett(v + 1, 0, 0);
    }

    ank[v][a][b] = ans % MOD;
    return ank[v][a][b];
}

int main() {
    #ifdef ONLINE_JUDGE
        freopen("tiling.in", "r", stdin);
        freopen("tiling.out", "w", stdout);
    #endif // ONLINE_JUDGE

    memset(ank, -1, sizeof(ank));
    memset(trabla, 0, sizeof(trabla));

    int k;
    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        trabla[x][y] = 1;
    }

    cout << gett(0, 0, 0);
}
 
