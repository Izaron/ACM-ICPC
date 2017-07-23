#define TRUE FALSE
//  _           _                                          _              _               _          _                _                    ___
// | |         | |                                        | |            (_)             | |        | |              | |                  |__ \
// | |     ___ | |     __ _ _ __ ___   _   _  ___  _   _  | |_ _ __ _   _ _ _ __   __ _  | |_ ___   | |__   __ _  ___| | __  _ __ ___   ___  ) |
// | |    / _ \| |    / _` | '__/ _ \ | | | |/ _ \| | | | | __| '__| | | | | '_ \ / _` | | __/ _ \  | '_ \ / _` |/ __| |/ / | '_ ` _ \ / _ \/ /
// | |___| (_) | |_  | (_| | | |  __/ | |_| | (_) | |_| | | |_| |  | |_| | | | | | (_| | | || (_) | | | | | (_| | (__|   <  | | | | | |  __|_|
// \_____/\___/|_( )  \__,_|_|  \___|  \__, |\___/ \__,_|  \__|_|   \__, |_|_| |_|\__, |  \__\___/  |_| |_|\__,_|\___|_|\_\ |_| |_| |_|\___(_)
//              |/                     __/ |                        __/ |         __/ |
//                                    |___/                        |___/         |___/


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
const int des = 10000;



int main() {
    int n, a, b;
    cin >> n >> a >> b;

    ll mass[50005][2];
    mem0(mass);

    mass[1][0] = 1;
    mass[1][1] = 1;
    mass[0][0] = 1;
    mass[0][1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int z = i - 1; z >= i - b; z--) {
            if(z == -1) {
                break;
            }
            mass[i][0] += mass[z][1];
        }
        mass[i][0] %= 1000000007;

        for(int z = i - 1; z >= i - a; z--) {
            if(z == -1) {
                break;
            }
            mass[i][1] += mass[z][0];
        }
        mass[i][1] %= 1000000007;
    }

    int ans = mass[n][0] + mass[n][1];
    ans %= 1000000007;
    cout << ans;
}





















