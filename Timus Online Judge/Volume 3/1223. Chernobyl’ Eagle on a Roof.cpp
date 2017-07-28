// The solution of the problem was written by Izaron
// Date: 15:50:11   27 Jul 2017
// Execution time: 0.093

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

const int maxn = 1000 + 5;

int calced[maxn][maxn];

int dp(int eggs, int roofs) {
    if (eggs == 1)
        return roofs;
    if (roofs <= 0)
        return 0;

    int& ans = calced[eggs][roofs];
    if (ans != -1)
        return ans;

    ans = INT_MAX / 2;

    for (int roof = 1; roof <= roofs; roof++) {
        // egg is broken
        int a = dp(eggs - 1, roof - 1);
        // egg isn't broken
        int b = dp(eggs, roofs - roof);

        ans = min(ans, 1 + max(a, b));
    }

    //cerr << eggs << " " << roofs << " : " << ans << endl;
    return ans;
}

int main() {
    memset(calced, -1, sizeof(calced));
    int a, b;
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        a = min(a, 15); // lol cheats!
        cout << dp(a, b) << endl;
    }
}
