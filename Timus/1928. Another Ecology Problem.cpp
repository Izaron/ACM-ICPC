#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
#include <map>
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//typedef tuple<int, int, int> tt;

const int N = 10000 + 5;

int ansA[N];
int ansB[N];
int n, m, k;

pii dp(int v) {
	if (v < 0)
		return mkp(0, 0);
	if (v == 0)
		return mkp(0, 0);
	if (ansA[v] != -1) {
		return mkp(ansA[v], ansB[v]);
	}

	pii ansi = mkp(0, 0);
	for (int i = 1; i <= k; i++) {
		pii dfs = dp(v - i);
		pii curr = mkp(dfs.second + i, dfs.first);
		if (v - i < 0)
			curr.first = dfs.second + m;
		if (curr.first > ansi.first) {
			ansi = curr;
		} else if (curr.first == ansi.first && curr.second < ansi.second) {
			ansi = curr;
		}
	}
	ansA[v] = ansi.first;
	ansB[v] = ansi.second;

	return mkp(ansA[v], ansB[v]);
}

int main() {
	fill(ansA, ansA + N, -1);
	fill(ansB, ansB + N, -1);
	cin >> n >> m >> k;
	pii pr = dp(n);
	cout << pr.first << " " << pr.second;
}
