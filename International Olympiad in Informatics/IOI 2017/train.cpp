#include "train.h"
#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector<int> vint;

const int maxn = 5000 + 5;

// owner, charging, track A->B
vint a, r, u, v;
set<int> to[maxn];
set<int> back[maxn];
int n, m;

struct solver_1 {
	vector<int> calced;

	void init() {
		calced.resize(n, -1);
	}

	bool check() {
		for (int i = 0; i < n; i++) {
			for (auto it : to[i]) {
				if (it != i && it != i + 1)
					return false;
			}
		}
		return true;
	}

	int solve(int s) {
		int& ans = calced[s];
		if (ans != -1)
			return ans;
		set<int> possible;

		if (to[s].count(s))
			possible.insert(r[s]);
		if (to[s].count(s + 1))
			possible.insert(solve(s + 1));

		if (a[s] == 0)
			ans = (*possible.begin());
		else
			ans = (*possible.rbegin());

		return ans;
	}

	vint solve_all() {
		init();
		vint res(n);
		for (int i = 0; i < n; i++)
			res[i] = solve(i);
		return res;
	}
} s1;

struct solver_3 {

	vector<int> timer;
	int glob;
	vector<bool> goods;
	vint pos;

	bool good(int v) {
		// if we can reach V in cycle from V
		int cnt = 0;
		pos[cnt++] = v;
		for (int i = 0; i < cnt; i++) {
			int cur = pos[i];
			if (cur == v && i > 0)
				return true;
			if (timer[cur] == glob)
				continue;
			timer[cur] = glob;
			for (auto it : to[cur])
				pos[cnt++] = it;
		}
		return false;
	}

	int solve(int v) {
		int cnt = 0;
		pos[cnt++] = v;
		for (int i = 0; i < cnt; i++) {
			int cur = pos[i];
			if (goods[cur])
				return 1;
			if (timer[cur] == glob)
				continue;
			timer[cur] = glob;
			for (auto it : to[cur])
				pos[cnt++] = it;
		}
		return 0;
	}

	void init() {
		pos.resize(n + m);
		timer.resize(n);
		goods.resize(n);
		glob = 1;
		for (int i = 0; i < n; i++) {
			glob++;
			if (r[i] == 1)
				goods[i] = good(i);
		}
	}

	bool check() {
		for (int i = 0; i < n; i++)
			if (a[i] != 1)
				return false;
		return true;
	}

	vint solve_all() {
		init();
		vint res(n);
		for (int i = 0; i < n; i++) {
			glob++;
			res[i] = solve(i);
		}
		return res;
	}
} s3;

struct solver_4 {

	vector<int> timer;
	int glob;
	vector<bool> goods;
	vector<int> calced;
	vector<int> ans;
	vint pos;

	bool good(int v) {
		// if we can reach V in cycle from V
		int cnt = 0;
		pos[cnt++] = v;
		for (int i = 0; i < cnt; i++) {
			int cur = pos[i];
			if (cur == v && i > 0)
				return true;
			if (r[cur] == 1)
				continue;
			if (timer[cur] == glob)
				continue;
			timer[cur] = glob;
			for (auto it : to[cur])
				pos[cnt++] = it;
		}
		return false;
	}

	void calc() {
		ans.resize(n, 1);
		vector<int> vec;

		for (int i = 0; i < n; i++) {
			glob++;
			if (r[i] == 0) {
				goods[i] = good(i);
				if (goods[i])
					vec.push_back(i);
			}
		}

		for (int i = 0; i < vec.size(); i++) {
			int v = vec[i];
			if (ans[v] == 0)
				continue;
			ans[v] = 0;
			for (auto it : back[v])
				vec.push_back(it);
		}
	}

	int solve(int v) {
		int cnt = 0;
		pos[cnt++] = v;
		for (int i = 0; i < cnt; i++) {
			int cur = pos[i];
			if (goods[cur])
				return 0;
			if (timer[cur] == glob)
				continue;
			timer[cur] = glob;
			for (auto it : to[cur])
				pos[cnt++] = it;
		}
		return 1;
	}

	void init() {
		pos.resize(n + m);
		timer.resize(n);
		goods.resize(n);
		calced.resize(n, -1);
		glob = 1;

		calc();
	}

	bool check() {
		for (int i = 0; i < n; i++)
			if (a[i] != 0)
				return false;
		return true;
	}

	vint solve_all() {
		init();
		vint res(n);
		for (int i = 0; i < n; i++) {
			glob++;
			res[i] = ans[i];
		}
		return res;
	}
} s4;

void calc_to() {
	for (int i = 0; i < m; i++) {
		to[u[i]].insert(v[i]);
		back[v[i]].insert(u[i]);
	}
}

vint solve() {
	if (s1.check())
		return s1.solve_all();
	if (s3.check())
		return s3.solve_all();
	if (s4.check())
		return s4.solve_all();
	throw 0;
}

vint who_wins(vint A, vint R, vint U, vint V) {
	a = A; r = R; u = U; v = V;
	n = a.size();
	m = u.size();
	calc_to();

	return solve();
}
