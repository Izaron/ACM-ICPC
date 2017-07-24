// The solution of the problem was written by Izaron
// Date: 12:59:35   1 Mar 2015
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
const int MAX = 1e7;
const int des = 10000;


ll answer[81] = {
    10,
    45,
    165,
    495,
    1287,
    3003,
    6435,
    12870,
    24310,
    43749,
    75501,
    125565,
    202005,
    315315,
    478731,
    708444,
    1023660,
    1446445,
    2001285,
    2714319,
    3612231,
    4720815,
    6063255,
    7658190,
    9517662,
    11645073,
    14033305,
    16663185,
    19502505,
    22505751,
    25614639,
    28759500,
    31861500,
    34835625,
    37594305,
    40051495,
    42126975,
    43750575,
    44865975,
    45433800,
    45433800,
    44865975,
    43750575,
    42126975,
    40051495,
    37594305,
    34835625,
    31861500,
    28759500,
    25614639,
    22505751,
    19502505,
    16663185,
    14033305,
    11645073,
    9517662,
    7658190,
    6063255,
    4720815,
    3612231,
    2714319,
    2001285,
    1446445,
    1023660,
    708444,
    478731,
    315315,
    202005,
    125565,
    75501,
    43749,
    24310,
    12870,
    6435,
    3003,
    1287,
    495,
    165,
    45,
    9,
    1,
};

int main()
{
    int s;
    cin >> s;
    cout << answer[s - 1];
}
