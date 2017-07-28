// The solution of the problem was written by Izaron
// Date: 00:52:20   26 Jul 2017
// Execution time: 1.248

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

const int maxa = 900 + 5;
const int maxb = 8100 + 5;

int s1, s2;
int calced[maxa][maxb];

int dp(int a, int b) {
    if (min(a, b) < 0)
        return INT_MAX / 2;
    if ((a == 0 && b > 0) || (a > 0 && b == 0))
        return INT_MAX / 2;
    if (a == 0 && b == 0)
        return 0;

    int& pr = calced[a][b];
    if (pr != -1)
        return pr;

    pr = INT_MAX / 2;
    for (int i = 1; i < 10; i++) {
        int np = dp(a - i, b - i * i);
        pr = min(pr, np);
    }
    pr++;

    return pr;
}

void re(int a, int b) {
    if (a == 0 && b == 0)
        return;
    int& pr = calced[a][b];
    for (int i = 1; i < 10; i++) {
        int np = dp(a - i, b - i * i);
        if (pr == np + 1) {
            printf("%d", i);
            re(a - i, b - i * i);
            return;
        }
    }
}

int main() {
    for (int i = 0; i < maxa; i++) {
        for (int b = 0; b < maxb; b++)
            calced[i][b] = -1;
    }

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d%d", &s1, &s2);
        if (s1 > 9 * 100) {
            printf("No solution\n");
            continue;
        }
        if (s2 > 9 * 9 * 100) {
            printf("No solution\n");
            continue;
        }
        int res = dp(s1, s2);
        if (res > 100) {
            printf("No solution\n");
            continue;
        }
        re(s1, s2);
        printf("\n");
    }
}
