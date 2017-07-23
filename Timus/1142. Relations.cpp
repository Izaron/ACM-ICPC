// The solution of the problem was written by Izaron
// Date: 19:20:29   12 May 2015
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
    int m[] = { 1, 1, 3, 13, 75, 541, 4683, 47293, 545835, 7087261, 102247563 };
    int n;
    while(cin >> n) {
        if(n == -1) break;
        cout << m[n] << endl;
    }
}






















