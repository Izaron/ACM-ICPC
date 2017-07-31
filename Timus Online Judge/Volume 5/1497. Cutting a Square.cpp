// The solution of the problem was written by Izaron
// Date: 18:15:28   29 Jul 2017
// Execution time: 0.046

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <limits.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

const int maxn = 1000 + 5;

short l[maxn][maxn];
short r[maxn][maxn];
short u[maxn][maxn];
short d[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(d, 0, sizeof(d));
    memset(u, 0, sizeof(u));

    for (int i = 0; i < n; i++) {
        for (int z = 0; z < n; z++) {
            if (vec[i][z] == '1') {
                l[i][z] = r[i][z] = u[i][z] = d[i][z] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int z = 0; z < n; z++) {
            if (z - 1 >= 0)
                l[i][z] += l[i][z - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int z = n - 1; z >= 0; z--) {
            if (z + 1 < n)
                r[i][z] += r[i][z + 1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int z = 0; z < n; z++) {
            if (z - 1 >= 0)
                d[z][i] += d[z - 1][i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int z = n - 1; z >= 0; z--) {
            if (z + 1 < n)
                u[z][i] += u[z + 1][i];
        }
    }

    bool cl = true, cr = true, cd = true, cu = true;
    for (int i = 0; i < n; i++) {
        for (int z = 0; z < n; z++) {
            if (vec[i][z] == '1') continue;
            if (l[i][z]) cl = false;
            if (r[i][z]) cr = false;
            if (d[i][z]) cd = false;
            if (u[i][z]) cu = false;
        }
    }

    if (cl || cr || cu || cd)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
