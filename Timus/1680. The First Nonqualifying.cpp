// The solution of the problem was written by Izaron
// Date: 00:14:52   18 Aug 2016
// Execution time: 0.001

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define gv(v, i) get<i>(v)
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int maxn = 100000 + 5;

int main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #endif

    int y, n, q;
    cin >> y >> n >> q;
    string s;
    getline(cin, s);
    set<string> st;
    for (int i = 0, j = 0; i < n; i++) {
        getline(cin, s);
        string s1 = s.substr(0, (int)s.size() - 1);
        if (st.count(s1)) {
            continue;
        } else {
            st.insert(s1);
            j++;
            if (j == q + 1) {
                cout << s;
                return 0;
            }
        }
    }
}
