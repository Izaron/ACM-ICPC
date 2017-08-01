#include "books.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vint;

const int maxn = 1000000 + 5;
const int mn = 6;

bool is_correct(vint v, int n) {
	//cerr << "Correctness of: ";
	//for (auto it : v)
	//	cerr << it << " " ;
	//cerr << endl;

	if (v[mn + 1] != 0)
		return false;

	for (int i = 0; i < n; i++) {
		if (v[i] != i) {
			return false;
		}
	}

	return true;
}

ll calc(vint p, int s) {
	if (s != 0 || p.size() > mn)
		throw 0;
	int n = p.size();

	//cerr << "calc: ";
	//for (auto it : p)
	//	cerr << it << " ";
	//cerr << endl;

	set<vint> used;

	// 1table, 2table, 3table, 4table, book, pos
	vint tmp = p;
	while (tmp.size() < mn)
		tmp.push_back(0);
	tmp.push_back(-1); tmp.push_back(0);

	set< pair<int, vint> > st;
	st.insert({0, tmp});

	while (!st.empty()) {
		pair<int, vint> pr = (*st.begin());
		st.erase(st.begin());

		vint cur = pr.second;
		int t = pr.first;

		if (is_correct(cur, n))
			return t;

		if (used.count(cur))
			continue;

		used.insert(cur);

		int carry = cur[mn], pos = cur[mn + 1];

		// move left
		if (pos - 1 >= 0) {
			vint tmp1 = cur;
			tmp1[mn + 1]--;
			st.insert({t + 1, tmp1});
		}

		// move right
		if (pos + 1 < n) {
			vint tmp2 = cur;
			tmp2[mn + 1]++;
			st.insert({t + 1, tmp2});
		}

		// swap books
		vint tmp3 = cur;
		swap(tmp3[pos], tmp3[mn]);
		st.insert({t, tmp3});
	}

	throw 0;
}

int maxi;
int dist;

void dfs(vector<bool>& used, vint& to, int v) {
    if (used[v])
        return;
    maxi = max(maxi, v);
    used[v] = true;
    dfs(used, to, to[v]);
}

ll clever(vint p, int s) {
    ll ans = 0;
    int n = p.size();
    for (int i = 0; i < n; i++)
        ans += abs(i - p[i]);
    vector<bool> vec(n);
    vector<bool> used(n);
    vint to = p;
    for (int i = 0; i < n; i++) {
        if (to[i] == i)
            to[i] = -1;
    }

    dist = 0;
    for (int i = 0; i < n; i++) {
        if (used[i])
            continue;
        if (to[i] == -1)
            continue;
        maxi = 0;
        dfs(used, to, i);
        if (dist <= i)
            ans += (i - dist) * 2;
        dist = max(dist, maxi);
    }

    return ans;
}

void test() {
    for (int n = 1; n <= mn; n++) {
    	vint v(n);
    	for (int i = 0; i < n; i++)
    		v[i] = i;
    	while (true) {
            ll aa = calc(v, 0);
    		ll bb = clever(v, 0);
    		cout << aa << " " << bb << endl;
            if (aa != bb) {
                cout << "ERROR!" << endl;
                for (auto it : v)
                    cout << it << " ";
                cout << endl;
            }
    		if (!next_permutation(v.begin(), v.end()))
    			break;
    	}
    }
}

ll minimum_walk(vint P, int s) {
	return clever(P, s);
}
