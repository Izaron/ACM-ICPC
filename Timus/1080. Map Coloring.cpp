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


vector<int> g[100];
int mass[100];
bool used[100];
int n;

bool dfs(int v, int z) {
    used[v] = true;
    mass[v] = z;

    for(int i = 0; i < (int)g[v].size(); i++) {
        if(used[g[v][i]]) {
            if(mass[g[v][i]] == z) {
                return false;
            }
        } else {
            if(!dfs(g[v][i], 1 - z))
                return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);

    memset(used, false, sizeof(used));
    memset(mass, -1, sizeof(mass));
    cin >> n;

    for(int i = 0; i < n; i++) {
        int z;
        while(cin >> z) {
            if(z == 0)
                break;
            z--;
            g[z].push_back(i);
            g[i].push_back(z);
        }
    }

    if(dfs(0,0)) {
        for(int i = 0; i < n; i++)
            cout << mass[i];
    } else {
        cout << -1;
    }
}
