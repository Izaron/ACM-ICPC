// The solution of the problem was written by Izaron
// Date: 17:07:47   22 May 2015
// Execution time: 0.64

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
typedef unsigned int uint;
typedef long long int ll;
typedef long double ld;



int main() {
    int n;
    uint t;
    priority_queue<uint> q;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%u", &t);
        q.push(t);
        if(i > n / 2) q.pop();
    }
    ll d = q.top();
    q.pop();
    if(n % 2 == 0) {
        d += q.top();
        if(d % 2 == 0) {
            cout << d / 2 << ".0";
        } else {
            cout << d / 2 << ".5";
        }
    } else {
        cout << d << ".0";
    }
}















