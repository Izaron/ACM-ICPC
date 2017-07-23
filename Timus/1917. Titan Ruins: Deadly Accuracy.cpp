// The solution of the problem was written by Izaron
// Date: 22:35:27   11 May 2015
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
    ll p;
    cin >> n >> p;

    ll ms[1000005];
    mem0(ms);

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        ms[tmp]++;
    }

    ll curr = 0, a = 0, b = 0;
    for(int i = 0; i < 1000005; i++) {
        if((curr + ms[i]) * i <= p) {
            curr += ms[i];
            a += ms[i];
        } else {
            if(curr == 0) break;
            b++;
            curr = 0;
            i--;
        }
    }

    if(curr != 0) {
        b++;
    }

    cout << a << " " << b;
}






















