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

#define pp system("pause");
#define ct double ttme = clock()
#define p_ct cout << (clock() - ttme) / CLOCKS_PER_SEC << endl
#define all(c) (c).begin(),(c).end()
#define fft ifstream fin("input.txt"); ofstream fout("output.txt")
#define fft_c FILE *fin, *fout
#define fft_c_open fin = fopen("input.txt","r"); fout = fopen("output.txt","w")
#define fft_c_cl fclose(fin); fclose(fout)
#define pii pair<ll,ll>
#define mp(a,b) make_pair((a),(b))
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


const int MAXN = 500;

int mex(set<int> a) {
    for(int i = 0; ; i++) {
        if(!a.count(i)) {
            return i;
        }
    }
}

int mass[MAXN];

int main() {
    int x;
    cin >> x;
    x %= 34 * 4;

    mass[0] = 0;
    mass[1] = 1;
    mass[2] = 1;

    set<int> sett;
    for(int n = 3; n <= x; n++) {
        sett.clear();
        sett.insert(mass[n - 2]);

        for(int i = 2; i < n; i++) {
            sett.insert(mass[n - i - 1] ^ mass[i - 2]);
        }

        mass[n] = mex(sett);
    }

    cout << ((mass[x] == 0) ? "Black" : "White");
}
