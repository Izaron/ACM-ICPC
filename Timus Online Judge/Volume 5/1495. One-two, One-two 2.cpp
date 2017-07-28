// The solution of the problem was written by Izaron
// Date: 23:45:21   25 Jul 2017
// Execution time: 0.452

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <vector>
#include <string.h>
#include <iostream>
#include <map>
#include <limits.h>
#include <set>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 31;
const int maxw = 1000000 + 5;

short calced[maxw][maxn];
vector<int> gen;
int n;

short calc(int mod, int cnt) {
    if (cnt < 0)
        return (mod == 0 ? 1 : 0);
    short& res = calced[mod][cnt];
    if (res != -1)
        return res;
    res = 0;
    res = max(res, calc((mod + gen[cnt] * 1) % n, cnt - 1));
    res = max(res, calc((mod + gen[cnt] * 2) % n, cnt - 1));
    return res;
}

int res;

void vosst(int mod, int cnt) {
    if (cnt < 0)
        return;
    short res = calc(mod, cnt);
    if (res == calc((mod + gen[cnt] * 1) % n, cnt - 1)) {
        cout << 1;
        vosst((mod + gen[cnt] * 1) % n, cnt - 1);
    } else {
        cout << 2;
        vosst((mod + gen[cnt] * 2) % n, cnt - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(calced, -1, sizeof(calced));

    cin >> n;

    gen.resize(maxn);
    gen[0] = 1;
    for (int z = 1; z < maxn; z++) {
        gen[z] = gen[z - 1] * 10;
        gen[z] %= n;
    }

    int cnt = 0;
    while (true) {
        if (calc(0, cnt) != 0)
            break;
        cnt++;
        if (cnt >= 30) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    vosst(0, cnt);
    cout << endl;
}
