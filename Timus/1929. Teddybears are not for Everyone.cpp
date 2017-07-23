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

const int N = 100000 + 5;


int main() {
	int n, m;
	cin >> n >> m;
	bool boy[N];
	fill(boy, boy + N, false);
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		boy[tmp - 1] = true;
	}

	int ans = 0;
	for (int a = 1; a < n; a++) {
		for (int b = a + 1; b < n; b++) {
			int haters = m;
			if (boy[0])
				haters--;
			if (boy[a])
				haters--;
			if (boy[b])
				haters--;
			if (haters == m)
				continue;
			if (haters * 2 >= n - 3 - haters) {
				ans++;
			}
		}
	}

	cout << ans;
}
