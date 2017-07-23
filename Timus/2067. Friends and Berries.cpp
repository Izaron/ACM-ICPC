// The solution of the problem was written by Izaron
// Date: 13:20:48   1 May 2016
// Execution time: 0.14

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
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tt;

const int N = 2 * 100000 + 5;

int n;
ll xs[N];
ll ys[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int s, r;
		scanf("%d%d", &s, &r);
		xs[i] = s;
		ys[i] = r;
	}

	for (int i = 1; i < n; i++) {
		xs[i] -= xs[0];
		ys[i] -= ys[0];
	}

	xs[0] = 0;
	ys[0] = 0;
	ll x1 = xs[1], y1 = ys[1];
	bool can = true;
	vector<pll> xMin, xPl, yMin, yPl, vec;
	xMin.pb(mkp(0, 0));
	xPl.pb(mkp(0, 0));
	yMin.pb(mkp(0, 0));
	yPl.pb(mkp(0, 0));
	vec.pb(mkp(0, 0));

	for (int i = 1; i < n; i++) {
		if (y1 * xs[i] != ys[i] * x1) {
			can = false;
			break;
		}
		ll dist = xs[i] * xs[i] + ys[i] * ys[i];
		pll pr = mkp(dist, i);
		if (xs[i] < 0)
			xMin.pb(pr);
		if (xs[i] > 0)
			xPl.pb(pr);
		if (ys[i] < 0)
			yMin.pb(pr);
		if (ys[i] > 0)
			yPl.pb(pr);
	}

	sort(xMin.begin(), xMin.end());
	sort(xPl.begin(), xPl.end());
	sort(yMin.begin(), yMin.end());
	sort(yPl.begin(), yPl.end());

	if (!can) {
		printf("0");
		return 0;
	}

	vector<int> alls;

	int cnt = 100;
	for (int i = 0; i < min((int)xMin.size(), cnt); i++)
		alls.pb(xMin[i].second);
	for (int i = xMin.size() - 1; i >= max((int)xMin.size() - cnt, 0); i--)
		alls.pb(xMin[i].second);

	for (int i = 0; i < min((int)xPl.size(), cnt); i++)
		alls.pb(xPl[i].second);
	for (int i = xPl.size() - 1; i >= max((int)xPl.size() - cnt, 0); i--)
		alls.pb(xPl[i].second);

	for (int i = 0; i < min((int)yMin.size(), cnt); i++)
		alls.pb(yMin[i].second);
	for (int i = yMin.size() - 1; i >= max((int)yMin.size() - cnt, 0); i--)
		alls.pb(yMin[i].second);

	for (int i = 0; i < min((int)yPl.size(), cnt); i++)
		alls.pb(yPl[i].second);
	for (int i = yPl.size() - 1; i >= max((int)yPl.size() - cnt, 0); i--)
		alls.pb(yPl[i].second);

	ll maxi = 0;
	int a = 0, b = 1;

	for (int i = 0; i < alls.size(); i++) {
		for (int z = i + 1; z < alls.size(); z++) {
			ll dist = (xs[alls[i]] - xs[alls[z]]) * (xs[alls[i]] - xs[alls[z]]) +
					(ys[alls[i]] - ys[alls[z]]) * (ys[alls[i]] - ys[alls[z]]);
			if (dist > maxi) {
				maxi = dist;
				a = alls[i];
				b = alls[z];
			}
		}
	}

	printf("1\n");
	printf("%d %d", a + 1, b + 1);
}



