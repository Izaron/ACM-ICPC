// The solution of the problem was written by Izaron
// Date: 23:57:18   24 Mar 2015
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

#define pp system("pause");
#define ct double ttme = clock()
#define p_ct cout << (clock() - ttme) / CLOCKS_PER_SEC << endl
#define all(c) (c).begin(),(c).end()
#define fft ifstream fin("input.txt"); ofstream fout("output.txt")
#define fft_c FILE *fin, *fout
#define fft_c_open fin = fopen("input.txt","r"); fout = fopen("output.txt","w")
#define fft_c_cl fclose(fin); fclose(fout)
#define pii pair<ll,ll>
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
typedef signed long long int ll;
typedef long double ld;
const int INF = 1e8;
const int DEL = 687134561;
const long long MODULO = 1e9 + 7;
const int MAX = 1e7;
const int des = 10000;



int cel(int a, int b) {
    if(b == 0) {
        return 0;
    } else if(a % b == 0) {
        return a / b;
    } else if(a >= 0) {
        return a / b + 1;
    } else {
        return a / b;
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int mass[20000];

    for(int i = 0; i < n + m - 1; i++) {
        scanf("%d", &mass[i]);
    }

    int curr = 0, maxi = -1000000000;
    for(int i = 0; i < m; i++) {
        maxi = max(maxi, cel((mass[i] - curr), (i + 1)));
    }
    curr += maxi;
    printf("%d ", curr);

    for(int i = 1; i < n; i++) {
        maxi = -1000000000;
        for(int z = i; z < i + m; z++) {
            maxi = max(maxi, cel((mass[z] - curr), (z - i + 1)));
        }
        curr += maxi;
        printf("%d ", maxi);
    }
}



















