// The solution of the problem was written by Izaron
// Date: 16:56:28   25 Jul 2017
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > start(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        start[i].resize(m);
        for (int z = 0; z < m; z++) {
            start[i][z] = (s[z] == 'W' ? 0 : 1);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int z = 0; z < m; z++) {
            int cnt;
            cin >> cnt;
            if (cnt % 2 == 0)
                continue;
            for (int a = 0; a < n; a++) {
                for (int b = 0; b < m; b++) {
                    int dist = (i - a) * (i - a) + (b - z) * (b - z);
                    int sq = (int)(sqrt(dist));
                    if (sq * sq == dist) {
                        start[a][b] ^= 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int z = 0; z < m; z++)
            cout << (start[i][z] == 0 ? 'W' : 'B');
        cout << endl;
    }
}
