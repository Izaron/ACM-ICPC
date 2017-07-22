#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

int main() {
    #ifndef HOME
    freopen("parallelepiped.in", "r", stdin);
    freopen("parallelepiped.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    map<pii, int> mp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        mp[{ a, b }]++;
    }

    // remove singles
    vector<pii> bad;
    for (auto it : mp) {
        if (it.second == 1)
            bad.push_back(it.first);
    }
    for (auto it : bad)
        mp.erase(it);
    for (auto& it : mp)
        it.second /= 2;

    // calc ans
    ll ans = -1;

    // (a, a, a)
    for (auto it : mp) {
        pii pr = it.first;
        if (pr.first == pr.second && it.second >= 3)
            ans = max(ans, (ll)(pr.first) * (ll)(pr.first) * (ll)(pr.first));
    }

    // (a, b, b) or (a, a, b)
    for (auto it : mp) {
        pii pr = it.first;
        if (pr.first != pr.second && it.second >= 2) {
            pii a = { pr.first, pr.first };
            pii b = { pr.second, pr.second };
            if (mp.count(a))
                ans = max(ans, (ll)(pr.first) * (ll)(pr.first) * (ll)(pr.second));
            if (mp.count(b))
                ans = max(ans, (ll)(pr.second) * (ll)(pr.second) * (ll)(pr.first));
        }
    }

    // (a, b, c)
    vector<pii> vec;
    for (auto it : mp) {
        if (it.first.first != it.first.second)
            vec.push_back(it.first);
    }

    vector< set<int> > kek(1e6 + 5);
    for (auto it : vec)
        kek[it.first].insert(it.second);

    for (int i = 0; i < vec.size(); i++) {
        int a = vec[i].first;
        int b = vec[i].second;

        if (kek[a].size() < kek[b].size()) {
            for (auto it : kek[a]) {
                if (kek[b].count(it)) {
                    ans = max(ans, (ll)(a) * (ll)(b) * (ll)(it));
                }
            }
        } else {
            for (auto it : kek[b]) {
                if (kek[a].count(it)) {
                    ans = max(ans, (ll)(a) * (ll)(b) * (ll)(it));
                }
            }
        }
    }

    // print
    cout << ans << endl;
}
