// The solution of the problem was written by Izaron
// Date: 18:57:50   13 May 2015
// Execution time: 0.281

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





int main() {
    int n;
    cin >> n;
    int m[100005];
    mem0(m);
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        int a = (i + 1) - tmp;
        if(a < 0) a = n + a;
        a++;
        m[a]++;
    }

    int maxi = 0;
    for(int i = 1; i < 100005; i++) {
        if(m[i] > m[maxi]) {
            maxi = i;
        }
    }

    cout << maxi;
}






















