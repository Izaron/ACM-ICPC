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
#include <unordered_set>
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
#define REP(i,n) for(i = 0; i < (int)(n); i++)
typedef unsigned long long ull;
typedef signed long long ll;
const int INF = 1e8;
const int DEL = 687134561;
const int MAXM = 100000007;
const int MAX = 1e7;
const int des = 10000;



int main() {
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int ans[500], ukz[500];
    pii mems[500];
    memset(ans, 0, sizeof(ans));
    memset(ukz, 1000, sizeof(ukz));
    for(int i = 0; i < 500; i++)
        ukz[i] = 1000;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mems[i].first = a;
        mems[i].second = b;
    }

    for(int h = 0; h < n; h++)
    for(int i = 0; i < n; i++) {
        int maxiAns = -1;
        for(int z = 0; z < n; z++) {
            if(i == z)
                continue;
            if(ans[z] > maxiAns && mems[i].first > mems[z].first && mems[i].second < mems[z].second) {
                maxiAns = ans[z];
                ukz[i] = z;
            }
        }
        ans[i] = maxiAns + 1;
    }

    int maxiIndex = 0;
    for(int i = 1; i < n; i++) {
        if(ans[i] > ans[maxiIndex]) {
            maxiIndex = i;
        }
    }

    cout << ans[maxiIndex] + 1 << endl;
    cout << maxiIndex + 1 << " ";

    while(ukz[maxiIndex] != 1000) {
        cout << ukz[maxiIndex] + 1 << " ";
        maxiIndex = ukz[maxiIndex];
    }
}
