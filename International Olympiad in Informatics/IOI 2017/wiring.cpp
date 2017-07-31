#include "wiring.h"
#include <limits.h>
#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<ll> vll;


ll solve2(vector<int>& a, vector<int>& b) {
    ll ans = 0;
    for (int i = 0; i < a.size(); i++)
        ans += b[0] - a[i];
    for (int i = 1; i < min(a.size(), b.size()); i++)
        ans += b[i] - b[0];
    if (b.size() > a.size()) {
        for (int i = a.size(); i < b.size(); i++)
            ans += b[i] - a.back();
    }
    return ans;
}

vector<vll> calced;

ll dp1(vint& a, vint& b, int x, int y) {
    if (x == a.size() && y == b.size())
        return 0;
    if (x == a.size() || y == b.size())
        return LLONG_MAX / 2;
    ll ans = calced[x][y];
    if (ans != -1)
        return ans;
    ans = LLONG_MAX / 2;
    ans = min(ans, abs(a[x] - b[y]) + dp1(a, b, x + 1, y));
    ans = min(ans, abs(a[x] - b[y]) + dp1(a, b, x, y + 1));
    ans = min(ans, abs(a[x] - b[y]) + dp1(a, b, x + 1, y + 1));
    calced[x][y] = ans;
    return ans;
}

ll solve1(vector<int> a, vector<int> b) {
	calced.clear();
    calced.resize(a.size());
    for (int i = 0; i < a.size(); i++)
        calced[i].resize(b.size(), -1);
    return dp1(a, b, 0, 0);
}

vector<ll> calc;
vector<int> pos;
vector<int> color;
vector<vll> gens;

void gen(int v) {
    vector<int> ra, rb;
    ra.push_back(pos[v]);
    int cnt = 0;
    for (int i = v + 1; i < pos.size(); i++) {
        if (color[i] != color[i - 1])
            cnt++;
        if (cnt > 1)
            break;
        if (cnt == 0)
            ra.push_back(pos[i]);
        else
            rb.push_back(pos[i]);
        if (rb.empty())
            gens[v].push_back(LLONG_MAX / 3);
        else
            gens[v].push_back(solve2(ra, rb));
    }
}

ll dp3(int a) {
    if (a == pos.size())
        return 0;

    ll ans = calc[a];
    if (ans != -1)
        return ans;

    ans = LLONG_MAX / 3;
    int cnt = 0;
    for (int i = a + 1; i < pos.size(); i++) {
        if (cnt >= gens[a].size())
            break;
        ans = min(ans, gens[a][cnt] + dp3(i + 1));
        ans = min(ans, gens[a][cnt] + dp3(i));
        cnt++;
    }

    calc[a] = ans;
    return ans;
}

ll solve3(vector<int> a, vector<int> b) {
    if (a[0] > b[0])
        return solve3(b, a);

    vector<pii> vec(a.size() + b.size());
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
        vec[cnt++] = { a[i], 0 };
    for (int i = 0; i < b.size(); i++)
        vec[cnt++] = { b[i], 1 };
    sort(vec.begin(), vec.end());
    pos.resize(vec.size());
    color.resize(vec.size());
    for (int i = 0; i < vec.size(); i++) {
        pos[i] = vec[i].first;
        color[i] = vec[i].second;
    }
    calc.resize(vec.size(), -1);

    gens.resize(vec.size());
    for (int i = 0; i < vec.size(); i++)
        gen(i);

    return dp3(0);
}

ll sum4(vector<ll>& sums, ll v) {
	if (v < 0)
		return 0;
	return sums[v];
}

ll val4(vector<ll>& vals, ll v) {
	if (v < 0)
		return 0;
	return vals[v];
}

ll calc4(vector<ll>& sums, vector<ll>& vals, ll a, ll bound, ll b) {
	//cerr << "Calculating " << a << " " << bound << " " << b << " ";

	// [a..bound] and [bound+1..b]
	ll len1 = bound - a + 1;
	ll len2 = b - bound;

	// ans += b[0] - a[i]
	ll ans = val4(vals, bound + 1) * len1 - (sum4(sums, bound) - sum4(sums, a - 1));
	//cerr << ".." << ans << " ";

	// ans += b[i] - b[0]
	ans += (sum4(sums, bound + min(len1, len2)) - sum4(sums, bound)) - min(len1, len2) * val4(vals, bound + 1);
	//cerr << ".." << ans << " ";

	/*
	if (b.size() > a.size()) {
        for (int i = a.size(); i < b.size(); i++)
            ans += b[i] - a.back();
    }
	*/
	if (len2 > len1)
		ans += (sum4(sums, b) - sum4(sums, b - (len2 - len1))) - (len2 - len1) * val4(vals, bound);

	//cerr << "ans is " << ans << endl;
	return ans;
}

