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
#define rep(i,n) for(i = 0; i < (int)(n); i++)
#define repi(a, n) for(int i = a; i < (int)(n); i++)
#define repp(i, a, n) for(int (i) = a; (i) < (int)(n); (i)++)
typedef unsigned long long ull;
typedef signed long long ll;
const int INF = 1e8;
const int DEL = 687134561;
const int MAXM = 100000007;
const int MAX = 1e7;
const int des = 10000;


int main()
{
    int n;
    cin >> n;

    int mass[100][100];
    bool used[100][100];
    mem0(mass);
    memb(used);

    vector<pii> vec;
    vec.push_back(make_pair(n - 1, n - 1));

    int ans = 1;

    while(vec.size() > 0) {
        if(vec[0].second - 1 >= 0 && !used[vec[0].first][vec[0].second - 1]) {
            used[vec[0].first][vec[0].second - 1] = true;
            vec.push_back(make_pair(vec[0].first, vec[0].second - 1));
        }
        if(vec[0].first - 1 >= 0 && !used[vec[0].first - 1][vec[0].second]) {
            used[vec[0].first - 1][vec[0].second] = true;
            vec.push_back(make_pair(vec[0].first - 1, vec[0].second));
        }

        mass[vec[0].first][vec[0].second] = ans;
        vec.erase(vec.begin() + 0);
        ans++;
    }

    for(int i = n - 1; i >= 0; i--) {
        repp(j, 0, n)
            cout << mass[i][j] << " ";
        cout << endl;
    }

    int z = 0;
}
