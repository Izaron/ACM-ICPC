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





const int N = 2 * 100000 + 5;
const ll MOD = 1000000007;
const int M = 101;

int main() {
    #ifdef ONLINE_JUDGE
        freopen("onlyone.in", "r", stdin);
        freopen("onlyone.out", "w", stdout);
    #endif // ONLINE_JUDGE

    int ms[M][M][M];
    memset(ms, 0, sizeof(ms));

    int n;
    cin >> n;

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ans += ms[a][0][0];
        ans += ms[0][b][0];
        ans += ms[0][0][c];
        ans -= 2 * ms[a][b][0];
        ans -= 2 * ms[0][b][c];
        ans -= 2 * ms[a][0][c];
        ans += 3 * ms[a][b][c];
        ms[a][0][0]++;
        ms[0][b][0]++;
        ms[0][0][c]++;
        ms[a][b][0]++;
        ms[0][b][c]++;
        ms[a][0][c]++;
        ms[a][b][c]++;
    }

    cout << ans;
}
