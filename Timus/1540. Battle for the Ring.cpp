#include <bits/stdc++.h>
#define mkp make_pair
#define pb push_back
using namespace std;
typedef pair<int, int> pii;

struct solver {
    int n;
    vector<bool> used;
    vector<int> calc;
    vector< vector<int> > mini;
    vector<int> ms;
    vector<int> segA;
    vector<int> segB;
    vector<int> segMin;
    vector< set<int> > values;
    map<pii, int> mp;
    int xorSum;

    int dfs(int a, int b) {
        if (a > b)
            return -1;
        int num = segA.size();
        segA.pb(a);
        segB.pb(b);
        segMin.pb(mini[a][b]);

        pii pr = mkp(a, b);
        mp[pr] = num;

        set<int> st;
        for (int i = a; i <= b; i++)
            st.insert(ms[i]);
        values.pb(st);

        int cur = a;
        for (int i = a; i <= b; i++) {
            if (ms[i] <= mini[a][b]) {
                dfs(cur, i - 1);
                cur = i + 1;
            }
        }

        dfs(cur, b);
        return num;
    }

    int xorr(int a, int b);

    int xorr(int v) {
        if (used[v])
            return calc[v];
        used[v] = true;

        int sum = 0;
        set<int> st;
        for (auto z : values[v]) {
            int cur = segA[v];
            int curSum = 0;
            for (int i = segA[v]; i <= segB[v]; i++) {
                if (ms[i] <= z) {
                    curSum ^= xorr(cur, i - 1);
                    cur = i + 1;
                }
            }
            curSum ^= xorr(cur, segB[v]);
            st.insert(curSum);
        }
        while (st.count(sum))
            sum++;

        calc[v] = sum;
        return sum;
    }

    int work(vector<int> a) {
        n = a.size();
        ms = a;
        mini.resize(n);
        for (int i = 0; i < n; i++)
            mini[i].resize(n);
        used.resize(n);
        calc.resize(n);
        for (int i = 0; i < n; i++) {
            int cur = INT_MAX;
            for (int z = i; z < n; z++) {
                cur = min(cur, a[z]);
                mini[i][z] = cur;
            }
        }
        dfs(0, n - 1);
        xorSum = xorr(0, n - 1);
        return xorSum;
    }

    int getWay(int need) {
        set<int> can;
        for (auto z : values[0]) {
            int cur = 0;
            int curSum = 0;
            for (int i = 0; i < n; i++) {
                if (ms[i] <= z) {
                    curSum ^= xorr(cur, i - 1);
                    cur = i + 1;
                }
            }
            curSum ^= xorr(cur, n - 1);
            if (curSum == need)
                can.insert(z);
        }
        if (can.empty())
            return -1;
        for (int i = 0; i < n; i++) {
            if (can.count(ms[i]))
                return i;
        }
        return -1;
    }
};

int solver::xorr(int a, int b) {
    if (a > b)
        return 0;
    return xorr(mp[mkp(a, b)]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;
    vector<solver> vec;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int z = 0; z < n; z++)
            cin >> a[z];
        solver _solver;
        sum ^= _solver.work(a);
        vec.push_back(_solver);
    }
    if (sum == 0) {
        cout << "S";
    } else {
        cout << "G" << endl;
        for (int i = 0; i < vec.size(); i++) {
            int need = sum ^ vec[i].xorSum;
            int val = vec[i].getWay(need);
            if (val != -1) {
                cout << i + 1 << " " << val + 1;
                return 0;
            }
        }
    }
}
