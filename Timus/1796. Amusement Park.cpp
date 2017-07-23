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
    int mass[6];
    for(int i = 0; i < 6; i++)
        cin >> mass[i];
    int sum = mass[0] * 10 + mass[1] * 50 + mass[2] * 100 + mass[3] * 500 +
            mass[4] * 1000 + mass[5] * 5000;
    int micro = sum;
    if(mass[0] > 0) {
        micro -= 10;
    } else if(mass[1] > 0) {
        micro -= 50;
    } else if(mass[2] > 0) {
        micro -= 100;
    } else if(mass[3] > 0) {
        micro -= 500;
    } else if(mass[4] > 0) {
        micro -= 1000;
    } else {
        micro -= 5000;
    }
    micro++;

    int k;
    cin >> k;

    vector<int> vec;

    int starter = (micro) / k * k;
    if(micro % k != 0)
        starter += k;
    for(int z = starter; z <= sum; z += k) {
        vec.push_back(z / k);
    }

    cout << vec.size() << endl;
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}
