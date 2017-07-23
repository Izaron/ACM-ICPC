// The solution of the problem was written by Izaron
// Date: 20:29:52   28 Apr 2016
// Execution time: 2.012

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

const int N = 1500000 + 5;

int n;
int ans[N];
int maxis[N];
int toLeft[N];
int toRight[N];

int main() {
    scanf("%d", &n);
    fill(ans, ans + N, 0);
    fill(maxis, maxis + N, 0);
    fill(toLeft, toLeft + N, 0);
    fill(toRight, toRight + N, 0);

    set<int> gus;
    bool gak = false;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        gus.ins(tmp);
        if (tmp >= 1000000)
            gak = true;
    }

    for (auto it : gus) {
        int lead = it;
        while (true) {
            if (lead >= N) {
                maxis[N - 1] = max(maxis[N - 1], abs(it - (lead - N - 1)));
                break;
            }
            maxis[lead] = max(maxis[lead], it);
            lead += it * 2;
        }
    }

    int curr = 0;
    for (int i = N - 1; i >= 0; i--) {
        curr--;
        curr = max(curr, maxis[i]);
        toLeft[i] = max(0, curr);
    }
    curr = 0;
    for (int i = 0; i < N; i++) {
        curr--;
        curr = max(curr, maxis[i]);
        toRight[i] = max(0, curr);
    }

    for (int i = 0; i < N; i++) {
        maxis[i] = max(maxis[i], max(toLeft[i], toRight[i]));
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int pos;
        scanf("%d", &pos);
        if (gak)
            printf("%d\n", pos);
        else
            printf("%d\n", maxis[pos]);
    }
}
