#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

vector<int> factorials(20);

struct solver {
	int l;

	map< int, vector<int> > links;
	vector<int> values;
	vector<int> cnt;
	map<int, int> ans_map;

	int get_sum(int v) {
		int sum = 0;
		while (v > 0) {
			sum += v % 10;
			v /= 10;
		}
		return sum;
	}

	bool is_simple(int v) {
		return get_sum(v) <= l;
	}

	void calculate_simples(int sum, int cnt, int v) {
		if (cnt == l) {
			if (sum < l)
				values.push_back(v);
			return;
		}
		for (int i = 0; i <= sum; i++)
			calculate_simples(sum - i, cnt + 1, v * 10 + i);
	}

	int decay(int v) {
		fill(cnt.begin(), cnt.end(), 0);
		while (v > 0) {
			if (v % 10 > 0)
				cnt[(v % 10) - 1]++;
			v /= 10;
		}
		int ans = 0;
		for (int i = 0; i < l; i++) {
			ans *= 10;
			ans += cnt[i];
		}
		return ans;
	}

	void calculate_links() {
		for (auto it : values) {
			int decayed = decay(it);
			if (!is_simple(decayed))
				continue;
			cerr << "l = " << l << ", value " << it << " mutates to " << decayed << endl;
			links[decayed].push_back(it);
		}
	}

	int calc_combs(int v) {
		fill(cnt.begin(), cnt.end(), 0);

		int s = get_sum(v);

		int res = 0;
		while (v > 0) {
			cnt[res++] = v % 10;
			v /= 10;
		}

		int ans = factorials[s];
		for (int i = 0; i < l; i++)
			ans /= factorials[cnt[i]];
		ans *= factorials[l] / factorials[s] / factorials[l - s];
		return ans;
	}

	int calc_ans(int v) {
		if (ans_map.count(v))
			return ans_map[v];
		int ans = 1 + calc_combs(v);
		if (links.count(v)) {
			for (auto back_link : links[v]) {
				if (back_link == v) {
					ans--;
					continue;
				}

				ans--;
				ans += calc_ans(back_link);
			}
		}

		ans_map[v] = ans;
		return ans;
	}

	void init(int l) {
		this->l = l;
		cnt.resize(l);
		calculate_simples(l, 0, 0);
		calculate_links();
	}

	int solve(int v) {
		cerr << "solver " << l << " solves " << v << endl;
		if (!is_simple(v))
			return 1;
		return calc_ans(v);
	}
};

vector<solver> solvers(9);

int main() {
	factorials[0] = 1;
	for (int i = 1; i < (int) factorials.size(); i++)
		factorials[i] = factorials[i - 1] * i;

	for (int i = 0; i < (int) solvers.size(); i++)
		solvers[i].init(i + 1);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << "Case #" << i + 1 << ": ";

		string s;
		cin >> s;
		int len = (int) s.size();
		int v = 0;
		for (int z = 0; z < len; z++) {
			v *= 10;
			v += s[z] - '0';
		}
		cout << solvers[len - 1].solve(v) << endl;
	}
}
