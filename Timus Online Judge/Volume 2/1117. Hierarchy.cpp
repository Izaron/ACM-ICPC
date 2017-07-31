// The solution of the problem was written by Izaron
// Date: 15:58:31   29 Jul 2017
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <limits.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;


// from 1 to b
ll calc(ll b) {
    ll ans = 0;
    ll cur = 4;
    while (true) {
        ll ex = (b - 1) / cur;
        ans += ex * 2;
        cur *= 2;
        if (ex == 0) break;
    }
    cur = 4;
    while (true) {
        if (b % cur == 0)
            ans++;
        cur *= 2;
        if (cur > b)
            break;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c;
    while (cin >> a >> b) {
        ll ans = 0;
        if (a > b)
            swap(a, b);
        ans = calc(b) - calc(a);
        cout << ans << endl;
        //if (c != ans)
        //    cerr << "LOL..." << endl;
    }
}
