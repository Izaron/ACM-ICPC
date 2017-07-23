// The solution of the problem was written by Izaron
// Date: 22:28:50   17 May 2016
// Execution time: 0.218

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

const int N = 100000 + 5;

int main() {
    int n;
    scanf("%d", &n);
    ull xs[N], ys[N];

    ull sumXRight = 0, sumYRight = 0, sumXLeft = 0, sumYLeft = 0;
    ull cntX = 0, cntY = 0;
    ull dist = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &xs[i], &ys[i]);
        sumXRight += xs[i];
        sumYRight += ys[i];
    }

    sort(xs, xs + n);
    sort(ys, ys + n);

    ull nn = n;
    nn = nn * (nn - 1) / 2;
    ull ans = 0;

    for (int i = 0; i < n; i++) {
        sumXLeft += xs[i];
        sumXRight -= xs[i];
        cntX++;
        dist += (cntX * xs[i] - sumXLeft);
        ans += dist / nn;
        dist %= nn;
    }

    for (int i = 0; i < n; i++) {
        sumYLeft += ys[i];
        sumYRight -= ys[i];
        cntY++;
        dist += (cntY * ys[i] - sumYLeft);
        ans += dist / nn;
        dist %= nn;
    }

    cout << ans;
}