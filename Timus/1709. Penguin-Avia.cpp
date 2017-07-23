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

int n, d, a;
vector<int> neig[N];
bool used[N];
string ans[N];

void dfs(int v, int last) {
	used[v] = true;
	for (auto it : neig[v]) {
		if (it == last)
			continue;
		if (used[it]) {
			ans[v][it] = 'd';
			ans[it][v] = 'd';
		} else {
			dfs(it, v);
		}
	}
}

int main() {
	fill(used, used + N, false);
	cin >> n >> d >> a;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int z = 0; z < s.size(); z++) {
			if (s[z] == '1') {
				neig[i].pb(z);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int z = 0; z < n; z++)
			ans[i] += '0';
	}

	vector<int> vec;
	for (int i = 0; i < n; i++) {
		if (used[i])
			continue;
		vec.pb(i);
		dfs(i, i);
	}

	for (int i = 1; i < vec.size(); i++) {
		ans[vec[i - 1]][vec[i]] = 'a';
		ans[vec[i]][vec[i - 1]] = 'a';
	}

	ll cost = 0;
	for (int i = 0; i < n; i++) {
		for (int z = 0; z < n; z++) {
			if (ans[i][z] == 'a')
				cost += a;
			else if (ans[i][z] == 'd')
				cost += d;
		}
	}

	cout << cost / 2 << endl;
	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;
}

