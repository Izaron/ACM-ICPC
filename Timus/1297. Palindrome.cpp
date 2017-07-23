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



string s;
string ans = "";

int dfs(int a, int b) {
    string tmp = "";
    while(a >= 0 && b < s.size() && s[a] == s[b]) {
        if(b - a == 2) {
            tmp += s[a + 1];
            tmp = s[a] + tmp;
            tmp += s[b];
        } else if(b - a == 1) {
            tmp += s[a];
            tmp += s[b];
        } else {
            tmp = s[a] + tmp;
            tmp += s[b];
        }

        a--;
        b++;
    }
    if(tmp.size() > ans.size()) {
        ans = tmp;
    }
    return b;
}

int main() {
    cin >> s;

    ans = s[0];

    if(s.size() == 1) {
        cout << s;
        return 0;
    }

    int curr = 0;

    for(curr = 1; curr < s.size(); curr++) {
        if(s[curr - 1] == s[curr + 1]) {
            dfs(curr - 1, curr + 1);
        }
        if(s[curr - 1] == s[curr]) {
            dfs(curr - 1, curr);
        }
    }

    cout << ans << endl;
}

















