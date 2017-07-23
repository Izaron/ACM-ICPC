// The solution of the problem was written by Izaron
// Date: 17:58:37   1 May 2016
// Execution time: 0.031

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

const int N = 1000 + 5;


int n, m;
vector<int> posle[N];
vector<int> groups[N];
vector<int> as, bs;
int ans[N];
int groupTime[N];
int pos[N];
int squad[N];
int currGroups = 0;
int idealA, idealPos;

void recalc() {
	fill(pos, pos + n, -1);

	for (int i = 0; i < as.size(); i++) {
		pos[as[i]] = i;
	}

	for (int i = 0; i < bs.size(); i++) {
		pos[bs[i]] = i;
	}
}

void findIdeal(int v) {
	int a = as.size(), b = bs.size();
	for (int i = 0; i < posle[v].size(); i++) {
		int it = posle[v][i];
		if (pos[it] == -1)
			continue;
		if (squad[it] == 0) {
			a = min(a, pos[it] + 1);
		} else {
			b = min(b, pos[it] + 1);
		}
	}
	if (a <= b) {
		idealA = 0;
		idealPos = a;
	} else {
		idealA = 1;
		idealPos = b;
	}
}

void addGroup(int v) {
	for (int i = 0; i < groups[v].size(); i++) {
		int man = groups[v][i];
		findIdeal(man);
		if (idealA == 0) {
			squad[man] = 0;
			as.insert(as.begin() + idealPos, man);
		} else {
			squad[man] = 1;
			bs.insert(bs.begin() + idealPos, man);
		}
		recalc();
	}
}

int main() {
	fill(pos, pos + N, -1);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int curr = 0;
		while (true) {
			scanf("%d", &curr);
			if (curr == 0)
				break;
			posle[i].pb(curr - 1);
		}
	}

	for (int i = 0; i < m; i++) {
		int t, k;
		scanf("%d%d", &t, &k);
		groupTime[i] = t;
		for (int z = 0; z < k; z++) {
			int curr;
			scanf("%d", &curr);
			groups[i].pb(curr - 1);
		}
	}

	int times = 0;
	while (true) {
		if (as.size() == 0 && bs.size() == 0 && currGroups >= m)
			break;
		if (as.size() == 0 && bs.size() == 0 && times < groupTime[currGroups] - 1) {
			times = groupTime[currGroups] - 1;
			continue;
		}

		if (as.size() > 0) {
			ans[as[0]] = times;
			as.erase(as.begin());
		}

		if (bs.size() > 0) {
			ans[bs[0]] = times;
			bs.erase(bs.begin());
		}

		recalc();

		while (currGroups < m && groupTime[currGroups] == times) {
			addGroup(currGroups);
			currGroups++;
		}

		times++;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
		if (squad[i] == 0)
			printf("right\n");
		else
			printf("left\n");
	}
}

