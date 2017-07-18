#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

const int maxn = (const int) (2e5 + 5);
const int maxk = 18;

int n, m;
int par[maxn];
int real_depth[maxn];
int for_query[maxn];
int query_cnt = 0;
vector<int> to[maxn];
vector<int> dep[maxn];
int depth_ptr[maxn];
vector<pii> dep_reqs[maxn];
int b_left[maxk][maxn];
int b_right[maxk][maxn];
vector<int> dep_sets[maxn];

void dfs(int v, int d) {
    depth_ptr[v] = (int) dep[d].size();
    real_depth[v] = d;
    dep[d].push_back(v);
    for (auto it : to[v])
        dfs(it, d + 1);
}

void build_left(int v) {
    for (auto it : to[v])
        build_left(it);
    b_left[0][v] = (to[v].size() == 0 ? v : to[v][0]);
    for (int i = 1; i < maxk; i++) {
        int last = b_left[i - 1][v];
        b_left[i][v] = b_left[i - 1][last];
    }
}

void build_right(int v) {
    for (auto it : to[v])
        build_right(it);
    b_right[0][v] = (to[v].size() == 0 ? v : to[v][to[v].size() - 1]);
    for (int i = 1; i < maxk; i++) {
        int last = b_right[i - 1][v];
        b_right[i][v] = b_right[i - 1][last];
    }
}

pii find_left_right_most(int v, int d) {
    pii res = make_pair(v, v);
    for (int i = maxk - 1; i >= 0; i--) {
        if ((d - (1 << i)) >= 0) {
            d -= (1 << i);
            res.first = b_left[i][res.first];
            res.second = b_right[i][res.second];
        }
    }
    return res;
}



int eu_cnt = 0;
int first_eu[maxn];

int order_of_key(vector<int> & vec, int k) {
    if (k > vec[vec.size() - 1])
        return vec.size();
    if (k <= vec[0])
        return 0;
    int l = 0, r = vec.size() - 1;
    while (l != r) {
        int la = l, lb = r;
        int mid = (l + r) / 2;
        if (k > vec[mid])
            l = mid;
        else
            r = mid;
        if (la == l && lb == r) {
            if (k > vec[r])
                l = r;
            else
                r = l;
        }
    }
    return l + 1;
}

pii find_in_depth(pii bs, int d) {
    ////////
    set<int> st;
    for (auto it : dep_sets[d])
        st.insert(it);
    ////////

    //int lef = dep_sets[d].order_of_key(first_eu[bs.first]);
    //int rig = dep_sets[d].order_of_key(first_eu[bs.second] + 1) - 1;

    int lef = order_of_key(dep_sets[d], first_eu[bs.first]);
    int rig = order_of_key(dep_sets[d], first_eu[bs.second] + 1) - 1;

    return make_pair(lef, rig);
}

void save_query(pii q, int d) {
    dep_reqs[d].push_back(q);
}

void euler(int v) {
    first_eu[v] = eu_cnt;
    dep_sets[real_depth[v]].push_back(eu_cnt++);
    for (auto it : to[v])
        euler(it);
}



void clean_quers() {
    for (int i = 0; i < maxn; i++) {
        if (dep_reqs[i].size() == 0)
            continue;
        for (auto & it : dep_reqs[i])
            it.second *= -1;
        sort(dep_reqs[i].begin(), dep_reqs[i].end());
        for (auto & it : dep_reqs[i])
            it.second *= -1;
        vector<pii> nvec;
        for (int z = 0; z < dep_reqs[i].size(); z++) {
            if (z + 1 < dep_reqs[i].size() && dep_reqs[i][z].second >= dep_reqs[i][z + 1].second)
                continue;
            nvec.push_back(dep_reqs[i][z]);
        }
        dep_reqs[i] = nvec;
    }
}

void setup_quers() {
    query_cnt = 0;
    for (int i = 0; i < maxn; i++) {
        if (dep_reqs[i].size() == 0)
            continue;
        for (auto it : dep_reqs[i]) {
            for (int z = it.first; z <= it.second; z++) {
                for_query[dep[i][z]] = query_cnt;
                //cerr << dep[i][z] << " num is " << query_cnt << endl;
            }
            query_cnt++;
        }
    }
}

int cnt[maxn];
int bad = 0;
int l, r;

void shift_left() {
    if (for_query[l] != -1 && cnt[for_query[l]] == 1)
        bad++;
    if (for_query[l] != -1)
        cnt[for_query[l]]--;
    l++;
    r = max(r, l);
}

bool move() {
    while (bad > 0) {
        r++;
        if (r >= n)
            return false;
        if (for_query[r] != -1 && cnt[for_query[r]] == 0)
            bad--;
        if (for_query[r] != -1)
            cnt[for_query[r]]++;
    }
    return true;
}

int main() {
    freopen("qual.in", "r", stdin);
    freopen("qual.out", "w", stdout);


    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &par[i + 1]);
        par[i + 1]--;
        to[par[i + 1]].push_back(i + 1);
    }
    scanf("%d", &m);
    dfs(0, 0);
    build_left(0);
    build_right(0);

    euler(0);

    int a, d;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &d);
        a--;
        save_query(find_in_depth(find_left_right_most(a, d), d + real_depth[a]), d + real_depth[a]);
        //request(a, d);
    }

    clean_quers();

    memset(for_query, -1, sizeof(for_query));
    setup_quers();


    // find ans
    memset(cnt, 0, sizeof(cnt));
    l = 0; r = -1;
    int len = INT_MAX;
    int aa = 0, bb = 0;
    bad = query_cnt;
    while (true) {
        if (!move())
            break;
        //cerr << "cur ans is " << l << " " << r << endl;
        if (r - l < len) {
            len = r - l;
            aa = l;
            bb = r;
        }
        shift_left();
    }

    printf("%d %d\n", aa + 1, bb + 1);
}

/*
 7
 1 1 2 2 3 3
 3
 1 1
 3 1
 1 2

 5
 1 1 2 2
 3
 1 1
 2 1
 1 2
 */

[close]
