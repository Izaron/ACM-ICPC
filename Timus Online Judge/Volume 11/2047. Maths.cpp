// The solution of the problem was written by Izaron
// Date: 12:47:42   2 May 2016
// Execution time: 0.343

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

const int N = 300 * 10000 + 5;

int dels[N];
int tmpar[N];
int len[N];
bool used[N];

int main() {
	fill(dels, dels + N, 1);
	fill(len, len + N, 0);
	fill(used, used + N, false);

	for (int i = 2; i < N; i++) {
		if (used[i])
			continue;
		for (int z = 2 * i; z < N; z += i) {
			used[z] = true;
		}
		int curr = i, old = i;

		for (int z = i; z < N; z += i) {
			tmpar[z] = 1;
		}

		while (true) {
			for (int z = curr; z < N; z += curr) {
				tmpar[z]++;
			}
			curr *= i;
			if (curr >= N || curr <= old)
				break;
			old = curr;
		}

		for (int z = i; z < N; z += i) {
			dels[z] *= tmpar[z];
		}
	}

	int maxi = 0, v = 0;
	for (int i = 1; i < N; i++) {
		len[i] = len[i - dels[i]] + 1;
		if (len[i] > maxi) {
			maxi = len[i];
			v = i;
		}
	}

	vector<int> vec;
	while (true) {
		vec.pb(v);
		if (v == 0)
			break;
		v -= dels[v];
	}
	reverse(vec.begin(), vec.end());

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << vec[i] - vec[i - 1] << " ";
	}
}

