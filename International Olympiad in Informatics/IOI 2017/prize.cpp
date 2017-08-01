#include "prize.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vint;

const int maxn = 2e5 + 5;

map<int, pii> calced;
set<int> st[maxn];

pii _ask(int v) {
	if (calced.count(v))
		return calced[v];
	vector<int> r = ask(v);
	pii pr = { r[0], r[1] };
	calced[v] = pr;
	return pr;
}

bool can(int v, int minus, int all) {
	pii p = _ask(v);
	if (p.first + p.second != all)
		return true;
	else
		st[p.first].insert(v);
	if (p.first > minus)
		return true;
	return false;
}

bool is_diamond(int v) {
	pii p = _ask(v);
	return p.first + p.second == 0;
}

int find_best(int n) {
	int big = 0;
	for (int i = 0; i < min(n, 475); i++) {
		pii pr = _ask(i);
		big = max(big, pr.first + pr.second);
		if (pr.first + pr.second == 0)
			return i;
	}

	//cerr << "Big count is " << big << endl;

	int pos = -1;
	for (int i = 0; i < big; i++) {
		int a = pos + 1, b = n - 1;

		for (int z = 0; z <= i; z++) {
			if (!st[z].empty()) {
				a = max(a, *st[z].rbegin() + 1);
			}
		}

		for (int z = i + 1; z < maxn; z++) {
			if (!st[z].empty()) {
				b = min(b, *st[z].begin());
			}
		}

		while (a != b) {
			int la = a, lb = b;
			int mid = (a + b) / 2;
			if (can(mid, i, big))
				b = mid;
			else
				a = mid + 1;
			if (la == a && lb == b) {
				if (can(mid, a, big))
					b = a;
				else
					a = b;
			}
		}

		//cerr << "Big pos is " << a << endl;
		pos = a;

		// check
		if (is_diamond(pos))
			return pos;
	}

	throw 0;
}
