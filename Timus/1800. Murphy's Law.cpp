// The solution of the problem was written by Izaron
// Date: 16:40:34   14 May 2015
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





#define forn(i,n) for (int i = 0; i < (int)(n); i++)
typedef long double ld;
ld g = 9.81l;
int main() {
    ld l, h, w;
    cin >> l >> h >> w;
    l /= 100, h /= 100, w *= acosl(0) / 15;
    ld t = 0;
    forn (i, 1000) {
        ld d = fabsl(sinl(w * t) * l / 2);
        //g x^2 /2 + (x-t)wl/2 + d = h
        //x^2 g/2 + x wl/2 - wlt/2+d-h = 0
        t = (-w * l / 2 + sqrtl(w * w * l * l / 4 + 2 * g * (w * l * t / 2 - d + h))) / g;
    }
    cout << ((cosl(w * t) > 0) ? "butter": "bread");
}





















