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

    bool mass[10005];
    memset(mass, false, sizeof(mass));

    for(int i = 2; i <= 10000; i++) {
        if(mass[i] == true)
            continue;
        for(int z = i * 2; z <= 10000; z += i) {
            mass[z] = true;
        }
    }

    vector<int> grs;
    map<int, int> mp;

    for(int i = 2; i <= 10000; i++) {
        if(mass[i] == false)
            grs.push_back(i);
    }

    for(int i = 0; i < 10; i++) {
        int tmp;
        cin >> tmp;

        for(int z = 0; z < grs.size(); z++) {
            while(tmp % grs[z] == 0) {
                mp[grs[z]]++;
                tmp /= grs[z];
            }
        }
    }

    int ans = 1;
    for(int i = 0; i < grs.size(); i++) {
        ans = (ans * (mp[grs[i]] + 1)) % 10;
    }

    cout << ans;
}
