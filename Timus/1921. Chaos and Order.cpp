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

const int N = 100 + 5;


int main() {
	int n, m, k, l;
	cin >> n >> m >> k >> l;
	char ms[N][N];
	bool rev = false;

	if (l - 1 > max(n, m)) {
		cout << "NO";
		return 0;
	}

	if (n == 1 || m == 1) {
		if (k == 1 && max(n, m) > l - 1) {
			cout << "NO";
			return 0;
		} else {
			cout << "YES" << endl;

			char ch = 'A';
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				for (int z = 0; z < m; z++) {
					cout << ch;
					cnt++;
					if (cnt >= l - 1) {
						cnt = 0;
						if (ch == 'A')
							ch = 'B';
						else
							ch = 'A';
					}
				}
				cout << endl;
			}
			return 0;
		}
	}

	if (k == 1) {
		if (l - 1 == n && l - 1 == m) {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				for (int z = 0; z < m; z++) {
					cout << 'A';
				}
				cout << endl;
			}
			return 0;
		} else {
			cout << "NO";
			return 0;
		}
	}

	if (l == 2) {
		if (k < 4) {
			cout << "NO";
			return 0;
		} else {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				char ch = 'A';
				if (i % 2 == 1)
					ch = 'C';
				for (int z = 0; z < m; z++) {
					cout << ch;
					ch++;
					if (ch > 'D')
						ch = 'A';
				}
				cout << endl;
			}
			return 0;
		}
	}

	if (n < m) {
		rev = true;
		swap(n, m);
	}

	if (l > 2 && k > 1) {
		for (int i = 0; i < m; i++) {
			char ch = 'A';
			int cnt = 0;
			if (i % 2 == 1)
				ch = 'B';
			for (int z = 0; z < n; z++) {
				cnt++;
				ms[z][i] = ch;
				if (cnt >= l - 1) {
					cnt = 0;
					if (ch == 'A')
						ch = 'B';
					else
						ch = 'A';
				}
			}
		}

		cout << "YES" << endl;
		if (!rev) {
			for (int i = 0; i < n; i++) {
				for (int z = 0; z < m; z++) {
					cout << ms[i][z];
				}
				cout << endl;
			}
		} else {
			for (int i = 0; i < m; i++) {
				for (int z = 0; z < n; z++) {
					cout << ms[z][i];
				}
				cout << endl;
			}
		}
	} else {
		cout << "NO";
	}
}
