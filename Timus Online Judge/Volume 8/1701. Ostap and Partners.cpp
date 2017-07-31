// The solution of the problem was written by Izaron
// Date: 16:56:39   29 Jul 2017
// Execution time: 0.124

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <limits.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

const int maxn = 5e4 + 5;

int n, m;
vector<pii> neig[maxn];
vector<int> num[maxn];
vector<int> res;

bool bfs(vector<bool>& used, vector<int>& res, int v, int bound) {
    //cerr << "bfs " << v << endl;
    vector<int> vec = { v };
    vector<int> diff = { 0 };

    int mini = 0;

    for (int i = 0; i < vec.size(); i++) {
        int cur = vec[i];
        int d = diff[i];
        //cerr << "cur & dif " << cur << " " << d << endl;
        mini = min(mini, d);
        if (used[cur]) {
            if (res[cur] != d)
                return false;
            continue;
        }
        used[cur] = true;
        res[cur] = d;
        for (int z = 0; z < neig[cur].size(); z++) {
            if (num[cur][z] > bound)
                continue;
            int to = neig[cur][z].first;
            int add = neig[cur][z].second;
            vec.push_back(to);
            diff.push_back(d + add);
        }
    }

    for (int i = 0; i < vec.size(); i++)
        res[vec[i]] = diff[i] - mini;

    return true;
}

// bound is [0..m-1]
bool can(int bound) {
    //cerr << "b " << bound << endl;
    vector<bool> used(n);
    fill(res.begin(), res.end(), 0);
    for (int i = 0; i < n; i++) {
        if (used[i])
            continue;
        if (!bfs(used, res, i, bound)) {
            //cerr << "fak" << endl;
            return false;
        }
    }
    if (res[0] != 0)
        return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        neig[a].push_back({ b, -c });
        neig[b].push_back({ a, c });
        num[a].push_back(i);
        num[b].push_back(i);
    }

    res.resize(n);

    if (can(m - 1)) {
        cout << "Possible" << endl;
        for (auto it : res)
            cout << it << endl;
    } else {
        int a = 0, b = m - 1;
        while (a != b) {
            int la = a, lb = b;
            int mid = (a + b) / 2;
            if (!can(mid))
                b = mid;
            else
                a = mid;
            if (la == a && lb == b) {
                if (!can(a))
                    b = a;
                else
                    a = b;
            }
        }
        cout << "Impossible after " << a + 1 << " statements" << endl;
    }
}
