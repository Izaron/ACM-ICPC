#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;

const int maxn = 100 + 5;

int n, q;
ld dista[maxn][maxn];
vector<ld> ccalc[maxn];
ld mann[maxn][maxn];

void dfs(ld kdist, ld speed, ld cur, vector<ld> & calc, int city) {
    if (kdist < 0)
        return;
    if (calc[city] <= cur)
        return;
    calc[city] = cur;
    for (int i = 0; i < n; i++) {
        if (i == city)
            continue;
        if (dista[city][i] == -1)
            continue;
        dfs(kdist - dista[city][i], speed, cur + dista[city][i] / speed, calc, i);
    }
}

void sub() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        ccalc[i].clear();
        ccalc[i].resize(n, LLONG_MAX / 4);
    }

    vector<int> dist(n), speed(n);
    for (int i = 0; i < n; i++) {
        cin >> dist[i] >> speed[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dista[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        dfs(dist[i], speed[i], 0, ccalc[i], i);

    for (int i = 0; i < n; i++) {
        //cerr << "i = " << i << ": ";
        //for (int j = 0; j < n; j++)
        //    cerr << ccalc[i][j] << " ";
        //cerr << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            mann[i][j] = ccalc[i][j];
    }

    for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mann[i][j] = min(mann[i][j], mann[i][k] + mann[k][j]);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << fixed << setprecision(10) << mann[a][b] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": ";
        sub();
        cout << endl;
    }
}
