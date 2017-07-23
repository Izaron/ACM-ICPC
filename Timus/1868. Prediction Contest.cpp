// The solution of the problem was written by Izaron
// Date: 20:50:05   2 May 2015
// Execution time: 0.046

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
    map<string, string> mp;
    for(int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        mp[s] = "gold";
    }
    for(int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        mp[s] = "silver";
    }
    for(int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        mp[s] = "bronze";
    }

    int maxi = 0, ans = 0;
    int k;
    cin >> k;

    for(int i = 0; i < k; i++) {
        int n;
        cin >> n;
        int curr = 0;
        for(int z = 0; z < n; z++) {
            string a, b, c;
            cin >> a >> b >> c;
            if(mp[a] == c) curr++;
        }
        if(curr > maxi) {
            ans = 1;
            maxi = curr;
        } else if(curr == maxi) {
            ans++;
        }
    }

    cout << ans * 5;
}




























