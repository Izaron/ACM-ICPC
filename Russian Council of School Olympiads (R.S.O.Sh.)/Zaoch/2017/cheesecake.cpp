#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#ifdef USE_CERR
#define CERR(a) cerr << a << endl
#else
#define CERR(a)
#endif

const int maxn = 2000 + 5;

int n, m, q;
vector<int> vec;
vector<int> calc;
vector<bool> used;

int counter[maxn][maxn];
int co = 10, last_co = 10;

int kek(int a, int b) {
    if (a == b && co != last_co)
        return maxn;
    if (counter[a][b] >= last_co)
        return -1;
    counter[a][b] = co++;
    int lal = vec[a];
    vec[a] = b;
    if (lal == -1)
        return a;
    else
        return kek(lal, a);
}

int kekk(int a, int b) {
    vector<int> shrek = vec;
    int val = kek(a, b);
    vec = shrek;
    last_co = co + 10;
    co = last_co;
    return val;
}

int kekk_pers(int a, int b) {
    int val = kek(a, b);
    last_co = co + 10;
    co = last_co;
    return val;
}

vector<int> neig[maxn];
vector<int> small_n[maxn];
vector<int> used3;
vector<int> usedc;
vector<int> comp;

void dfs_comp(int v) {
    if (used3[v])
        return;
    used3[v] = true;
    comp.push_back(v);
    for (auto it : neig[v])
        dfs_comp(it);
}

bool dfs_cycle(int v) {
    if (usedc[v])
        return true;
    usedc[v] = true;
    if (small_n[v].size() == 0)
        return false;
    return dfs_cycle(small_n[v][0]);
}

int calc_3() {
    for (int i = 0; i < maxn; i++) {
        neig[i].clear();
        small_n[i].clear();
    }
    used3.clear();
    usedc.clear();

    for (int i = 0; i < n; i++) {
        if (vec[i] == -1)
            continue;
        int a = i, b = vec[i];
        if (vec[b] != -1) {
            neig[i].push_back(vec[b]);
            neig[vec[b]].push_back(i);
            small_n[i].push_back(vec[b]);
        }
    }

    used3.resize(n);
    usedc.resize(n);
    int all = n, in_cycle = 0;

    for (int i = 0; i < n; i++) {
        if (used3[i])
            continue;
        comp.clear();
        dfs_comp(i);
        bool can = false;

        int ind = comp[0], kek = INT_MAX;;
        for (auto it : comp) {
            if (small_n[it].size() == 0)
                continue;
            if (neig[it].size() < kek) {
                kek = neig[it].size();
                ind = it;
            }
        }

        //for (auto it : comp) {
            fill(usedc.begin(), usedc.end(), false);
            if (dfs_cycle(ind)) {
                can = true;
                //break;
            }
        //}
        if (can) {
            in_cycle += comp.size();
        }
    }

    int ans = 0;
    ans += in_cycle * (all - in_cycle);
    ans += (all - in_cycle) * (n - 1);
    return ans;
}

vector<bool> is_cycle;

void build() {
    for (int i = 0; i < maxn; i++) {
        neig[i].clear();
        small_n[i].clear();
    }
    used3.clear();
    usedc.clear();
    is_cycle.clear();

    for (int i = 0; i < n; i++) {
        if (vec[i] == -1)
            continue;
        int a = i, b = vec[i];
        if (vec[b] != -1) {
            neig[i].push_back(vec[b]);
            neig[vec[b]].push_back(i);
            small_n[i].push_back(vec[b]);
        }
    }

    used3.resize(n);
    usedc.resize(n);
    is_cycle.resize(n);
    int all = n, in_cycle = 0;

    for (int i = 0; i < n; i++) {
        if (used3[i])
            continue;
        comp.clear();
        dfs_comp(i);
        bool can = false;

        int ind = comp[0], kek = INT_MAX;;
        for (auto it : comp) {
            if (small_n[it].size() == 0)
                continue;
            if (neig[it].size() < kek) {
                kek = neig[it].size();
                ind = it;
            }
        }

        //for (auto it : comp) {
            fill(usedc.begin(), usedc.end(), false);
            if (dfs_cycle(ind)) {
                can = true;
                //break;
            }
        //}
        if (can) {
            in_cycle += comp.size();
            for (auto it : comp)
                is_cycle[it] = true;
        }
    }

    int ans = 0;
    ans += in_cycle * (all - in_cycle);
    ans += (all - in_cycle) * (n - 1);
    //return ans;
}

int main() {
    memset(counter, 0, sizeof(counter));

    scanf("%d%d%d", &n, &m, &q);
    calc.resize(n);
    fill(calc.begin(), calc.end(), -1);
    vec.resize(n);
    fill(vec.begin(), vec.end(), -1);
    used.resize(n);

    int x, y;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        x--; y--;
        vec[x] = y;
    }

    build();

    int t;
    for (int i = 0; i < q; i++) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &x, &y);
            x--;
            y--;

            if (kekk(x, y) != -1)
                printf("Yes\n");
            else
                printf("No\n");
        } else if (t == 3) {
            printf("%d\n", calc_3());
        } else {
            scanf("%d%d", &x, &y);
            x--;
            y--;
            if (kekk(x, y) != -1) {
                printf("Yes\n");
                kekk_pers(x, y);
            } else
                printf("No\n");
        }
    }
}

/*
5 3 8
1 2
5 1
2 4
1 1 2
3
2 1 2
3
2 4 2
2 5 3
3
1 4 5
*/
