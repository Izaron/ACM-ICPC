// The solution of the problem was written by Izaron
// Date: 13:22:31   2 May 2016
// Execution time: 0.062

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


int n;
string s;
vector<char> vec;
vector<int> pos;
int ans[N];
int num[N];
bool used[N];
int mn;

bool contact(int a, int b) {
	char ca = vec[a], cb = vec[b];
	if (ca >= 'A' && ca <= 'Z' && tolower(ca) == cb)
		return true;
	else if (cb >= 'A' && cb <= 'Z' && tolower(cb) == ca)
		return true;
	return false;
}

bool isMain(int a) {
	char ca = vec[a];
	if (ca >= 'A' && ca <= 'Z')
		return true;
	return false;
}

void dfs(int v) {
	int a = v, b = v + 1;

	while (true) {
		if (a < 0 || b >= (int)vec.size())
			break;
		if (contact(a, b)) {
			mn += 2;
			ans[pos[a]] = pos[b];
			ans[pos[b]] = pos[a];
			pos.erase(pos.begin() + a);
			pos.erase(pos.begin() + a);
			vec.erase(vec.begin() + a);
			vec.erase(vec.begin() + a);
			a--;
			b--;
		} else {
			break;
		}
	}
}

int main() {
	cin >> n >> s;
	n *= 2;
	int cnt = 1;
	for (int i = 0; i < s.size(); i++) {
		vec.pb(s[i]);
		pos.pb(i);
		if (s[i] >= 'a' && s[i] <= 'z') {
			num[i] = cnt;
			cnt++;
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		if (contact(i, i + 1)) {
			dfs(i);
			i = -1;
		}
	}
	if (vec.size() != 0)
		cout << "Impossible";
	else {
		for (int i = 0; i < n; i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				cout << num[ans[i]] << " ";
			}
		}
	}
}

