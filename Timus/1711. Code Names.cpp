// The solution of the problem was written by Izaron
// Date: 21:32:36   27 Apr 2015
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <string>
#include <sstream>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include <cmath>
#include <math.h>
#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

#define pp /*system("pause")*/
#define ct double ttme = clock()
#define p_ct cout << (clock() - ttme) / CLOCKS_PER_SEC << endl
#define all(c) (c).begin(),(c).end()
#define fft ifstream fin("input.txt"); ofstream fout("output.txt")
#define fft_c FILE *fin, *fout
#define fft_c_open fin = fopen("input.txt","r"); fout = fopen("output.txt","w")
#define fft_c_cl fclose(fin); fclose(fout)
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define mkp(a,b) make_pair((a),(b))
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pss pair<string, string>
#define M_PI 3.14159265358979323846
#define mem0(m) memset((m), 0, sizeof(m));
#define memb(m) memset((m), false, sizeof(m));
#define memi(m) memset((m), 0, sizeof(m));
#define rep(i,n) for(i = 0; i < (int)(n); i++)
#define repi(a, n) for(int i = a; i < (int)(n); i++)
#define repp(i, a, n) for(int (i) = a; (i) < (int)(n); (i)++)
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
ll gcd(ll a, ll b)
{
    ll c;
    while(a) {
        c = a;
        a = b % a;
        b = c;
    }

    return b;
}
const int INF = 1e8;
const int DEL = 687134561;
const long long MODULO = 1e9 + 7;
const int MAX = 1e7;



const int N = 16;

int main() {
    tuple<string, string, string> t[N];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s[3];
        cin >> s[0] >> s[1] >> s[2];
        sort(s, s + 3);
        t[i] = make_tuple(s[0], s[1], s[2]);
    }
    vector<string> ans;
    string curr = "";
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        if(get<0>(t[a]) > curr) {
            curr = get<0>(t[a]);
        } else if(get<1>(t[a]) > curr) {
            curr = get<1>(t[a]);
        } else if(get<2>(t[a]) > curr) {
            curr = get<2>(t[a]);
        } else {
            cout << "IMPOSSIBLE";
            return 0;
        }
        ans.push_back(curr);
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}











