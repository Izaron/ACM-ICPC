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



const int N = 150005;

int main()
{
    char a[N], b[N];

    scanf("%s", &a);
    scanf("%s", &b);
    int index = strlen(a);
    int n = strlen(a) + strlen(b) + 1;
    a[index] = '#';
    for(int i = 0; i < strlen(b); i++) {
        a[i + index + 1] = b[i];
    }

    int algo[N] = {0};

    for(int i = 1; i < n; i++) {
        int j = algo[i - 1];
        while(j > 0 && a[i] != a[j]) {
            j = algo[j - 1];
        }
        if(a[i] == a[j]) {
            j++;
        }
        algo[i] = j;
    }

    vector<pii> ans;

    int curr = -1;
    pii tmi;
    for(int i = n - 1; i > index; i--) {
        if(curr == -1) {
            tmi.first = i;
            tmi.second = i;

            curr = algo[i] - 1;
            if(curr == -1) {
                printf("Yes");
                return 0;
            }

            curr--;
            tmi.first--;

            if(curr == -1) {
                ans.push_back(tmi);
            }
        } else {
            tmi.first--;
            curr--;

            if(curr == -1) {
                ans.push_back(tmi);
            }
        }
    }

    printf("No\n");
    for(int i = ans.size() - 1; i >= 0; i--) {
        for(int z = ans[i].first; z < ans[i].second; z++) {
            printf("%c", a[z + 1]);
        }
        printf(" ");
    }
}



















