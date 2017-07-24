// The solution of the problem was written by Izaron
// Date: 16:10:58   29 Apr 2015
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


char m[16];

void povorot() {
    char a[16];

    a[0] = m[3];
    a[1] = m[7];
    a[2] = m[11];
    a[3] = m[15];

    a[4] = m[2];
    a[5] = m[6];
    a[6] = m[10];
    a[7] = m[14];

    a[8] = m[1];
    a[9] = m[5];
    a[10] = m[9];
    a[11] = m[13];

    a[12] = m[0];
    a[13] = m[4];
    a[14] = m[8];
    a[15] = m[12];

    for(int i = 0; i < 16; i++)
        m[i] = a[i];
}

int main() {
    for(int i = 0; i < 16; i++)
        cin >> m[i];
    char s[16];
    for(int i = 0; i < 16; i++)
        cin >> s[i];
    for(int i = 0; i < 4; i++) {
        for(int z = 0; z < 16; z++) {
            if(m[z] == 'X') cout << s[z];
        }
        povorot();
        povorot();
        povorot();
    }
}











