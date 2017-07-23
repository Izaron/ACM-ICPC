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


int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
ll ans[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

bool isVis(int year) {
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	if (year % 400 == 0)
		return true;
	return false;
}

void calcAll() {
	int inWeek = 0;
	for (int year = 1; year <= 400; year++) {
		if (isVis(year))
			month[1] = 29;
		else
			month[1] = 28;

		int cnt = 0;
		for (int i = 0; i < 12; i++) {
			if ((inWeek + 12) % 7 == 4) {
				cnt++;
			}
			inWeek += month[i];
			inWeek %= 7;
		}
		ans[cnt]++;
	}
}

void calcAdd(int to) {
	int inWeek = 0;
	for (int year = 1; year <= to; year++) {
		if (isVis(year))
			month[1] = 29;
		else
			month[1] = 28;

		int cnt = 0;
		for (int i = 0; i < 12; i++) {
			if ((inWeek + 12) % 7 == 4) {
				cnt++;
			}
			inWeek += month[i];
			inWeek %= 7;
		}
		ans[cnt]++;
	}
}

void calcMinus(int to) {
	int inWeek = 0;
	for (int year = 1; year <= to; year++) {
		if (isVis(year))
			month[1] = 29;
		else
			month[1] = 28;

		int cnt = 0;
		for (int i = 0; i < 12; i++) {
			if ((inWeek + 12) % 7 == 4) {
				cnt++;
			}
			inWeek += month[i];
			inWeek %= 7;
		}
		ans[cnt]--;
	}
}

int main() {
	//calcAll();
	//for (int i = 0; i < 13; i++) {
	//	cout << i << ": " << ans[i] << endl;
	//}

	ll a, b;
	cin >> a >> b;
	a--;
	ll cnt = b / 400;
	cnt -= a / 400;

	ans[1] = 171 * cnt;
	ans[2] = 170 * cnt;
	ans[3] = 59 * cnt;

	calcAdd(b - (b / 400) * 400);
	calcMinus(a - (a / 400) * 400);

	for (int i = 0; i < 13; i++) {
		cout << i << ": " << ans[i] << endl;
	}
}

