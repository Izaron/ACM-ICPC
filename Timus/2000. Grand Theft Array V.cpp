// The solution of the problem was written by Izaron
// Date: 12:44:28   30 Mar 2015
// Execution time: 0.218

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

int gcd(int a, int b)
{
    int c;
    while(a) {
        c = a;
        a = b % a;
        b = c;
    }

    return b;
}

#define pp /*system("pause")*/;
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
#define piii pair<ll,pair<ll,ll>>
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
const int INF = 1e8;
const int DEL = 687134561;
const long long MODULO = 1e9 + 7;
const int MAX = 1e7;
const int des = 10000;





int main() {
    int mass[100005];
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &mass[i]);
    }

    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;

    int xx = x, yy = y;

    int a = 0, b = 0;
    bool aa = true;

    if(x == y) {
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i <= x; i++) {
            sum1 += mass[i];
        }
        for(int i = x; i < n; i++) {
            sum2 += mass[i];
        }
        if(sum1 > sum2) {
            printf("%d %d", sum1, sum2 - mass[x]);
        } else {
            printf("%d %d", sum2, sum1 - mass[x]);
        }

        return 0;
    }

    if(x < y) {
        for(int i = 0; i <= x; i++) {
            a += mass[i];
            mass[i] = 0;
        }
        for(int i = y; i < n; i++) {
            b += mass[i];
            mass[i] = 0;
        }
    } else {
        for(int i = x; i < n; i++) {
            a += mass[i];
            mass[i] = 0;
        }
        for(int i = 0; i <= y; i++) {
            b += mass[i];
            mass[i] = 0;
        }
    }

    while(x != y) {
        if(aa) {
            if(x > y) {
                x--;
            } else {
                x++;
            }
            a += mass[x];
            mass[x] = 0;
        } else {
            if(y < x) {
                y++;
            } else {
                y--;
            }
            b += mass[y];
            mass[y] = 0;
        }

        aa = !aa;
    }

    printf("%d %d", a, b);
}
























