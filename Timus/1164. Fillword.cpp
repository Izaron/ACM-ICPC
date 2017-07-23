// The solution of the problem was written by Izaron
// Date: 23:41:48   15 May 2015
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
    map<char, int> mp;
    int n, m, p;
    cin >> n >> m >> p;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(auto ch: s) {
            mp[ch]++;
        }
    }

    for(int i = 0; i < p; i++) {
        string s;
        cin >> s;
        for(auto ch: s) {
            mp[ch]--;
        }
    }

    for(int i = (int)('A'); i <= (int)('Z'); i++) {
        for(int z = 0; z < mp[(char)(i)]; z++) {
            cout << (char)(i);
        }
    }
}





















