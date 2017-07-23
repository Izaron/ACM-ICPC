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
#include <unordered_map>
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



const int MAXN = 100005;

int main() {
    bool used[MAXN], used2[MAXN];
    memb(used);
    memb(used2);

    int n, r;
    scanf("%d%d", &n, &r);

    int ukz[MAXN];
    int mass[MAXN];

    for(int i = 0; i < n; i++) {
        ukz[i] = -1;
        scanf("%d", &mass[i]);
    }

    int k = n;

    for(int i = n - 1; i >= 0; i--) {
        auto it = lower_bound(mass, mass + n, mass[i] + r + 1);
        int index = it - mass;

        if(index == n) {
            continue;
        }

        for(; index < n; index++) {
            if(!used[index]) {
                break;
            }
        }

        if(index == n) {
            continue;
        }

        used[index] = true;
        ukz[i] = index;
        k--;
    }

    printf("%d\n", k);

    vector<int> vec;
    for(int i = 0; i < n; i++) {
        vec.clear();
        if(k == 0) {
            break;
        }
        if(used2[i]) {
            continue;
        }
        used2[i] = true;
        vec.push_back(i);
        for(int z = ukz[i]; z != -1; z = ukz[z]) {
            used2[z] = true;
            vec.push_back(z);
        }

        printf("%d ", vec.size());
        for(int z = 0; z < vec.size(); z++) {
            printf("%d ", vec[z] + 1);
        }
        printf("\n");

        k--;
    }
}
