// The solution of the problem was written by Izaron
// Date: 20:14:18   2 May 2016
// Execution time: 0.28

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
//typedef tuple<int, int, int> tt;

const int N = 100000 + 5;


int main() {
	int n;
	scanf("%d", &n);
	set<int> st;
	st.ins(1);
	map<int, int> mp;
	int gc = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		st.ins(tmp);
		mp[tmp]++;
		if (tmp != 1 && mp[tmp] >= 3) {
			cout << "infinity";
			return 0;
		}
		if (gc == 0)
			gc = tmp;
		else
			gc = __gcd(gc, tmp);
	}

	if (gc != 1) {
		cout << "infinity";
		return 0;
	}

	if (st.size() == 0) {
		cout << 0;
		return 0;
	}

	int ms[N], len[N];
	int ln = st.size();
	int cnt = 0;
	for (auto it : st) {
		ms[cnt] = it;
		len[cnt] = mp[it];
		cnt++;
	}

	int ans = 0;
	for (int i = ln - 1; i >= 0; i--) {
		if (ms[i] == 1)
			continue;
		int cnt = len[i];
		for (int z = i + 1; z < ln; z++) {
			if (ms[z] % ms[i] == 0) {
				cnt++;
			}
			if (ms[z] % ms[i] == 0) {
				len[i] = max(len[i], len[z] + 1);
			}
		}
		ans = max(ans, len[i]);
		if (cnt >= 3) {
			cout << "infinity";
			return 0;
		}
	}

	cout << ans;
}

