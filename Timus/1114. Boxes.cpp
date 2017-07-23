// The solution of the problem was written by Izaron
// Date: 18:53:46   16 May 2016
// Execution time: 0.001

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;

const int N = 10000 + 5;

ull ans[21][17][17];

ull dfs(int n, int a, int b) {
    if (a == 0 && b == 0)
        return 1;
    if (n == 0)
        return 1;

    if (ans[n][a][b] != 0)
        return ans[n][a][b];

    ull curr = 0;
    for (int i = 0; i <= a; i++) {
        for (int z = 0; z <= b; z++) {
            curr += dfs(n - 1, i, z);
        }
    }
    ans[n][a][b] = curr;
    return curr;
}

int main() {
    memset(ans, 0, sizeof(ans));
    int n, a, b;
    cin >> n >> a >> b;
    cout << dfs(n, a, b);
}