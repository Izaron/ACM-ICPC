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

const int maxn = 100000 + 5;

int main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #endif

    int a, b;
    cin >> a >> b;
    int n = b;
    for (int i = 2; i <= n; i++) {
        n -= n / i;
    }
    int k = a - 1;
    for (int i = 2; i <= k; i++) {
        k -= k / i;
    }
    cout << n - k;
}
