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
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
typedef unsigned long long ull;
typedef signed long long ll;
const int INF = 1e8;
const int MAXM = 100000007;
const int MAX = 1e7;
const int des = 10000;

int main() {

    int n;
    int mass[10];
    memset(mass, 0, sizeof(mass));

    cin >> n;

    if(n == 1) {
        cout << 1;
        return 0;
    } else if(n == 0) {
        cout << 10;
        return 0;
    }

    for(int i = 9; i >= 2; i--) {
        while(n % i == 0) {
            n /= i;
            mass[i]++;
        }
    }

    if(n > 1 && n < 10)
        mass[n]++;

    if(n != 1) {
        cout << -1;
        return 0;
    }

    for(int i = 2; i <= 9; i++) {
        for(int z = 0; z < mass[i]; z++)
            cout << i;
    }

}
