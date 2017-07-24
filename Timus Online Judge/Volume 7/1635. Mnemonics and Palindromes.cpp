// The solution of the problem was written by Izaron
// Date: 20:31:09   19 May 2016
// Execution time: 0.14

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
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int N = 4000 + 5;


string s;
int isPal[N][N];
int anss[N];
int to[N];

int getPal(int a, int b) {
    if (a == b)
        return 1;
    if (a + 1 == b)
        return s[a] == s[b];

    if (isPal[a][b] != -1)
        return isPal[a][b];

    isPal[a][b] = 0;
    if (s[a] == s[b] && getPal(a + 1, b - 1) == 1)
        isPal[a][b] = 1;

    return isPal[a][b];
}

int dfs(int v) {
    if (v >= s.size())
        return 0;

    if (anss[v] != -1)
        return anss[v];

    int ans = 1000000000;
    for (int i = v + 1; i <= s.size(); i++) {
        if (getPal(v, i - 1)) {
            ans = min(ans, 1 + dfs(i));
            if (ans == 1 + dfs(i))
                to[v] = i;
        }
    }

    anss[v] = ans;
    return ans;
}

int main() {
    memset(isPal, -1, sizeof(isPal));
    memset(anss, -1, sizeof(anss));

    cin >> s;
    cout << dfs(0) << endl;
    for (int i = 0; i < s.size();) {
        for (int z = i; z < to[i]; z++)
            cout << s[z];
        cout << " ";
        i = to[i];
    }
}
