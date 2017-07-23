#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

int main() {
    ll n;
    cin >> n;
    int cnt = 0;
    for (ll i = 2; i <= 2e7; i++) {
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
    }
    if (n != 1)
        cnt++;
    if (cnt == 20)
        cout << "Yes";
    else
        cout << "No";
}
