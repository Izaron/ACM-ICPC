// The solution of the problem was written by Izaron
// Date: 22:20:05   12 May 2016
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

const int N = 100000 + 5;

int m, n;
map<string, int> mp;
vector<pair<string, int>> vec;

int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        int cnt;
        string s;
        cin >> cnt >> s >> s;
        mp[s] = cnt;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int cnt;
        string s;
        cin >> cnt >> s >> s;
        vec.pb(mkp(s, cnt));
    }

    int tim = 0;
    while (vec.size() > 0) {
        tim++;
        string s = vec[0].first;
        int cnt = vec[0].second;
        if (mp[s] <= 0) {
            vec.erase(vec.begin());
            continue;
        }

        if (mp[s] < cnt) {
            if (vec.size() == 1) {
                cout << tim;
                return 0;
            } else {
                vec[0].second = mp[s];
                swap(vec[0], vec[1]);
            }
        } else {
            mp[s] -= cnt;
            vec.erase(vec.begin());
        }
    }

    cout << tim;
}