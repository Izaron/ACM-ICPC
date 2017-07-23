// The solution of the problem was written by Izaron
// Date: 23:57:11   19 Mar 2015
// Execution time: 0.203

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

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
#define pii pair<ll,ll>
#define mp(a,b) make_pair((a),(b))
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
typedef signed long long int ll;
typedef long double ld;
const int INF = 1e8;
const int DEL = 687134561;
const long long MODULO = 1e9 + 7;
const int MAX = 1e7;
const int des = 10000;



string a, b;
string ans = "Impossible";

bool failed[1005][1005];
bool win = false;

void dfs(string finalized, int x, int y) {
    if(x == a.size() && y == b.size()) {
        ans = finalized;
        win = true;
        return;
    } else {
        failed[x][y] = true;
    }

    if(!failed[x + 2][y] && x + 1 < a.size() && a[x] != a[x + 1]) {
        dfs(finalized + "11", x + 2, y);
        if(!win)
            failed[x][y] = true;
    }
    if(!failed[x + 1][y + 1] && x < a.size() && y < a.size() && a[x] != b[y]) {
        dfs(finalized + "12", x + 1, y + 1);
        if(!win)
            failed[x][y] = true;
    }
    if(!failed[x][y + 2] && y + 1 < a.size() && b[y] != b[y + 1]) {
        dfs(finalized + "22", x, y + 2);
        if(!win)
            failed[x][y] = true;
    }
}

int main() {
    int n;
    cin >> n >> a >> b;
    dfs("", 0, 0);
    cout << ans;
}

















