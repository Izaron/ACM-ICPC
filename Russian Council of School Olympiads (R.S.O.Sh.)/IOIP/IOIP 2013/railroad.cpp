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
 
 
 
 
 
const int N = 50005;
const int M = 150005;
 
vector<pii> g[N];
int ans[M];
bool used[M];
 
int curr = 1;
void dfs(int v) {
    for(auto it : g[v]) {
        if(used[it.second])
            continue;
        used[it.second] = true;
        int b = it.first;
        int num = it.second;
        ans[num] = curr;
        curr++;
        dfs(b);
    }
}
 
int main() {

#ifdef ONLINE_JUDGE
    freopen("railroad.in", "r", stdin);
    freopen("railroad.out", "w", stdout);
#endif // ONLINE_JUDGE

    fill(used, used + M, false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(mkp(b, i));
        g[b].pb(mkp(a, i));
    }
 
    int cnt = 0;
    int v = 0;
    for(int i = 0; i < n; i++) {
        if(g[i].size() == 1) {
            cnt++;
            v = i;
        }
    }
 
    if(cnt >= 2) {
        cout << "IMPOSSIBLE";
        return 0;
    }
 
    dfs(v);
 
    for(int i = 0; i < m; i++)
        cout << ans[i] << endl;
}






