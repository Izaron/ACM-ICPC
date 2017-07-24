// The solution of the problem was written by Izaron
// Date: 22:57:05   5 May 2015
// Execution time: 0.328

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



int main() {
    int n;
    scanf("%d", &n);

    pii m[100005];
    int a[40000];
    mem0(a);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &m[i].first, &m[i].second);
    }

    sort(m, m + n);

    a[m[n - 1].first] = 1;
    int cost = m[n - 1].first, maxi = 1;

    for(int i = n - 2; i >= 0; i--) {
        for(int z = cost; z >= m[i].first; z--) {
            a[z] = maxi;
        }
        cost = min((int)m[i].first, cost);
        a[m[i].first] = a[m[i].second + 1] + 1;
        maxi = max(maxi, a[m[i].first]);
    }

    printf("%d", maxi);
}



















