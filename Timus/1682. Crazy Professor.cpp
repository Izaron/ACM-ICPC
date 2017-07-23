// The solution of the problem was written by Izaron
// Date: 16:11:17   26 Jul 2016
// Execution time: 0.046

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

int k, n;
vector<int> parent;
vector<int> rang;

void make_set (int v) {
	parent[v] = v;
	rang[v] = 0;
}

int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (rang[a] < rang[b])
			swap (a, b);
		parent[b] = a;
		if (rang[a] == rang[b])
			++rang[a];
	}
}

int main() {
    cin >> k;

    rang.push_back(0);
    parent.push_back(0);

    vector<int> ost[maxn];
    vector<int> alls[maxn];

    set<int> bs;

    for (int a = 1; ; a++) {
        parent.push_back(0);
        rang.push_back(0);

        if (a >= 100000) {
            cout << -1;
            return 0;
        }

        make_set(a);

        bs.clear();

        // b + a * a === 0
        /*for (int b = 1; b < a; b++) {
            if ((b + a * a) % k == 0) {
                bs.insert(b);
            }
        }*/

        ll ak = (ll)(a) * (ll)(a);
        ak %= k;

        for (auto it : alls[(k - ak) % k]) {
            bs.insert(it);
        }

        // a + b * b === 0
        for (auto it : ost[k - (a % k)]) {
            bs.insert(it);
        }

        for (auto it : bs) {
            int sa = find_set(a), sb = find_set(it);
            if (sa == sb) {
                cout << a;
                return 0;
            }
            union_sets(a, it);
        }

        // other
        ost[ak].push_back(a);
        alls[a % k].push_back(a);
    }
}
