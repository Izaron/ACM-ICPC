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




int main() {
    int x = 0, y = 0, z = 0;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        int m;
        cin >> s >> m;
        if(s == "X") {
            x += m;
        } else if(s == "Y") {
            y += m;
        } else {
            z += m;
        }
    }

    int maxi = 32000 * 2, ax = x, ay = y, az = z;

    for(int i = -32000; i <= 32000; i++) {
        int plus = x - i;
        y += plus;
        z -= plus;
        if(abs(i) + abs(y) + abs(z) < maxi) {
            maxi = abs(i) + abs(y) + abs(z);
            ax = i;
            ay = y;
            az = z;
        }
        y -= plus;
        z += plus;
    }

    int memes = 0;
    if(ax != 0) memes++;
    if(ay != 0) memes++;
    if(az != 0) memes++;

    cout << memes << endl;

    if(ax != 0) cout << "X " << -ax << endl;
    if(ay != 0) cout << "Y " << -ay << endl;
    if(az != 0) cout << "Z " << -az << endl;
}



















