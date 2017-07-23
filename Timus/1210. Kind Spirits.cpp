// The solution of the problem was written by Izaron
// Date: 19:56:36   12 May 2015
// Execution time: 0.156

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

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


int n;
vector<pii> g[35][35];
ll ans[35];
ll ansid[35][35];
ll ansed = 1000000000000;

void dfs(int level, int v, ll cost) {
    ansid[level][v] = cost;

    if(level == n) {
        ans[v] = min(ans[v], cost);
        ansed = min(ansed, ans[v]);
    }
    for(auto it: g[level][v]) {
        if(ansid[level + 1][it.first] > cost + it.second) {
            dfs(level + 1, it.first, cost + it.second);
        }
    }
}

int main() {
    for(int i = 0; i < 35; i++) {
        ans[i] = 1000000000000;
        for(int z = 0; z < 35; z++) {
            ansid[i][z] = 1000000000000;
        }
    }

    cin >> n;

    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;

        for(int z = 0; z < k; z++) {
            int a, b;
            while(cin >> a) {
                if(a == 0) break;
                cin >> b;
                a--;
                g[i - 1][a].pb(mkp(z, b));
            }
        }

        if(i != n) {
            string s;
            cin >> s;
        }
    }

    dfs(0, 0, 0);

    cout << ansed;
}






















