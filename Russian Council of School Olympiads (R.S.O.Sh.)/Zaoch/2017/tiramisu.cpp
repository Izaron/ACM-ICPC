#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n, m;
vector<int> temp;
vector<pii> kurtak;

bool temp_sort(int a, int b) {
    return temp[a] < temp[b];
}

bool kurtak_sort_f(int a, int b) {
    return kurtak[a] < kurtak[b];
}

bool kurtak_sort_s(int a, int b) {
    pii aa, bb;
    aa = { kurtak[a].second, kurtak[a].first }; 
    bb = { kurtak[b].second, kurtak[b].first }; 
    return aa < bb;
}

vector<int> gen(int n) {
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[i] = i;
    return res;
}

int main() {
    scanf("%d%d", &n, &m);

    //if (max(m, n) > 7)
    //    throw 0;

    temp.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &temp[i]);

    kurtak.resize(m);
    for (int i = 0; i < m; i++)
        scanf("%d%d", &kurtak[i].first, &kurtak[i].second);

    vector<int> temp_sorted = gen(n);
    sort(temp_sorted.begin(), temp_sorted.end(), temp_sort);

    vector<int> kurtak_sorted_f = gen(m);
    sort(kurtak_sorted_f.begin(), kurtak_sorted_f.end(), kurtak_sort_f);

    vector<int> kurtak_sorted_s = gen(m);
    sort(kurtak_sorted_s.begin(), kurtak_sorted_s.end(), kurtak_sort_s);

    int kf = 0, ks = 0;
    set<int> kset;

    vector<vector<int>> vec(n);

    for (int i = 0; i < n; ) {
        int a = i, b = i;
        int t = temp[temp_sorted[i]];
        while (b < n && temp[temp_sorted[b]] == t)
            b++;
        b--;

        while (kf < m && kurtak[kurtak_sorted_f[kf]].first <= t) {
            kset.insert(kurtak_sorted_f[kf]);
            kf++;
        }

        while (ks < m && kurtak[kurtak_sorted_s[ks]].second < t) {
            kset.erase(kurtak_sorted_s[ks]);
            ks++;
        }

        int cnt = 0;
        vector<int> res;
        for (auto it : kset) {
            cnt++;
            if (cnt > 3)
                break;
            res.push_back(it);
        }

        for (int z = a; z <= b; z++) {
            vec[temp_sorted[z]] = res;
        }

        i = b + 1;
    }

    vector<int> res(n, -1);

    set<int> st[3];
    for (int i = 0; i < n; i++) {
        if (vec[i].size() == 0) {
            printf("No\n");
            return 0;
        }
        st[vec[i].size() - 1].insert(i);
    }

    while (true) {
        int k = 0;
        while (k < 3 && st[k].size() == 0)
            k++;
        if (k == 3)
            break;
   
        int pos = *st[k].begin();
        st[k].erase(pos);

        int val = -1;
        for (auto it : vec[pos]) {
            if (pos - 1 >= 0 && res[pos - 1] == it)
                continue;
            if (pos + 1 < n && res[pos + 1] == it)
                continue;
            val = it;
        }
        if (val == -1) {
            printf("No\n");
            return 0;
        }

        res[pos] = val;
        for (int a = -1; a <= 1; a += 2) {
            if (pos - a >= 0 && pos - a < n && res[pos - a] == -1) {
                int ind = -1;
                for (int z = 0; z < vec[pos - a].size(); z++) {
                    if (vec[pos - a][z] == val)
                        ind = z;
                }
                if (ind != -1)
                    vec[pos - a].erase(vec[pos - a].begin() + ind);
                else
                    continue;
                st[vec[pos - a].size()].erase(pos - a);
                if (vec[pos - a].size() == 0) {
                    printf("No\n");
                    return 0;
                }
                st[vec[pos - a].size() - 1].insert(pos - a);
            }
        }
    }

    printf("Yes\n");
    for (auto it : res)
        printf("%d ", it + 1);
}