// The solution of the problem was written by Izaron
// Date: 22:03:37   1 May 2015
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;

#define pii pair<ll,ll>
#define pdd pair<double,double>
#define mkp(a,b) make_pair((a),(b))
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define mem0(m) memset((m), 0, sizeof(m));
#define memb(m) memset((m), false, sizeof(m));
typedef long long int ll;
typedef long double ld;




int main() {
    int b, r, y;
    cin >> b >> r >> y;
    int k;
    cin >> k;
    int ans = 1;
    for(int i = 0; i < k; i++) {
        string s;
        cin >> s;
        if(s == "Red") ans *= r;
        if(s == "Blue") ans *= b;
        if(s == "Yellow") ans *= y;
    }
    cout << ans;
}












