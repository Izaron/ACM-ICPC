#include "simurgh.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vint;

const int maxn = 500 + 5;

int n;
set<pii> to[maxn];
set<pii> built[maxn];
vint a;
vint b;
set<int> vertices;
set<int> exists;
vector<bool> used;

void build_tree(int v) {
	used[v] = true;
	for (auto it : to[v]) {
		int vert = it.first, ind = it.second;
		if (used[vert])
			continue;
		built[v].insert({ vert, ind });
		built[vert].insert({ v, ind });
		vertices.insert(ind);
		build_tree(vert);
	}
}

void dfs(set<int>& cont, int v) {
	used[v] = true;
	cont.insert(v);
	for (auto it : built[v]) {
		int vert = it.first, ind = it.second;
		if (used[vert])
			continue;
		dfs(cont, vert);
	}
}

set<int> bad;
set<int> good;
map<int, int> mp;

int calc_max_edge(set<int>& a, set<int>& b, int p) {
	int ans = -1, good_ans = -1, ret = -1;
	vector<int> r(n - 1);
	map<int, int> ank;

	for (auto v : a) {
		// V is in the first group
		vector<int> res;
		vector<int> inds;
		for (auto it : to[v]) {
			int vert = it.first, ind = it.second;
			if (!b.count(vert))
				continue;
			if (bad.count(ind))
				continue;
			int cur_ans;
			if (good_ans != -1 && good.count(ind)) {
				cur_ans = good_ans;
			} else {
				int cnt = 0;
				for (auto it : vertices)
					r[cnt++] = it;
				r[cnt++] = ind;
				cur_ans = count_common_roads(r);
				mp[ind] = cur_ans - p;
				if (good.count(ind))
					good_ans = max(good_ans, cur_ans);
			}
			res.push_back(cur_ans);
			inds.push_back(ind);
			if (cur_ans > ans) {
				ans = cur_ans;
				ret = ind;
			}
		}

		for (int i = 0; i < res.size(); i++)
			ank[inds[i]] = res[i];
	}

	if (good_ans < ans)
		good.clear();

	for (auto it : ank) {
		if (it.second < ans)
			bad.insert(it.first);
		else
			good.insert(it.first);
	}

	return ret;
}

void work() {
	set<int> vs = vertices;
	int p = 0;
	while (!vs.empty()) {
		int ind = *vs.begin();
		vs.erase(ind);
		#ifdef USE_CERR
		cerr << "CHECKING EDGE " << ind << endl;
		#endif

		int aa = a[ind], bb = b[ind];
		built[aa].erase({ bb, ind });
		built[bb].erase({ aa, ind });
		fill(used.begin(), used.end(), false);

		set<int> cont_a, cont_b;
		for (int i = 0; i < n; i++) {
			if (used[i])
				continue;
			if (cont_a.empty())
				dfs(cont_a, i);
			else
				dfs(cont_b, i);
		}

		#ifdef USE_CERR
		cerr << "set A: ";
		for (auto it : cont_a)
			cerr << it << " ";
		cerr << endl;

		cerr << "set B: ";
		for (auto it : cont_b)
			cerr << it << " ";
		cerr << endl;
		#endif

		vertices.erase(ind);
		int add = calc_max_edge(cont_a, cont_b, p);
		p++;
		#ifdef USE_CERR
		cerr << "NEW EDGE IS " << add << endl;
		#endif
		vertices.insert(add);

		int a1 = a[add];
		int b1 = b[add];
		built[a1].insert({ b1, add });
		built[b1].insert({ a1, add });
	}
}

vint find_roads(int N, vint u, vint v) {
	n = N;
	a = u; b = v;
	for (int i = 0; i < u.size(); i++) {
		to[u[i]].insert({ v[i], i });
		to[v[i]].insert({ u[i], i });
		exists.insert(i);
	}

	used.resize(n);
	build_tree(0);

	#ifdef USE_CERR
	cerr << "built tree:" << endl;
	for (int i = 0; i < n; i++) {
		for (auto it : built[i]) {
			if (it.first > i)
				cerr << i << " " << it.first << " num is " << it.second << endl;
		}
	}
	#endif

	work();

	vector<int> r(n - 1);
	int cnt = 0;
	for (auto it : vertices)
		r[cnt++] = it;
	return r;
}
