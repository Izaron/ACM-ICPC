// The solution of the problem was written by Izaron
// Date: 13:32:02   22 Feb 2015
// Execution time: 0.031

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
using namespace std;

#define pp system("pause");
#define ct double ttme = clock()
#define p_ct cout << (clock() - ttme) / CLOCKS_PER_SEC << endl
#define all(c) (c).begin(),(c).end()
#define fft ifstream fin("input.txt"); ofstream fout("output.txt")
#define fft_c FILE *fin, *fout
#define fft_c_open fin = fopen("input.txt","r"); fout = fopen("output.txt","w")
#define fft_c_cl fclose(fin); fclose(fout)
#define pii pair<ll,ll>
#define pff pair<float,float>
#define piii pair<int,pair<int,int>>
#define M_PI 3.14159265358979323846
#define mem0(m) memset((m), 0, sizeof(m));
#define memb(m) memset((m), false, sizeof(m));
#define memi(m) memset((m), 0, sizeof(m));
#define rep(i,n) for(i = 0; i < (int)(n); i++)
#define repi(a, n) for(int i = a; i < (int)(n); i++)
#define repp(i, a, n) for(int (i) = a; (i) < (int)(n); (i)++)
typedef unsigned long long ull;
typedef signed long long ll;
const int INF = 1e8;
const int DEL = 687134561;
const int MAXM = 100000007;
const int MAX = 1e7;
const int des = 10000;


int main()
{
    map<char, int> mp;

    mp['a'] = 1;
    mp['b'] = 2;
    mp['c'] = 3;

    mp['d'] = 1;
    mp['e'] = 2;
    mp['f'] = 3;

    mp['g'] = 1;
    mp['h'] = 2;
    mp['i'] = 3;

    mp['j'] = 1;
    mp['k'] = 2;
    mp['l'] = 3;

    mp['m'] = 1;
    mp['n'] = 2;
    mp['o'] = 3;

    mp['p'] = 1;
    mp['q'] = 2;
    mp['r'] = 3;

    mp['s'] = 1;
    mp['t'] = 2;
    mp['u'] = 3;

    mp['v'] = 1;
    mp['w'] = 2;
    mp['x'] = 3;

    mp['y'] = 1;
    mp['z'] = 2;

    mp['.'] = 1;
    mp[','] = 2;
    mp['!'] = 3;

    mp[' '] = 1;

    string s;
    getline(cin, s);

    int ans = 0;

    for(int i = 0; i < s.size(); i++) {
        ans += mp[s[i]];
    }

    cout << ans;
}
