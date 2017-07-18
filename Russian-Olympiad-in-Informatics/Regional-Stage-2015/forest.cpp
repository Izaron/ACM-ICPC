#include <bits/stdc++.h>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define gv(v, i) get<i>(v)
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

ll A, K, B, M, X;

int getp(ll v) {
    int ans = 0;
    while (v > 0) {
        ans++;
        v /= 10;
    }
    return ans;
}

bool can(ll days) {
    ll w1 = days - days / K;
    ll w2 = days - days / M;

    if (getp(w1) + getp(A) - 1 >= 19)
        return true;
    if (getp(w2) + getp(B) - 1 >= 19)
        return true;

    if (w1 * A >= X)
        return true;

    if (w2 * B >= X)
        return true;

    return w1 * A + w2 * B >= X;
}

int main() {
    #ifndef HOME
    freopen("forest.in", "r", stdin);
    freopen("forest.out", "w", stdout);
    #endif

    cin >> A >> K >> B >> M >> X;

    ll a = 0, b = 2000000000000000005;
    while (a != b) {
        ll la = a, lb = b;
        ll mid = (a + b) / 2;
        if (can(mid))
            b = mid;
        else
            a = mid;
        if (la == a && lb == b) {
            if (can(a))
                b = a;
            else
                a = b;
        }
    }

    cout << a;
} 
