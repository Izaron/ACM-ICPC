// The solution of the problem was written by Izaron
// Date: 21:42:16   15 Apr 2015
// Execution time: 0.406

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#define TRUE FALSE
//  _           _                                          _              _               _          _                _                    ___
// | |         | |                                        | |            (_)             | |        | |              | |                  |__ \
// | |     ___ | |     __ _ _ __ ___   _   _  ___  _   _  | |_ _ __ _   _ _ _ __   __ _  | |_ ___   | |__   __ _  ___| | __  _ __ ___   ___  ) |
// | |    / _ \| |    / _` | '__/ _ \ | | | |/ _ \| | | | | __| '__| | | | | '_ \ / _` | | __/ _ \  | '_ \ / _` |/ __| |/ / | '_ ` _ \ / _ \/ /
// | |___| (_) | |_  | (_| | | |  __/ | |_| | (_) | |_| | | |_| |  | |_| | | | | | (_| | | || (_) | | | | | (_| | (__|   <  | | | | | |  __|_|
// \_____/\___/|_( )  \__,_|_|  \___|  \__, |\___/ \__,_|  \__|_|   \__, |_|_| |_|\__, |  \__\___/  |_| |_|\__,_|\___|_|\_\ |_| |_| |_|\___(_)
//               |/                     __/ |                        __/ |         __/ |
//

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
#include <stack>
using namespace std;

#define pp /*system("pause")*/
#define ct double ttme = clock()
#define p_ct cout << (clock() - ttme) / CLOCKS_PER_SEC << endl
#define all(c) (c).begin(),(c).end()
#define fft ifstream fin("input.txt"); ofstream fout("output.txt")
#define fft_c FILE *fin, *fout
#define fft_c_open fin = fopen("input.txt","r"); fout = fopen("output.txt","w")
#define fft_c_cl fclose(fin); fclose(fout)
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define mkp(a,b) make_pair((a),(b))
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pss pair<string, string>
#define M_PI 3.14159265358979323846
#define mem0(m) memset((m), 0, sizeof(m));
#define memb(m) memset((m), false, sizeof(m));
#define memi(m) memset((m), 0, sizeof(m));
#define rep(i,n) for(i = 0; i < (int)(n); i++)
#define repi(a, n) for(int i = a; i < (int)(n); i++)
#define repp(i, a, n) for(int (i) = a; (i) < (int)(n); (i)++)
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
ll gcd(ll a, ll b)
{
    ll c;
    while(a) {
        c = a;
        a = b % a;
        b = c;
    }

    return b;
}
const int INF = 1e8;
const int DEL = 687134561;
const long long MODULO = 1e9 + 7;
const int MAX = 1e7;



const int N = 100005;

vector<int> g[N];
int parent[N];

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        parent[b] = a;
        return true;
    } else {
        return false;
    }
}

bool used[N];
void dfs(int v) {
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(used[to]) continue;
        parent[to] = v;
        dfs(to);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    memset(parent, -1, sizeof(parent));
    memset(used, false, sizeof(used));

    vector<pii> lst;
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        lst.push_back(mkp(a, b));
    }

    int q;
    scanf("%d", &q);

    vector<int> cms, cms2;

    for(int i = 0; i < q; i++) {
        int tmp;
        scanf("%d", &tmp);
        tmp--;
        cms.push_back(tmp);
        cms2.push_back(tmp);
    }

    sort(all(cms2));

    int ans = 0;
    int curr = 0;
    for(int i = 0; i < lst.size(); i++) {
        if(i == cms2[curr]) {
            curr++;
            continue;
        }
        int a = lst[i].first, b = lst[i].second;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    curr = 0;
    for(int i = 0; i < n; i++) {
        if(used[i]) continue;
        make_set(i);
        dfs(i);
        ans++;
    }

    reverse(all(cms));

    vector<int> ansed;
    ansed.push_back(ans);

    for(int i = 0; i < cms.size() - 1; i++) {
        int a = lst[cms[i]].first, b = lst[cms[i]].second;
        g[a].push_back(b);
        g[b].push_back(a);
        if(union_sets(a,b)) ans--;
        ansed.push_back(ans);
    }

    reverse(all(ansed));

    for(int i = 0; i < ansed.size(); i++) {
        printf("%d\n", ansed[i]);
    }
}
















