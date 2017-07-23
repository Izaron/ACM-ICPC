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
#define REP(i,n) for(i = 0; i < (int)(n); i++)
typedef unsigned long long ull;
typedef signed long long ll;
const int INF = 1e8;
const int DEL = 687134561;
const int MAXM = 100000007;
const int MAX = 1e7;
const int des = 10000;


vector<int> g[100];
bool used[100];
int coms[100];
int ans = 0;
bool fak = false;

void dfs(int v, int curr) {
    if(g[v].size() == 0) {
        fak = true;
        return;
    }

    used[v] = true;
    coms[v] = curr % 2;
    if(coms[v] == 1)
        ans++;

    for(int i = 0; i < g[v].size(); i++) {
        if(used[g[v][i]])
            continue;
        dfs(g[v][i], curr + 1);
    }
}

int main()
{
    memset(used, false, sizeof(used));
    memset(coms, 0, sizeof(coms));

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        while(cin >> a) {
            if(a == 0)
                break;
            a--;
            g[i].push_back(a);
        }
    }

    for(int i = 0; i < n; i++) {
        if(!used[i])
            dfs(i, 0);
    }

    if(fak) {
        cout << 0;
        return 0;
    }

    cout << ans << endl;

    for(int i = 0; i < n; i++) {
        if(coms[i] == 1)
            cout << i + 1 << " ";
    }
}
