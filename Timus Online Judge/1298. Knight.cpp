// The solution of the problem was written by Izaron
// Date: 21:23:07   10 Mar 2015
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
#include <unordered_map>
#include <queue>
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;

#define pp system("pause");
#define ct double ttme = clock()
#define p_ct cout << (clock() - ttme) / CLOCKS_PER_SEC << endl
#define all(c) (c).begin(),(c).end()
#define fft ifstream fin("input.txt"); ofstream fout("output.txt")
#define fft_c FILE *fin, *fout
#define fft_c_open fin = fopen("input.txt","r"); fout = fopen("output.txt","w")
#define fft_c_cl fclose(fin); fclose(fout)
#define pii pair<int,int>
#define mp(a,b) make_pair((a),(b))
#define pff pair<float,float>
#define piii pair<int,pair<int,int>>
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
const int INF = 1e8;
const int DEL = 687134561;
const long long MODULO = 1e9 + 7;
const int MAX = 1e7;
const int des = 10000;


int n;

int mass[10][10];

int dx[] = { -1, -2, -2, -1,  1,  2,  2,  1 };
int dy[] = { -2, -1,  1,  2,  2,  1, -1, -2 };

bool dfs(int x, int y, int curr) {
    mass[x][y] = curr;

    if(curr == 1) {
        return true;
    }

    for(int i = 0; i < 8; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx >= 0 && xx < n && yy >= 0 && yy < n && mass[xx][yy] == 0) {
            if(dfs(xx, yy, curr - 1)) {
                return true;
            }
        }
    }

    mass[x][y] = 0;
    return false;
}

int main()
{
    memset(mass, 0, sizeof(mass));

    cin >> n;

    if(n == 8) {
        cout << "a1\n"
                "b3\n"
                "a5\n"
                "b7\n"
                "d8\n"
                "c6\n"
                "b4\n"
                "a2\n"
                "c3\n"
                "b1\n"
                "a3\n"
                "b5\n"
                "a7\n"
                "c8\n"
                "b6\n"
                "a4\n"
                "c5\n"
                "a6\n"
                "b8\n"
                "d7\n"
                "f8\n"
                "e6\n"
                "d4\n"
                "c2\n"
                "e3\n"
                "d1\n"
                "b2\n"
                "c4\n"
                "d6\n"
                "e8\n"
                "g7\n"
                "f5\n"
                "e7\n"
                "g8\n"
                "f6\n"
                "h7\n"
                "g5\n"
                "e4\n"
                "d2\n"
                "f1\n"
                "h2\n"
                "f3\n"
                "e1\n"
                "g2\n"
                "h4\n"
                "g6\n"
                "h8\n"
                "f7\n"
                "h6\n"
                "g4\n"
                "e5\n"
                "d3\n"
                "c1\n"
                "e2\n"
                "g1\n"
                "h3\n"
                "f2\n"
                "h1\n"
                "g3\n"
                "h5\n"
                "f4\n"
                "d5\n"
                "c7\n"
                "a8";

        return 0;
    }

    bool can = false;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            if(dfs(x, y, n * n)) {
                can = true;
                break;
            }
        }
        if(can) {
            break;
        }
    }

    if(!can) {
        cout << "IMPOSSIBLE";
    } else {
        int curr = n * n;
        while(curr > 0) {
            for(int i = 0; i < n; i++)
            for(int z = 0; z < n; z++) {
                if(mass[i][z] == curr) {
                    cout << (char)(i + 'a') << (z + 1) << endl;
                }
            }
            curr--;
        }
    }
}
