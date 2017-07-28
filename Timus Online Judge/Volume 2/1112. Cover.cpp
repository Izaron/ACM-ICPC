// The solution of the problem was written by Izaron
// Date: 15:14:10   25 Jul 2017
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;

int n;
vector<pii> vec;
vector<int> calc;

int dp(int v) {
    if (calc[v] != -1)
        return calc[v];
    int ans = 1;
    for (int i = v + 1; i < n; i++) {
        if (vec[i].first >= vec[v].second) {
            ans = max(ans, 1 + dp(i));
        }
    }
    calc[v] = ans;
    return ans;
}

void vosst(int v) {
    int ans = 1;
    cout << vec[v].first << " " << vec[v].second << endl;
    if (calc[v] == 1)
        return;
    for (int i = v + 1; i < n; i++) {
        if (vec[i].first >= vec[v].second) {
            if (1 + dp(i) == calc[v]) {
                vosst(i);
                return;
            }
        }
    }
}

int main() {
    cin >> n;
    vec.resize(n);
    calc.resize(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
        if (vec[i].first > vec[i].second)
            swap(vec[i].first, vec[i].second);
    }
    sort(vec.begin(), vec.end());
    int kek = 0;
    for (int i = 0; i < n; i++)
        kek = max(kek, dp(i));
    cout << kek << endl;
    for (int i = 0; i < n; i++) {
        if (kek == dp(i)) {
            vosst(i);
            break;
        }
    }
}
