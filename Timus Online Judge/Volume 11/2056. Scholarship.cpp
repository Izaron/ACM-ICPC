// The solution of the problem was written by Izaron
// Date: 13:27:39   28 Jul 2017
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
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
    cin >> n;

    double sr = 0;
    bool troes = false, nonFives = false;

    for(int i = 0; i < n; i++) {
        double tmp;
        cin >> tmp;
        sr += tmp;
        if(tmp == 3) troes = true;
        if(tmp != 5) nonFives = true;
    }

    sr /= n;

    if(troes) {
        cout << "None";
    } else if(!nonFives) {
        cout << "Named";
    } else if(sr >= 4.5) {
        cout << "High";
    } else {
        cout << "Common";
    }
}




























