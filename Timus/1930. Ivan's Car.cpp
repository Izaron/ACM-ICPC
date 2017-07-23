// The solution of the problem was written by Izaron
// Date: 21:30:50   22 May 2016
// Execution time: 0.14

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <deque>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int, int> tt;

const int N = 10000 + 5;


int n, m;
int x, y;
vector<int> up[N];
vector<int> down[N];
int ans1[N];
int ans2[N];

void work(int type) {
    fill(ans1, ans1 + N, -1);

    vector<int> dek;
    vector<int> tmp;

    dek.pb(x);
    ans1[x] = 0;

    int ans = 0;

    while (true) {
        bool can = false;

        if (type == 0) {
            for (int i = 0; i < dek.size(); i++) {
                for (auto neig : up[dek[i]]) {
                    if (ans1[neig] != -1)
                        continue;
                    can = true;
                    ans1[neig] = ans;
                    dek.pb(neig);
                }
            }

            ans++;
            tmp.clear();
            for (int i = 0; i < dek.size(); i++) {
                for (auto neig : down[dek[i]]) {
                    if (ans1[neig] != -1)
                        continue;
                    can = true;
                    ans1[neig] = ans;
                    tmp.pb(neig);
                }
            }
            dek.clear();
            dek = tmp;
        } else {
            for (int i = 0; i < dek.size(); i++) {
                for (auto neig : down[dek[i]]) {
                    if (ans1[neig] != -1)
                        continue;
                    can = true;
                    ans1[neig] = ans;
                    dek.pb(neig);
                }
            }

            ans++;
            tmp.clear();
            for (int i = 0; i < dek.size(); i++) {
                for (auto neig : up[dek[i]]) {
                    if (ans1[neig] != -1)
                        continue;
                    can = true;
                    ans1[neig] = ans;
                    tmp.pb(neig);
                }
            }
            dek.clear();
            dek = tmp;
        }

        type = 1 - type;

        if (!can)
            break;
    }
}

int main() {
    memset(ans1, -1, sizeof(ans1));
    memset(ans2, -1, sizeof(ans2));

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        up[a].pb(b);
        down[b].pb(a);
    }

    scanf("%d%d", &x, &y);
    x--;
    y--;

    work(0);
    int kek = ans1[y];
    work(1);
    kek = min(kek, ans1[y]);
    cout << kek;
}
