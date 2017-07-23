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

    string mass[1005];

    for(int i = 0; i < n; i++)
        cin >> mass[i];

    vector<int> ans;

    for(int langs = 1; langs <= n; langs++) {
        if(n % langs != 0)
            continue;

        bool can = true;
        map<string, bool> beens;

        for(int start = 0; start < n; start += langs) {
            string marker = "1234567890123456789111";
            for(int z = start; z < start + langs; z++) {
                if(mass[z] == "unknown") {
                    continue;
                } else if(marker == "1234567890123456789111") {
                    marker = mass[z];
                    if(beens[marker]) {
                        can = false;
                        break;
                    } else {
                        beens[marker] = true;
                    }
                } else if(marker != mass[z]) {
                    can = false;
                    break;
                }
            }

            if(!can)
                break;
        }

        if(can)
            ans.push_back(n / langs);
    }

    if(ans.size() == 0) {
        cout << "Igor is wrong.";
    } else {
        sort(all(ans));
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
}
