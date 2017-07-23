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
typedef long long int ll;
typedef long double ld;




vector<int> g[1005];
bool used[1005];

int main() {
    memb(used);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[b].pb(a);
    }

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        for(auto it: g[a]) {
            if(!used[it]) {
                cout << "NO";
                return 0;
            }
        }
        used[a] = true;
    }

    cout << "YES";
}





















