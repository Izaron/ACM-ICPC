// The solution of the problem was written by Izaron
// Date: 23:03:15   5 May 2015
// Execution time: 0.078

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
#include <sstream>
using namespace std;

#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define mem0(m) memset((m), 0, sizeof(m));
#define memb(m) memset((m), false, sizeof(m));
typedef long long int ll;
typedef long double ld;



ll m[505][505];

ll dfs(int n, int sz) {
    if(n < 0)
        return 0;

    if(m[n][sz] != -1)
        return m[n][sz];

    if(n == 0) {
        m[n][sz] = 1;
        return 1;
    }

    ll res = 0;
    for(int i = sz + 1; i <= n; i++) {
        res += dfs(n - i, i);
    }

    m[n][sz] = res;
    return res;
}

int main() {
    int n;
    for(int i = 0; i < 505; i++) {
        for(int z = 0; z < 505; z++) {
            m[i][z] = -1;
        }
    }
    scanf("%d", &n);
    printf("%I64d", dfs(n, 0) - 1);
}



















