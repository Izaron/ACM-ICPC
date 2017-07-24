// The solution of the problem was written by Izaron
// Date: 15:01:45   11 May 2015
// Execution time: 0.015

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
    double v, a, k;
    cin >> v >> a >> k;

    double l = 0.0;
    while(v > 0.00000001) {
        l += v * v * sin(2.0 * a * 3.1415926535 / 180.0) / 10.0;
        v /= sqrt(k);
    }

    cout << fixed << setprecision(2) << l;
}
