ll solve4(vector<int> a, vector<int> b) {
	//cerr << "Solving 4th subtask" << endl;
	vector<int> col(a.size() + b.size());
	int s = col.size();
	vector<ll> vals(s);
	vector<ll> sums(s);

	vector< pair<ll, int> > vec(s);
	for (int i = 0; i < a.size(); i++)
		vec[i] = make_pair(a[i], 0);
	for (int i = 0; i < b.size(); i++)
		vec[i + a.size()] = make_pair(b[i], 1);
	sort(vec.begin(), vec.end());

	for (int i = 0; i < s; i++) {
		col[i] = vec[i].second;
		sums[i] = vec[i].first;
		vals[i] = vec[i].first;
		if (i > 0)
			sums[i] += sums[i - 1];
	}

	vector<ll> ans(s);

	int last_0 = -1, last_1 = -1;
	int bound_0 = -1, bound_1 = -1;

	for (int i = 0; i < s; i++) {
		ll cur = LLONG_MAX / 3;
		ans[i] = cur;
		//cerr << "i = " << i << endl;
		if (col[i] == 0) {

			last_0 = i;
			bound_0 = i;
			if (bound_1 == -1) {
				continue;
			} else {
				while (true) {
					if (last_1 < 0 || col[last_1] != 1) {
						last_1++;
						break;
					}
					ll add = calc4(sums, vals, last_1, bound_1, i);
					if (last_1 == 0)
						add += min(ans[last_1], 0LL);
					else
						add += min(ans[last_1], ans[last_1 - 1]);
					add = min(add, LLONG_MAX / 3);
					if (add <= cur) {
						cur = add;
						last_1--;
					} else {
						last_1++;
						break;
					}
				}
			}

		} else {

			last_1 = i;
			bound_1 = i;
			if (bound_0 == -1) {
				continue;
			} else {
				while (true) {
					if (last_0 < 0 || col[last_0] != 0) {
						last_0++;
						break;
					}
					ll add = calc4(sums, vals, last_0, bound_0, i);
					if (last_0 == 0)
						add += min(ans[last_0], 0LL);
					else
						add += min(ans[last_0], ans[last_0 - 1]);
					add = min(add, LLONG_MAX / 3);
					if (add <= cur) {
						cur = add;
						last_0--;
					} else {
						last_0++;
						break;
					}
				}
			}

		}

		ans[i] = cur;
	}

	//for (int i = 0; i < s; i++) {
	//	cerr << "ANS " << i << ": " << ans[i] << endl;
	//}

	return ans[s - 1];
}

void test14() {
	srand(13);
	for (int t = 0; t < 10000; t++) {
		cout << "Test #" << t << endl;
		int a = (rand() % 100) + 1;
		int b = (rand() % 100) + 1;

		set<ll> st;
		for (int i = 0; i < a + b; i++) {
			while (true) {
				ll v = rand() % (1000000000 + 1);
				if (v < 0) {
					v += 1000000000 + 1;
					v %= 1000000000 + 1;
				}
				if (!st.count(v)) {
					st.insert(v);
					break;
				}
			}
		}

		vint v(a + b);
		for (int i = 0; i < a + b; i++) {
			v[i] = (*st.begin());
			st.erase(st.begin());
		}
		random_shuffle(v.begin(), v.end());
		vint va(a);
		vint vb(b);
		int cnt = 0;
		for (int i = 0; i < a; i++)
			va[i] = v[cnt++];
		for (int i = 0; i < b; i++)
			vb[i] = v[cnt++];

		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());

		cout << "vector A: ";
		for (auto it : va)
			cout << it << " ";
		cout << endl;

		cout << "vector B: ";
		for (auto it : vb)
			cout << it << " ";
		cout << endl;

		ll ans_1 = solve1(va, vb);
		ll ans_4 = solve4(va, vb);
		cout << "Ans dynamic: " << ans_1 << endl;
		cout << "Ans fast:    " << ans_4 << endl;

		if (ans_4 != ans_1) {
			cout << "ERROR!" << endl;
			throw 0;
		}
	}
}

ll min_total_length(vector<int> r, vector<int> b) {
	return solve4(r, b);
}
