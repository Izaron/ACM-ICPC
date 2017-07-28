// The solution of the problem was written by Izaron
// Date: 16:38:59   25 Jul 2017
// Execution time: 1.669

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector< vector<int> > vec;
    for (int i = 0; i < n; i++) {
        vector<int> v(m);
        for (int z = 0; z < m; z++)
            cin >> v[z];
        vec.push_back(v);

        if (vec.size() > 1) {
            vector<int>& lv = vec[vec.size() - 2];
            for (int z = 0; z < m; z++) {
                if (lv[z] == 0 || v[z] == 0)
                    continue;

                pii lefter;
                if (z > 0 && lv[z - 1] == 1)
                    lefter.first = 1;
                if (z > 0 && v[z - 1] == 1)
                    lefter.second = 1;
                if (lefter.first != lefter.second) {
                    cout << "No" << endl;
                    return 0;
                }

                pii righter;
                if (z + 1 < m && lv[z + 1] == 1)
                    righter.first = 1;
                if (z + 1 < m && v[z + 1] == 1)
                    righter.second = 1;
                if (righter.first != righter.second) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }

        if (vec.size() > 2)
            vec.erase(vec.begin());
    }

    cout << "Yes" << endl;
}
