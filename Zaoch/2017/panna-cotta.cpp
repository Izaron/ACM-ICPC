#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = (ll)(1e18);

pll query(ll v) {
    if (v > maxn)
        return { 0, 1 };
    cout << "X " << v << endl;
    ll a, b;
    cin >> a >> b;
    return { a, b };
}

void play() {
    ll cur = 0;
    vector<pll> qus;
    vector<bool> can;
    qus.push_back({0, 1});
    can.push_back(true);

    for (ll pow = 5; pow >= 0; pow--) {
        pll qu = query(1LL << (cur + (1LL << pow)));
        qus.push_back(qu);
        if (qu.first == 0) {
            can.push_back(false);
        } else {
            cur += (1LL << pow);
            can.push_back(true);
        }
    }

    for (int i = qus.size() - 1; i >= 0; i--) {
        if (can[i]) {
            cout << "N " << qus[i].second << endl;
            break;
        }
    }

    string s;
    cin >> s;
    if (s == "Wrong")
        throw 0;
}

int main() {
    int g;
    cin >> g;
    for (int i = 0; i < g; i++)
        play();
}