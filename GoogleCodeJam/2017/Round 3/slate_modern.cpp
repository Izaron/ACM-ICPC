#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

struct solver {
	int r, c;
	int n;
	ll d;

	vector<pll> pos;
	vector<ll> values;

	ll work() {
		cin >> r >> c >> n >> d;
		pos.resize(n);
		values.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> pos[i].first >> pos[i].second >> values[i];
			pos[i].first--; pos[i].second--;
		}

		ll ans = 0;
		for (int q = 0; q < r; q++) {
			for (int z = 0; z < c; z++) {
				ll a = LLONG_MIN, b = LLONG_MAX;
				for (int i = 0; i < n; i++) {
					ll dist = abs(pos[i].first - q) + abs(pos[i].second - z);
					a = max(a, values[i] - dist * d);
					b = min(b, values[i] + dist * d);
					if (a > b)
						return -1;
				}
				ans += b;
				ans %= mod;
			}
		}

		return ans;
	}

	void solve() {
		ll w = work();
		if (w == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << w << endl;
	}
} s;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << "Case #" << i + 1 << ": ";
		s.solve();
	}
}