#include <bits/stdc++.h>
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;


const int N = 262144 * 2 + 5;
const int BIT = 19 + 5;

int n, m, k;
vector<pii> closed[N];
vector<pii> opened[N];
vector<pii> openedReverse[N];
set<pii> all;
vector<pii> allList;
int go[N];
int way[N][BIT];

void buildWay() {
    for (int i = 0; i < n; i++)
        way[i][0] = go[i];
    for (int bit = 1; bit < BIT; bit++) {
        for (int i = 0; i < n; i++) {
            int to = way[i][bit - 1];
            way[i][bit] = way[to][bit - 1];
        }
    }
}

bool can(int from, int to, int len) {
    int tto = from;
    while (true) {
        if (len == 0)
            break;
        int curr = -1;
        for (int i = BIT - 1; i >= 0; i--) {
            if (len >= (1 << i)) {
                curr = i;
                break;
            }
        }
        len -= (1 << curr);
        tto = way[tto][curr];
    }

    return (tto >= to);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("trains.in", "r", stdin);
    freopen("trains.out", "w", stdout);

    memset(go, 0, sizeof(go));
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; i++) {
        int s, d, a;
        scanf("%d%d%d", &s, &d, &a);
        s--;
        d--;
        a--;
        closed[a].pb(mkp(s, d));
    }

    for (int i = 0; i < k; i++) {
        if (closed[i].size() == 0)
            continue;
        sort(closed[i].begin(), closed[i].end());
    }

    for (int i = 0; i < k; i++) {
        int last = 0;
        for (int z = 0; z < closed[i].size(); z++) {
            int a = closed[i][z].first;
            int b = closed[i][z].second;
            opened[i].pb(mkp(last, a));
            openedReverse[i].pb(mkp(a, last));
            last = b;
        }
        opened[i].pb(mkp(last, n - 1));
        openedReverse[i].pb(mkp(n - 1, last));
    }

    for (int i = 0; i < k; i++) {
        for (int z = 0; z < opened[i].size(); z++) {
            all.insert(opened[i][z]);
        }
    }

    for (auto it : all)
        allList.pb(it);

    for (int i = 0; i < allList.size(); i++)
        go[allList[i].first] = max(go[allList[i].first], allList[i].second);
    for (int i = 1; i < N; i++)
        go[i] = max(go[i], go[i - 1]);

    buildWay();

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int curr, d;
        scanf("%d%d", &curr, &d);
        curr--;
        d--;

        if (!can(curr, d, (1 << (BIT - 1)))) {
            printf("-1\n");
            continue;
        }

        int a = 1, b = (1 << (BIT - 1));

        while (a != b) {
            int la = a, lb = b;
            int mid = (a + b) / 2;

            if (can(curr, d, mid))
                b = mid;
            else
                a = mid;

            if (la == a && lb == b) {
                if (can(curr, d, a))
                    b = a;
                else
                    a = b;
            }
        }

        printf("%d\n", a);
    }
}