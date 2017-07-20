#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

void sub() {
    ll n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    mp[n] = 1;
    ll res = -1;
    while (true) {
        pair<ll, ll> p = *mp.rbegin();
        if (k <= p.second) {
            res = p.first;
            break;
        }
        k -= p.second;
        mp.erase(p.first);

        p.first--;
        mp[p.first / 2] += p.second;
        mp[p.first - p.first / 2] += p.second;
    }
    
    res--;
    cout << res - res / 2 << " " << res / 2;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        sub();
        cout << endl;
    }
}
