#include <bits/stdc++.h>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

const int N = 100000 + 5;

int n, m;
int city[N];
vector<int> neig[N];
int s, f, r;
int distS[N], distF[N], distR[N];

void bfsS(int v) {
    deque<pii> dek;
    dek.pb(mkp(0, v));

    while (!dek.empty()) {
        pii curr = dek.front();
        dek.pop_front();
        if (curr.first >= distS[curr.second])
            continue;
        distS[curr.second] = curr.first;
        for (auto it : neig[curr.second]) {
            if (curr.first + 1 < distS[it]) {
                dek.pb(mkp(curr.first + 1, it));
            }
        }
    }
}

void bfsF(int v) {
    deque<pii> dek;
    dek.pb(mkp(0, v));

    while (!dek.empty()) {
        pii curr = dek.front();
        dek.pop_front();
        if (curr.first >= distF[curr.second])
            continue;
        distF[curr.second] = curr.first;
        for (auto it : neig[curr.second]) {
            if (curr.first + 1 < distF[it]) {
                dek.pb(mkp(curr.first + 1, it));
            }
        }
    }
}

void bfsR(int v) {
    deque<pii> dek;
    dek.pb(mkp(0, v));

    while (!dek.empty()) {
        pii curr = dek.front();
        dek.pop_front();
        if (curr.first >= distR[curr.second])
            continue;
        distR[curr.second] = curr.first;
        for (auto it : neig[curr.second]) {
            if (curr.first + 1 < distR[it]) {
                dek.pb(mkp(curr.first + 1, it));
            }
        }
    }
}

int main() {
    memset(city, -1, sizeof(city));
    fill(distS, distS + N, 100000000);
    fill(distF, distF + N, 100000000);
    fill(distR, distR + N, 100000000);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        neig[a].pb(b);
        neig[b].pb(a);
    }
    scanf("%d%d%d", &s, &f, &r);
    s--;
    f--;
    r--;

    bfsS(s);
    bfsF(f);
    bfsR(r);

    int dist = 1000000000;
    for (int i = 0; i < n; i++) {
        dist = min(dist, distS[i] + distF[i]);
    }

    for (int i = 0; i < n; i++) {
        if (distS[i] + distF[i] == dist) {
            if (city[distS[i]] == -1 || distR[city[distS[i]]] < distR[i])
                city[distS[i]] = i;
        }
    }

    int ans = 1000000000;
    for (int i = 0; i < N; i++) {
        if (city[i] == -1)
            continue;
        ans = min(ans, distR[city[i]]);
    }

    printf("%d", ans);
}