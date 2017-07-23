// The solution of the problem was written by Izaron
// Date: 21:49:31   21 May 2016
// Execution time: 0.858

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <vector>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int, int> tt;

const int N = 1000 + 5;
const ld EPS = 0.0000001;



bool can = false;
ll xxx1, yyy1, xxx2, yyy2;
ll ggg;

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, Y1;
    ll d = gcd (b%a, a, x1, Y1);
    x = Y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution (ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
    g = gcd (abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)   x0 *= -1;
    if (b < 0)   y0 *= -1;
    return true;
}

bool isTrue(ld x, ld y) {
    if (floor(x) != x)
        return false;
    if (floor(y) != y)
        return false;
    return true;
}

void work(ll d1, ll d2, ll d3) {
    if (can)
        return;

    for (ll X1 = -d1; X1 < 0; X1++) {
        ld Y1tmp = sqrt(d1 * d1 - X1 * X1);
        if (floor(Y1tmp) != Y1tmp)
            continue;
        ll Y1 = (ll)Y1tmp;


        ld r, a, b, c;
        r = d3;
        a = -2 * X1;
        b = -2 * Y1;
        c = X1 * X1 + Y1 * Y1 + d3 * d3 - d2 * d2;
        ld x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);
        if (c*c > r*r*(a*a+b*b)+EPS) {
            continue;
        } else if (abs (c*c - r*r*(a*a+b*b)) < EPS) {
            if (isTrue(x0, y0)) {
                can = true;
                xxx1 = X1;
                yyy1 = Y1;
                xxx2 = (ll)x0;
                yyy2 = (ll)y0;
                return;
            }
        } else {
            double d = r*r - c*c/(a*a+b*b);
            double mult = sqrt (d / (a*a+b*b));
            double ax,ay,bx,by;
            ax = x0 + b * mult;
            bx = x0 - b * mult;
            ay = y0 - a * mult;
            by = y0 + a * mult;

            if (isTrue(ax, ay)) {
                can = true;
                xxx1 = X1;
                yyy1 = Y1;
                xxx2 = (ll)ax;
                yyy2 = (ll)ay;
                return;
            }

            if (isTrue(bx, by)) {
                can = true;
                xxx1 = X1;
                yyy1 = Y1;
                xxx2 = (ll)bx;
                yyy2 = (ll)by;
                return;
            }
        }
    }
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    work(a, b, c);
    work(a, c, b);
    work(b, a, c);
    work(b, c, a);
    work(c, a, b);
    work(c, b, a);

    if (!can) {
        cout << -1;
    } else {
        cout << "0 0\n";
        cout << xxx1 << " " << yyy1 << endl;
        cout << xxx2 << " " << yyy2 << endl;
    }
}
