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
#define pii pair<int,int>
#define mp(a,b) make_pair((a),(b))
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
const long long MODULO = 1e9 + 7;
const int MAX = 1e7;
const int des = 10000;


int main()
{
    int n;
    string s;
    cin >> s;
    if(s.size() == 2) {
        string ss = s.substr(0, 1);
        n = atoi(ss.c_str());
    } else {
        string ss = s.substr(0, 2);
        n = atoi(ss.c_str());
    }

    char c = s[s.size() - 1];

    if( (n >= 1 && n <= 2 && c == 'A') || (n >= 1 && n <= 2 && c == 'D') ) {
        cout << "window";
        return 0;
    }

    if( (n >= 3 && n <= 20 && c == 'A') || (n >= 3 && n <= 20 && c == 'F') ) {
        cout << "window";
        return 0;
    }

    if( (n >= 21 && n <= 65 && c == 'A') || (n >= 21 && n <= 65 && c == 'K') ) {
        cout << "window";
        return 0;
    }

    if( (n >= 1 && n <= 2 && c == 'B') || (n >= 1 && n <= 2 && c == 'C') ) {
        cout << "aisle";
        return 0;
    }

    if( (n >= 3 && n <= 20 && c == 'B') || (n >= 3 && n <= 20 && c == 'C') ||
        (n >= 3 && n <= 20 && c == 'D') || (n >= 3 && n <= 20 && c == 'E')) {
        cout << "aisle";
        return 0;
    }

    if( (n >= 21 && n <= 65 && c == 'C') || (n >= 21 && n <= 65 && c == 'D') ||
        (n >= 21 && n <= 65 && c == 'G') || (n >= 21 && n <= 65 && c == 'H')) {
        cout << "aisle";
        return 0;
    }

    cout << "neither";
}
