#include "../../../Algorithms/algos.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <limits.h>
using namespace std;
typedef int64_t ll;
typedef vector<int> vint;

ll factor(big_int& v) {
    ll bnd = 1e4;
    ll w = v.weak();
    if (w != -1)
        bnd = min(bnd, w - 1);

    for (ll i = 2; i <= bnd; i++) {
        if (v % i == 0)
            return i;
    }

    return -1;
}

string bits(ll v) {
    string s = "";
    while (v) {
        s += (char)((v % 2) + '0');
        v >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}

big_int conv(string s, int p) {
    big_int cur(1);
    big_int ret;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1')
            ret += cur;
        cur *= p;
    }
    return ret;
}

vint check(ll v) {
    string s = bits(v);
    vint res;
    for (int p = 2; p <= 10; p++) {
        big_int b = conv(s, p);
        ll cur = factor(b);
        if (cur == -1)
            return vint(0);
        res.push_back(cur);
    }
    return res;
}

void solve() {
    int n, j;
    cin >> n >> j;
    ll st = (1LL << (n - 1)) + 1;
    int cnt = 0;
    cout << endl;
    for (ll cur = st; ; cur += 2) {
        cerr << "Watch at " << bits(cur) << endl;
        vint v = check(cur);
        if (!v.empty()) {
            cnt++;
            cout << bits(cur) << " ";
            for (auto it : v)
                cout << it << " ";
            cout << endl;
            cerr << "WOAH COUNT " << cnt << endl;
            if (cnt == j)
                break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
