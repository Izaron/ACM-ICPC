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

int gcd(int a, int b)
{
    int c;
    while(a) {
        c = a;
        a = b % a;
        b = c;
    }

    return b;
}

#define pp system("pause");
#define ct double ttme = clock()
#define p_ct cout << (clock() - ttme) / CLOCKS_PER_SEC << endl
#define all(c) (c).begin(),(c).end()
#define fft ifstream fin("input.txt"); ofstream fout("output.txt")
#define fft_c FILE *fin, *fout
#define fft_c_open fin = fopen("input.txt","r"); fout = fopen("output.txt","w")
#define fft_c_cl fclose(fin); fclose(fout)
#define pii pair<ll,ll>
#define mkp(a,b) make_pair((a),(b))
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




int main() {
    set<string> st;
    vector<string> vec;
    map<string, bool> many;
    string lang = "wowmemes";
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(st.find(s) == st.end()) {
            vec.push_back(s);
        } else {
            many[s] = true;
        }
        st.insert(s);
    }

    if(n == 1) {
        cout << 0;
    } else if(n == 2) {
        if(vec.size() == 1) {
            cout << 0;
        } else {
            cout << 1 << endl;
            cout << vec[0] << "-" << vec[1];
        }
    } else if(n > 2) {
        if(vec.size() == n) {
            cout << vec.size() << endl;
            for(int i = 0; i < vec.size(); i++) {
                cout << lang << "-" << vec[i] << endl;
            }
        } else {
            cout << "Impossible";
        }
    }
}



















