// The solution of the problem was written by Izaron
// Date: 16:44:07   14 May 2015
// Execution time: 0.031

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

    double x = 0.228, y = 1.488;
    double ans = 0;

    for(int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        double dist = pow(a - x, 2) + pow(b - y, 2);
        if(dist > ans) {
            ans = dist;
        }
    }

    cout << fixed << setprecision(12) << x << " " << y << " " << sqrt(ans);
}





















