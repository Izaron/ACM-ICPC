// The solution of the problem was written by Izaron
// Date: 21:08:38   19 Oct 2015
// Execution time: 0.031

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define pb push_back
#define pii pair<ll, ll>
#define pss pair<string,string>
#define pdd pair<ld,ld>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define ff first
#define ss second
typedef long long int ll;
typedef long double ld;



const int N = 1000 + 5;


int main() {
    int has[N][N];
    memset(has, 0, sizeof(has));

    int n;
    cin >> n;
    double ans = 0;

    for(int i = 0; i < n; i++) {
        double x, y, r;
        cin >> x >> y >> r;
        r *= r;
        int w = 0, e = 0;
        for(double xx = 0; xx <= 1.0; xx += 0.001) {
            e = 0;
            for(double yy = 0; yy <= 1.0; yy += 0.001) {
                if(has[w][e]) {
                    e++;
                    continue;
                }
                double dist = (xx - x) * (xx - x) + (yy - y) * (yy - y);
                if(dist <= r) {
                    has[w][e] = 1;
                    ans++;
                }
                e++;
            }
            w++;
        }
    }

    cout << fixed << setprecision(9) << ans / 10000;
}



