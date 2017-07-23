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
#include <unordered_map>
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
const int INF = 1e8;
const int DEL = 687134561;
const long long MODULO = 1e9 + 7;
const int MAX = 1e7;
const int des = 10000;



int main() {
    stringstream ss;
    int n;
    cin >> n;

    int maxxi = 0;
    int tmp = 5;

    int lal = 0, sm = 1, bg = n * n;

    int mass[105][105];
    mem0(mass);

    for(int i = 0; i < n; i++) {
        if(n % 2 == 0) {
            lal = i % 2;
        }

        for(int z = 0; z < n; z++) {
            if(lal % 2 == 0) {
                ss << bg << " ";
                mass[i][z] = bg;
                bg--;
            } else {
                ss << sm << " ";
                mass[i][z] = sm;
                sm++;
            }

            if(z > 0) {
                maxxi = max(maxxi, mass[i][z] + mass[i][z - 1]);
            }

            if(i > 0) {
                maxxi = max(maxxi, mass[i][z] + mass[i - 1][z]);
            }

            lal++;
        }

        ss << endl;
    }

    cout << maxxi << endl;
    cout << ss.str();
}
