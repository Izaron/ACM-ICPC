// The solution of the problem was written by Izaron
// Date: 20:46:03   6 May 2015
// Execution time: 0.125

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
#define memb(m) memset((m), false, sizeof(m));
typedef long long int ll;
typedef long double ld;




int main() {
    int m[105][105], sum[105][105];
    mem0(m);
    mem0(sum);
    int n;

    cin >> n;
    int maxi = -1000000000;

    for(int i = 1; i <= n; i++) {
        for(int z = 1; z <= n; z++) {
            cin >> m[i][z];
            maxi = max(maxi, m[i][z]);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int z = 1; z <= n; z++) {
            for(int x = 1; x <= i; x++) {
                for(int y = 1; y <= z; y++) {
                    sum[i][z] += m[x][y];
                }
            }
            maxi = max(maxi, sum[i][z]);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int z = 1; z <= n; z++) {
            for(int x = 1; x <= i; x++) {
                for(int y = 1; y <= z; y++) {
                    int cnt = sum[i][y - 1] + sum[x - 1][z] - sum[x - 1][y - 1];
                    cnt = sum[i][z] - cnt;
                    maxi = max(maxi, cnt);
                }
            }
        }
    }

    cout << maxi;
}



















