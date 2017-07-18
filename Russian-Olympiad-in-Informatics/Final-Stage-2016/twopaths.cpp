#include <bits/stdc++.h>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

const int N = 800000 * 2 + 5;
const int STEP = 18;



int n, k;

vector<int> neig[N];
int parent[N];
int as[N];
int bs[N];
int cs[N];
int first[N];
int depth[N];
int way[N];
int wayCnt = 0;
int step[N];
int razz[N];
pii table[N][STEP];

int logTable[N];

void buildTable() {
    for (int st = 0; st < STEP; st++) {
        for (int i = 0; i < wayCnt; i++) {
            table[i][st] = mkp(1000000000, 1000000000);
        }
    }

    for (int i = 0; i < wayCnt; i++)
        table[i][0] = mkp(depth[way[i]], way[i]);

    for (int st = 1; st < STEP; st++) {
        for (int i = 0; i + (1 << st) < wayCnt; i++) {
            pii a = table[i][st - 1];
            pii b = table[i + (1 << (st - 1))][st - 1];
            table[i][st] = min(a, b);
        }
    }
}

pii getTable(int L, int R) {
    int k = logTable[R - L];
    return min(table[L][k], table[R - (1 << k) + 1][k]);
}

int getPredok(int a, int b) {
    return getTable(min(first[a], first[b]), max(first[a], first[b])).second;
}

void dfsWay(int v, int d) {
    first[v] = wayCnt;
    depth[v] = d;
    way[wayCnt++] = v;
    for (auto it : neig[v]) {
        dfsWay(it, d + 1);
        way[wayCnt++] = v;
    }
}

int getCurr(int a, int b, int c, int d) {
    if (a == b || c == d)
        return 0;

    int pred = getPredok(a, c);
    return max(0, depth[pred] - max(depth[d], depth[b]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("twopaths.in", "r", stdin);
    //freopen("twopaths.out", "w", stdout);

    logTable[0] = 0;
    logTable[1] = 0;
    for (int i = 2; i < N; i++)
        logTable[i] = logTable[i / 2] + 1;


    int logg = 0;
    int raz = 1;
    for (int i = 0; i < N; i++) {
        while (raz < i) {
            raz *= 2;
            logg++;
        }
        razz[i] = logg;
    }

    step[1] = 1;
    for (int i = 2; i < 30; i++)
        step[i] = step[i - 1] * 2;

    scanf("%d%d", &n, &k);

    for (int i = 1; i < n; i++) {
        scanf("%d", &parent[i]);
        parent[i]--;
        neig[parent[i]].pb(i);
    }

    dfsWay(0, 0);

    buildTable();

    for (int i = 0; i < k; i++) {
        scanf("%d%d", &as[i], &bs[i]);
        as[i]--;
        bs[i]--;
        cs[i] = getPredok(as[i], bs[i]);
    }

    int maxi = 0, a = 0, b = 1;

    for (int i = 0; i < k; i++) {
        for (int z = i + 1; z < k; z++) {
            int curr = 0;
            curr += getCurr(as[i], cs[i], as[z], cs[z]);
            curr += getCurr(as[i], cs[i], bs[z], cs[z]);
            curr += getCurr(bs[i], cs[i], as[z], cs[z]);
            curr += getCurr(bs[i], cs[i], bs[z], cs[z]);
            if (curr > maxi) {
                maxi = curr;
                a = i;
                b = z;
            }
        }
    }

    printf("%d\n%d %d", maxi, a + 1, b + 1);
}