// The solution of the problem was written by Izaron
// Date: 19:40:02   12 May 2015
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
    int a;
    double b;
    cin >> a >> b;
    if(a == 1)
        b *= 2;
    else if(a == 2)
        b *= sqrt(2);

    int n;
    cin >> n;

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int x;
        double y;
        cin >> x >> y;
        if(x == 1)
            y *= 2;
        else if(x == 3)
            y = y * sqrt(3) / 2;

        if(b >= y) cnt++;
    }

    cout << cnt;
}






















