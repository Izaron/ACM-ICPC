// The solution of the problem was written by Izaron
// Date: 21:22:45   19 Jul 2015
// Execution time: 0.327

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





const int N = 730000;

int main() {
    string s;
    getline(cin, s);
    int nado[N];
    fill(nado, nado + N, 0);
    int sz = 0;
    for(int i = 0; i < s.size(); i += 4) {
        sz++;
        int a = (int)(s[i] - 33);
        int b = (int)(s[i + 1] - 33);
        int c = (int)(s[i + 2] - 33);
        int code = a * 90 * 90 + b * 90 + c;
        nado[code]++;
    }
    int pohod = 0;
    int curr[N];
    fill(curr, curr + N, 0);
    for(int i = 0; i < N; i++) {
        if(curr[i] != nado[i])
            pohod++;
    }

    int num = 0;
    int codes[N];
    int ans = 0;
    getline(cin, s);
    for(int i = 0; i < s.size(); i += 4) {
        int a = (int)(s[i] - 33);
        int b = (int)(s[i + 1] - 33);
        int c = (int)(s[i + 2] - 33);
        int code = a * 90 * 90 + b * 90 + c;
        codes[num] = code;
        if(curr[code] == nado[code]) pohod++;
        curr[code]++;
        if(curr[code] == nado[code]) pohod--;
        if(num - sz >= 0) {
            code = codes[num - sz];
            if(curr[code] == nado[code]) pohod++;
            curr[code]--;
            if(curr[code] == nado[code]) pohod--;
        }
        num++;

        if(pohod == 0) ans++;
    }

    cout << ans;
}



