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




int main() {
    int n;
    int m[100][100];

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    int to[105], back[105];
    mem0(to);
    mem0(back);

    for(int i = 0; i < n; i++) {
        for(int z = 0; z < n; z++) {
            int cost = m[i][z];
            if(i < z) {
                for(int k = i; k < z; k++)
                    back[k] += cost;
            } else {
                for(int k = z; k < i; k++)
                    to[k] += cost;
            }
        }
    }

    int maxi = 0;
    for(int i = 0; i < 105; i++) {
        maxi = max(maxi, max(to[i], back[i]));
    }

    if(maxi % 36 == 0)
        cout << maxi / 36;
    else
        cout << maxi / 36 + 1;
}











