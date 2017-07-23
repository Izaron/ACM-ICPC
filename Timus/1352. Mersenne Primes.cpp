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
    int m[] = { 2,3,5,7,13,17,19,31,61,89,107,127,521,607,
                1279,2203,2281,3217,4253,4423,9689,9941,                   11213,19937,21701,23209,44497,86243,
                110503,132049,216091,756839,859433,
                1257787,1398269,2976221,3021377,6972593,
                13466917,20996011 };
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int cnt;
        cin >> cnt;
        cout << m[cnt - 1] << endl;
    }
}














