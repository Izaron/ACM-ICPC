// The solution of the problem was written by Izaron
// Date: 14:35:55   22 Feb 2015
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
    double a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    double def1 = 0.0;
    for(double a = a1; abs(a - b1) >= 0.015; a += 0.01) {
        if(a - (int)(a) >= 0.6) {
            a = (int)(a);
            a += 1.0;
        }
        if(a >= 24.0) {
            a = 0.0;
        }

        def1 += 0.01;
        if(def1 - (int)(def1) >= 0.6) {
            def1 = (int)(def1);
            def1 += 1.0;
        }
    }

    double def2 = 0.0;
    for(double a = a2; abs(a - b2) >= 0.015; a += 0.01) {
        if(a - (int)(a) >= 0.6) {
            a = (int)(a);
            a += 1.0;
        }
        if(a >= 24.0) {
            a = 0.0;
        }

        def2 += 0.01;
        if(def2 - (int)(def2) >= 0.6) {
            def2 = (int)(def2);
            def2 += 1.0;
        }
    }

    double def = abs(def1 - def2);

    if(def - (int)(def) > 0.59) {
        def -= 0.60;
        def += 1.0;
    }

    if(abs(def - (int)(def)) < abs(def - ((int)(def) + 1.0))) {
        def = (int)(def);
    } else {
        def = (int)(def) + 1.0;
    }

    cout << min((int)(def) / 2, 5);
}
