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
	int ms[26];
	fill(ms, ms + 26, 0);
	string s;
	int k;
	cin >> s >> k;

	set<char> st;
	for (int i = 0; i < s.size(); i++)
		st.ins(s[i]);
	if (k >= st.size()) {
		cout << s.size() << " " << 1;
		return 0;
	}
	for (int i = 0; i < s.size(); i++) {
		ms[s[i] - 'a']++;
	}
	sort(ms, ms + 26);
	reverse(ms, ms + 26);

	int tar = ms[k - 1];
	int sum = 0;
	for (int i = 0; i < k; i++)
		sum += ms[i];
	int nado = 0, iz = 0;
	for (int i = 0; i < 26; i++) {
		if (i < k && ms[i] == tar) {
			nado++;
			iz++;
		} else if (ms[i] == tar) {
			iz++;
		}
	}

	ll ans = 1;
	ll kk = 1;
	for (ll i = iz - nado + 1; i <= iz; i++) {
		ans *= i;
		ans /= kk;
		kk++;
	}

	cout << sum << " " << ans;
}

