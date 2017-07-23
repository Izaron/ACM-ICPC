// The solution of the problem was written by Izaron
// Date: 00:05:40   1 Mar 2015
// Execution time: 0.671

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
const int MAX = 1e7;
const int des = 10000;



const int MAXN = 1000000 + 10;
int a[2 * MAXN];
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int i = 1;
    while (n--)
    {
        int t;
        scanf("%d", &t);
        if (t > 0)
            a[i++] = t;
        else if (t == -1)
            printf("%d\n", a[--i]);
        else if (t == 0)
        {
            if (i - 1 <= n)
            {
                int num = min(i - 1, n);
                for (int j = 1; j <= num; ++j)
                {
                    a[i] = a[i-num];
                    ++i;
                }
            }
        }
    }
    //system("pause");
    return 0;
}
