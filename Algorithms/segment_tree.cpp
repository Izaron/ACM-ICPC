#include <vector>
#include <functional>
#include <iostream>
using namespace std;

template<class T>
class segment_tree {
  private:
	int n;
	vector<T> t;

	function<T(T, T)> effect_func;
	T neutral_value;

	void build(vector<T>& vec, int v, int l, int r) {
		if (l == r) {
			t[v] = vec[l];
		} else {
			build(vec, v * 2, l, (l + r) / 2);
			build(vec, v * 2 + 1, (l + r) / 2 + 1, r);
			t[v] = effect_func(t[v * 2], t[v * 2 + 1]);
		}
	}

	void set(int v, int l, int r, int pos, T& val) {
		if (l == r) {
			t[v] = val;
		} else {
			if (pos <= (l + r) / 2)
				set(v * 2, l, (l + r) / 2, pos, val);
			else
				set(v * 2 + 1, (l + r) / 2 + 1, r, pos, val);
			t[v] = effect_func(t[v * 2], t[v * 2 + 1]);
		}
	}

	T get(int v, int l, int r, int L, int R) {
		if (r < L || R < l)
			return neutral_value;
		if (l >= L && r <= R)
			return t[v];
		return effect_func(
			get(v * 2, l, (l + r) / 2, L, R),
			get(v * 2 + 1, (l + r) / 2 + 1, r, L, R)
		);
	}

  public:
	void init(vector<T> vec, function<T(T, T)> effect_func, T neutral_value) {
		this->n = (int) vec.size();
		this->effect_func = effect_func;
		this->neutral_value = neutral_value;
		t.resize(4 * n);
		build(vec, 1, 0, n - 1);
	}

	void init(int n, function<T(T, T)> effect_func, T neutral_value) {
		this->n = n;
		this->effect_func = effect_func;
		this->neutral_value = neutral_value;
		t.resize(4 * n);
		fill(t.begin(), t.end(), neutral_value);
	}

	void set(int pos, T val) {
		set(1, 0, n - 1, pos, val);
	}

	T get(int l, int r) {
		return get(1, 0, n - 1, l, r);
	}
};

int main() {
	segment_tree<int64_t> t;
	int n;
	cin >> n;
	vector<int64_t> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	t.init(vec, plus<int64_t>(), 0);
	
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		cout << t.get(l - 1, r - 1) << endl;
	}
}
