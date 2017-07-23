// The solution of the problem was written by Izaron
// Date: 20:21:12   12 Aug 2015
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define pss pair<int,int>
#define pdd pair<double,double>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define ff first
#define ss second
typedef long long int ll;
typedef long double ld;





const int N = 2 * 10000 + 5;

int main() {
    //freopen("ragnarok.in", "r", stdin);
    //freopen("ragnarok.out", "w", stdout);

    string s;
    cin >> s;
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    tmp += "#";
    tmp += s;
    int n = tmp.size();
    int z[N];
    fill(z, z + N, 0);
    int heh = 0;
    for(int i = 1, l = 0, r = 0; i < n; i++) {
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && tmp[z[i]] == tmp[i + z[i]])
            z[i]++;
        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
        if(i > s.size() + 1 && z[i] + i == n)
            heh = max(heh, z[i]);
    }
    cout << s;
    for(int z = s.size() - heh - 1; z >= 0; z--)
        cout << s[z];
}


