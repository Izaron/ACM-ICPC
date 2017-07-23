// The solution of the problem was written by Izaron
// Date: 21:07:33   28 Apr 2016
// Execution time: 0.421

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int N = 100000 + 5;

int n, m;
int ys[N];
int xs[N];
int ysCpy[N];
int xsCpy[N];

int gett() {
    int ans = 0;
    int ker = min(ys[0], ys[n - 1]);
    for (int i = 1; i < m - 1; i++) {
        ans = max(ans, min(ker, xs[i]));
    }
    ans = max(ans, min(xs[0], ys[n - 1]));
    ans = max(ans, min(xs[m - 1], ys[0]));

    return ans;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> ys[i];
        ysCpy[i] = ys[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> xs[i];
        xsCpy[i] = xs[i];
    }

    int ans = gett();

    for (int i = 0; i < m; i++)
        ys[i] = xsCpy[i];
    for (int i = 0; i < n; i++)
        xs[i] = ysCpy[i];
    swap(n, m);

    ans = max(ans, gett());

    cout << ans;
}
