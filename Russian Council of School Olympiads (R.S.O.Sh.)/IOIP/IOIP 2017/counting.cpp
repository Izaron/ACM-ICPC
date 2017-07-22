#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;

int main() {
    #ifndef HOME
    freopen("counting.in", "r", stdin);
    freopen("counting.out", "w", stdout);
    #endif

    // input
    int r, g, b;
    cin >> g >> r >> b;
    ll ans = 0;

    vector<ll> gs(10), bs(10);
    vector< vector<ll> > rs(10);

    map<string, ll> mp_g, mp_b, mp_r;

    for (auto& it : rs)
        it.resize(10);

    // raw answer
    for (int i = 0; i < g; i++) {
        string s;
        cin >> s;
        gs[s.back() - '0']++;
        mp_g[s]++;
    }

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        rs[s[0] - '0'][s.back() - '0']++;
        mp_r[s]++;
    }

    for (int i = 0; i < b; i++) {
        string s;
        cin >> s;
        bs[s[0] - '0']++;
        mp_b[s]++;
    }

    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            ans += gs[a] * rs[a][b] * bs[b];
        }
    }

    for (auto it : mp_g) {
        string s = it.first;
        ans -= it.second * mp_b[s] * rs[s.back() - '0'][s[0] - '0'];
    }

    // remove wrong
    for (auto i : mp_r) {
        string s = i.first;
        if (s[0] == s.back()) {
            ll g_count = mp_g[s];
            ans -= g_count * i.second * bs[s.back() - '0'];

            ll b_count = mp_b[s];
            ans -= b_count * i.second * gs[s[0] - '0'];

            ans += 2 * i.second * g_count * b_count;
        }
    }

    // output
    cout << ans << endl;
}
