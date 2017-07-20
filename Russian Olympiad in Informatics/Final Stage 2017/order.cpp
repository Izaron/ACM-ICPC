#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

int n;
vector<int> vec;
vector<int> as, bs;

void go(int pow, int pos, int u, int d, int add) {
    if (pow < 0)
        return;

    int cur = (vec[pos] >> pow) & 1;

    if (u == 1) {
        int ncur = (vec[pos - 1] >> pow) & 1;
        if (ncur != cur) {
            if (ncur == 0)
                as[pow] += add;
            else
                bs[pow] += add;
            u = 0;
        }
    }

    if (d == 1) {
        int ncur = (vec[pos + 1] >> pow) & 1;
        if (ncur != cur) {
            if (ncur == 0)
                bs[pow] += add;
            else
                as[pow] += add;
            d = 0;
        }
    }

    go(pow - 1, pos, u, d, add);
}

void change(int pos, int val) {
    go(29, pos, (pos == 0 ? 0 : 1), (pos == n - 1 ? 0 : 1), -1);
    vec[pos] = val;
    go(29, pos, (pos == 0 ? 0 : 1), (pos == n - 1 ? 0 : 1), +1);
}

int calc() {
    int ret = 0;
    for (int i = 0; i < 30; i++) {
        if (as[i] > 0 && bs[i] > 0)
            return -1;
        if (bs[i] > 0)
            ret |= (1 << i);
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    vec.resize(n);
    as.resize(30);
    bs.resize(30);
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        change(i, v);
    }
    printf("%d\n", calc());
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int pos, v;
        scanf("%d%d", &pos, &v);
        change(pos - 1, v);
        printf("%d\n", calc());
    }
}
