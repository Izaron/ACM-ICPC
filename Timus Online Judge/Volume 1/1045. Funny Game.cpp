// The solution of the problem was written by Izaron
// Date: 18:00:44   20 Feb 2015
// Execution time: 0.015

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


int ans = 10000, kk = 0;
vector<int> g[1005];
bool used[1005];

int dfs(int k) {
    used[k] = true;

    if(g[k].size() == 2 && ( used[g[k][0]] || used[g[k][1]] )) {
        if(!used[g[k][0]]) {
            return 1 + dfs(g[k][0]);
        } else {
            return 1 + dfs(g[k][1]);
        }
    }

    for(int i = 0; i < (int)g[k].size(); i++) {
        if(used[ g[k][i] ])
            continue;
        if(dfs(g[k][i]) % 2 == 0) {
            if(k == kk) {
                ans = min(ans, g[k][i]);
            } else {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    memset(used, false, sizeof(used));

    int n, k;
    cin >> n >> k;

    k--;
    kk = k;

    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(k);

    if(ans != 10000)
        cout << "First player wins flying to airport " << ans + 1;
    else
        cout << "First player loses";
}
