// The solution of the problem was written by Izaron
// Date: 22:55:02   16 Oct 2015
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define pb push_back
#define pii pair<short, short>
#define pss pair<string,string>
#define pdd pair<ld,ld>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define ff first
#define ss second
typedef long long int ll;
typedef long double ld;



const int N = 100000 + 5;


int main() {
    int n;
    cin >> n;
    map<string, pii> mp;
    while(n--) {
        string user, res;
        cin >> user >> res;
        if(res == "AC") {
            mp[user].ss = 1;
        }
        if(res == "CE") {
            continue;
        }
        if(res == "ML" || res == "TL" || res == "WA") {
            int src;
            cin >> src;
            if(src == 6)
                mp[user].ss = 1;
            else if(src == 7) {
                mp[user].ff = 1;
                mp[user].ss = 1;
            } else {
                continue;
            }
        }
    }

    int a = 0, b = 0;
    for(auto it : mp) {
        a += it.ss.ff;
        b += it.ss.ss;
    }

    cout << a << " " << b;
}



