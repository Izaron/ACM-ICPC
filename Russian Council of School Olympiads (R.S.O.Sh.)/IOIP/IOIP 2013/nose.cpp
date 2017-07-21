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





const int N = 1000 + 5;


int main() {
    #ifdef ONLINE_JUDGE
        freopen("nose.in", "r", stdin);
        freopen("nose.out", "w", stdout);
    #endif // ONLINE_JUDGE

    int n, m;
    cin >> n >> m;
    string s[N];
    for(int i = 0; i < n; i++)
        cin >> s[i];

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int z = 0; z < m; z++) {
            if(i < n - 1 && s[i][z] == '.' && s[i + 1][z] == '.')
                ans++;
            if(z < m - 1 && s[i][z] == '.' && s[i][z + 1] == '.')
                ans++;
        }
    }

    cout << ans;
}





