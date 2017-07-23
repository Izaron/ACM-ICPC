// The solution of the problem was written by Izaron
// Date: 23:54:47   13 Apr 2015
// Execution time: 1.234

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#define TRUE FALSE
//  _           _                                          _              _               _          _                _                    ___
// | |         | |                                        | |            (_)             | |        | |              | |                  |__ \
// | |     ___ | |     __ _ _ __ ___   _   _  ___  _   _  | |_ _ __ _   _ _ _ __   __ _  | |_ ___   | |__   __ _  ___| | __  _ __ ___   ___  ) |
// | |    / _ \| |    / _` | '__/ _ \ | | | |/ _ \| | | | | __| '__| | | | | '_ \ / _` | | __/ _ \  | '_ \ / _` |/ __| |/ / | '_ ` _ \ / _ \/ /
// | |___| (_) | |_  | (_| | | |  __/ | |_| | (_) | |_| | | |_| |  | |_| | | | | | (_| | | || (_) | | | | | (_| | (__|   <  | | | | | |  __|_|
// \_____/\___/|_( )  \__,_|_|  \___|  \__, |\___/ \__,_|  \__|_|   \__, |_|_| |_|\__, |  \__\___/  |_| |_|\__,_|\___|_|\_\ |_| |_| |_|\___(_)
//              |/                     __/ |                        __/ |         __/ |
//

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




ll t[128][128][128];
int n;

ll sum(int x, int y, int z) {
    ll result = 0;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for(int j = y; j >= 0; j = (j & (j + 1)) - 1)
            for(int q = z; q >= 0; q = (q & (q + 1)) - 1)
                result += t[i][j][q];
    return result;
}

void inc(int x, int y, int z, int delta) {
    for(int i = x; i < n; i = (i | (i + 1)))
        for(int j = y; j < n; j = (j | (j + 1)))
            for(int q = z; q < n; q = (q | (q + 1)))
                t[i][j][q] += delta;
}

ll sum(int x1, int y1, int z1, int x2, int y2, int z2) {
    int x0 = x1 - 1, y0 = y1 - 1, z0 = z1 - 1;
    x1 = x2, y1 = y2, z1 = z2;
    return sum(x1, y1, z1) - sum(x0, y1, z1) - sum(x1, y0, z1) - sum(x1, y1, z0)
            + sum(x1, y0, z0) + sum(x0, y1, z0) + sum(x0, y0, z1) - sum(x0, y0, z0);
}

int main() {
    scanf("%d", &n);
    int m;
    while(true) {
        scanf("%d", &m);
        if(m == 3) break;
        if(m == 1) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            ll k;
            scanf("%I64d", &k);
            inc(x, y, z, k);
        }
        if(m == 2) {
            int x1, y1, z1, x2, y2, z2;
            scanf("%d%d%d", &x1, &y1, &z1);
            scanf("%d%d%d", &x2, &y2, &z2);
            printf("%I64d\n", sum(x1, y1, z1, x2, y2, z2));
        }
    }
}
