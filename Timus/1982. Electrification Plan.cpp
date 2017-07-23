// The solution of the problem was written by Izaron
// Date: 23:02:20   1 May 2016
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <bitset>
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tt;

const int N = 100 + 5;

int n, k;
bool good[N];
vector<int> neig[N];

void dfs(int v, int last) {
	good[v] = true;
	for (auto it : neig[v]) {
		if (it == last)
			continue;
		dfs(it, v);
	}
}

int main() {
	scanf("%d%d", &n, &k);
	fill(good, good + N, false);
	for (int i = 0; i < k; i++) {
		int tmp;
		scanf("%d", &tmp);
		good[tmp - 1] = true;
	}

	vector<tt> vec;
	for (int i = 0; i < n; i++) {
		for (int z = 0; z < n; z++) {
			int way;
			scanf("%d", &way);
			if (i <= z)
				continue;
			vec.pb(mt(way, i, z));
		}
	}
	sort(vec.begin(), vec.end());

	int ans = 0;
	for (int i = 0; i < vec.size(); i++) {
		int cost = get<0>(vec[i]);
		int a = get<1>(vec[i]);
		int b = get<2>(vec[i]);
		if (good[a] && good[b])
			continue;
		ans += cost;
		neig[a].pb(b);
		neig[b].pb(a);
		if (good[a] || good[b])
			dfs(a, a);
	}

	printf("%d", ans);
}

