#include "aliens.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> indexes;
vector<int> points;
int64_t ans[5000 + 5][5000 + 5];

int64_t square(int a, int b) {
    int64_t dist = points[b] - indexes[a] + 1;
    return dist * dist;
}

int64_t common(int a, int b) {
    if (a == b)
        return 0;
    if (a < 0 || b >= (int) points.size())
        return 0;
    int64_t dist = max(0, points[a] - indexes[b] + 1);
    return dist * dist;
}

int64_t dp(int v, int k) {
    if (k < 0)
        return LLONG_MAX / 2;
    if (v == (int) points.size())
        return 0;
    if (ans[v][k] != -1)
        return ans[v][k];
    int64_t ank = LLONG_MAX;
    for (int i = v; i < (int) points.size(); i++) {
        ank = min(ank, dp(i + 1, k - 1) + square(v, i) - common(i, i + 1));
    }
    ans[v][k] = ank;
    return ank;
}

long long take_photos(int n, int m, int k, std::vector<int> r, std::vector<int> c) {
    vector<int> ms(m, -1);
    for (int i = 0; i < n; i++) {
        int a = r[i], b = c[i];
        if (a > b)
            swap(a, b);
        ms[a] = max(ms[a], b);
    }

    int cur = -1;
    for (int i = 0; i < m; i++) {
        if (ms[i] > cur) {
            cur = ms[i];
            indexes.push_back(i);
            points.push_back(ms[i]);
        }
    }

    memset(ans, -1, sizeof(ans));
    return dp(0, k);
}
