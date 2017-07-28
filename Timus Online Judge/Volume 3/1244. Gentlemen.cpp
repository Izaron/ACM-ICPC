// The solution of the problem was written by Izaron
// Date: 23:21:42   25 Jul 2017
// Execution time: 0.046

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <vector>
#include <string.h>
#include <iostream>
#include <map>
#include <limits.h>
#include <set>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 100;
const int maxw = 1000;

int calced[maxn][maxn * maxw];
int all, n;
vector<int> cards;

int calc(int v, int w) {
    if (w == all)
        return 1;
    if (w > all)
        return 0;
    if (v == n)
        return 0;
    if (calced[v][w] != -1)
        return calced[v][w];
    int& res = calced[v][w];
    res = calc(v + 1, w) + calc(v + 1, w + cards[v]);
    res = min(res, 2);
    return res;
}

void re(int v, int w) {
    if (w == all) {
        for (int i = v; i < n; i++)
            cout << i + 1 << " ";
        return;
    }
    if (w > all)
        return;
    if (v == n)
        return;
    if (calc(v + 1, w) == 1) {
        cout << v + 1 << " ";
        re(v + 1, w);
    } else {
        re(v + 1, w + cards[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(calced, -1, sizeof(calced));
    cin >> all >> n;
    cards.resize(n);
    for (int i = 0; i < n; i++)
        cin >> cards[i];

    int res = calc(0, 0);
    if (res == 2) {
        cout << -1 << endl;
    } else if (res == 0) {
        cout << 0 << endl;
    } else {
        re(0, 0);
        cout << endl;
    }
}
