// The solution of the problem was written by Izaron
// Date: 15:42:18   11 May 2015
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
    map<int, string> m;
    string s, ans = "";
    int curr = 0;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
            int mp = curr * 3;
            if(s[i] == '(') mp++;
            if(s[i] == '[') mp += 2;

            string kek = "";
            i++;
            while(s[i] != '}' && s[i] != ')' && s[i] != ']') {
                kek += s[i];
                i++;
            }
            ans += "?";

            if(m.count(mp)) {
                curr++;
                mp += 3;
            }

            m[mp] = kek;
        } else {
            ans += s[i];
        }
    }

    int k = 0;
    string ank = "";

    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] == '?') {
            ank += m[k];
            k++;
        } else {
            ank += ans[i];
        }
    }

    for(int i = 0; i < ank.size(); i++) {
        if(i == 0) {
            cout << (char)toupper(ank[i]);
        } else {
            cout << (char)tolower(ank[i]);
        }
    }
}
























