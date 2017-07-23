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


int n;
char mass[40][40];
bool used[40][40];
int ans = 0;

void dfs(int x, int y) {
    if(used[x][y])
        return;

    used[x][y] = true;

    if(mass[x - 1][y] == '#') {
        ans++;
    }

    if(mass[x + 1][y] == '#') {
        ans++;
    }

    if(mass[x][y + 1] == '#') {
        ans++;
    }

    if(mass[x][y - 1] == '#') {
        ans++;
    }

    if(mass[x - 1][y] == '.' && !used[x - 1][y]) {
        dfs(x - 1, y);
    }

    if(mass[x + 1][y] == '.' && !used[x + 1][y]) {
        dfs(x + 1, y);
    }

    if(mass[x][y - 1] == '.' && !used[x][y - 1]) {
        dfs(x, y - 1);
    }

    if(mass[x][y + 1] == '.' && !used[x][y + 1]) {
        dfs(x, y + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    memset(used, false, sizeof(used));
    cin >> n;

    for(int i = 0; i < n + 2; i++) {
        mass[0][i] = '#';
        mass[n + 1][i] = '#';
        mass[i][0] = '#';
        mass[i][n + 1] = '#';
    }

    mass[0][0] = '?';
    mass[1][0] = '?';
    mass[0][1] = '?';

    mass[n + 1][n + 1] = '?';
    mass[n + 1][n] = '?';
    mass[n][n + 1] = '?';

    for(int i = 1; i <= n; i++) {
        for(int z = 1; z <= n; z++) {
            char ch;
            cin >> ch;
            mass[i][z] = ch;
        }
    }

    dfs(1, 1);
    dfs(n, n);
    cout << ans * 9;
}
