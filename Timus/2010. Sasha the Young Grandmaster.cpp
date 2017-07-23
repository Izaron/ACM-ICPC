// The solution of the problem was written by Izaron
// Date: 12:33:25   1 May 2015
// Execution time: 0.031

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
#include <stack>
using namespace std;

#define pp /*system("pause")*/
#define ct double ttme = clock()
#define p_ct cout << (clock() - ttme) / CLOCKS_PER_SEC << endl
#define fft ifstream fin("input.txt"); ofstream fout("output.txt")
#define fft_c FILE *fin, *fout
#define fft_c_open fin = fopen("input.txt","r"); fout = fopen("output.txt","w")
#define fft_c_cl fclose(fin); fclose(fout)
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define mkp(a,b) make_pair((a),(b))
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
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



ll n;

bool inside(ll x, ll y) {
    if(x >= 1 && x <= n && y >= 1 && y <= n)
        return true;
    return false;
}

ll checkKing(ll x, ll y) {
    if(n == 1) return 0;
    int cnt = 0;
    if(x == 1 || x == n) cnt++;
    if(y == 1 || y == n) cnt++;
    if(cnt == 0)
        return 8;
    else if(cnt == 1)
        return 5;
    else
        return 3;
}

ll checkKnight(ll x, ll y) {
    ll cnt = 0;
    if(inside(x - 2, y - 1)) cnt++;
    if(inside(x - 1, y - 2)) cnt++;
    if(inside(x + 2, y - 1)) cnt++;
    if(inside(x + 1, y - 2)) cnt++;
    if(inside(x - 2, y + 1)) cnt++;
    if(inside(x - 1, y + 2)) cnt++;
    if(inside(x + 2, y + 1)) cnt++;
    if(inside(x + 1, y + 2)) cnt++;
    return cnt;
}

ll checkBishop(ll x, ll y) {
    return min(x - 1, y - 1) +
           min(n - x, n - y) +
           min(x - 1, n - y) +
           min(n - x, y - 1);
}

ll checkRook(ll x, ll y) {
    return n * 2 - 2;
}

int main() {
    ll x, y;
    cin >> n >> x >> y;

    cout << "King: " << checkKing(x, y) << endl;
    cout << "Knight: " << checkKnight(x, y) << endl;
    cout << "Bishop: " << checkBishop(x, y) << endl;
    cout << "Rook: " << checkRook(x, y) << endl;
    cout << "Queen: " << checkRook(x, y) + checkBishop(x, y) << endl;
}












