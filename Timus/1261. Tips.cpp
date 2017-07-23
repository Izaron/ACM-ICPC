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
#define pii pair<int,int>
#define mp(a,b) make_pair((a),(b))
#define pff pair<float,float>
#define piii pair<int,pair<int,int>>
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
    ll n;
    cin >> n;

    for(ll i = 1; i <= 2097152; i++) {
        ll myy = 0, tmp = i, step = 0;

        while(tmp > 0) {
            if(step == 0) {
                myy += (tmp & 1);
                step++;
            } else {
                myy += 3 * step * (tmp & 1);
                step *= 3;
            }
            tmp >>= 1;
        }

        ll nah = myy - n;
        if(nah <= 0) {
            continue;
        }

        bool fool = false;

        ll memas0 = myy, memas1 = nah;
        while(myy > 0 || nah > 0) {
            if(myy == 1 && nah == 1) {
                break;
            }
            if(myy % 3 == nah % 3 && nah % 3 > 0) {
                fool = true;
                break;
            }

            if(myy % 3 == 2 || nah % 3 == 2) {
                fool = true;
                break;
            }

            myy /= 3;
            nah /= 3;
        }

        if(fool) {
            continue;
        }

        cout << memas0 << " " << memas1;
        return 0;
    }

    cout << 0;
}
