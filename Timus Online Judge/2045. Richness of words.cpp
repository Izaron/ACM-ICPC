// The solution of the problem was written by Izaron
// Date: 20:36:45   13 Oct 2015
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define pss pair<string,string>
#define pdd pair<ld,ld>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define ff first
#define ss second
typedef long long int ll;
typedef long double ld;



const int N = 2000 + 5;





int main() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << "1 : a" << endl;
        return 0;
    }

    if(n == 2) {
        cout << "1 : NO" << endl;
        cout << "2 : ab" << endl;
        return 0;
    }

    cout << "1 : NO" << endl;
    cout << "2 : NO" << endl;

    string s = "";
    for(int i = 0; i < n; i++)
        s += (char)(i % 3 + 'a');

    for(int i = 3; i <= n; i++) {
        int kz = n - i + 2;
        string tmp = s;
        for(int z = kz; z < n; z++)
            tmp[z] = tmp[kz];
        cout << i << " : " << tmp << endl;
    }
}


