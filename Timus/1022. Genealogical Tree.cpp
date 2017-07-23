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



const int N = 100;
vector<int> g[N];
int m[N];
bool used[N];

void dfs(int v, int mol) {
    m[v] = mol;
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(m[to] > mol - 1) {
            dfs(to, mol - 1);
        }
    }
}

int main() {
    for(int i = 0; i < N; i++) m[i] = 1000;
    memb(used);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;
        while(true) {
            cin >> tmp;
            if(tmp == 0) break;
            tmp--;
            g[i].push_back(tmp);
        }
    }

    for(int i = 0; i < n; i++) {
        if(m[i] > 999)
            dfs(i, 999);
    }

    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++) {
        v.push_back(mkp(-m[i], i));
    }

    sort(all(v));

    for(int i = 0; i < n; i++) {
        cout << v[i].second + 1 << " ";
    }
}












