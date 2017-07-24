// The solution of the problem was written by Izaron
// Date: 22:45:47   1 May 2016
// Execution time: 0.655

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <bitset>
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tt;

const int N = 319 * 319 + 5;

int n, sq;
char as[6], bs[6];
map<ll, int> mp;
ll indexx[N];
int indexInt[N];
ll add[N];
ll value[N];
ll delta[N];
ll minis[N];

ll getTime() {
	scanf("%s", &as);
	scanf("%s", &bs);
	ll day = (as[0] - '0') * 10 + (as[1] - '0');
	ll month = (as[3] - '0') * 10 + (as[4] - '0');
	ll hour = (bs[0] - '0') * 10 + (bs[1] - '0');
	ll minute = (bs[3] - '0') * 10 + (bs[4] - '0');
	return minute + hour * 60 + day * 60 * 24 + month * 60 * 24 * 32;
}

int main() {
	scanf("%d", &n);
	sq = (int)sqrt(n) + 2;
	set<ll> times;

    for (int i = 0; i < n; i++) {
        ll money;
        scanf("%lld", &money);
        ll time = getTime();
        times.ins(time);
        indexx[i] = time;
        add[i] = money;
    }

    int cnt = 0;
    for (ll it : times) {
        mp[it] = cnt;
        cnt++;
    }

    for (int i = 0; i < n; i++)
        indexInt[i] = mp[indexx[i]];

    for (int i = 0; i < n; i++) {
        // add
        set<int> dop;
        for (int z = indexInt[i]; z < sq * sq;) {
            if (z % sq == 0) {
                delta[z / sq] += add[i];
                z += sq;
            } else {
                dop.ins(z / sq);
                value[z] += add[i];
                z++;
            }
        }

        for (int it : dop) {
            minis[it] = 0;
            for (int z = it * sq; z < (it + 1) * sq; z++)
                minis[it] = min(minis[it], value[z]);
        }

        // calc
        ll ans = 0;
        for (int z = 0; z < sq; z++)
            ans = min(ans, minis[z] + delta[z]);

        // print
        printf("%lld\n", ans);
    }
}

