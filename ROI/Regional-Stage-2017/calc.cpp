#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#ifdef USE_CERR
#define CERR(a) cerr << "dump: " << a << endl;
#else
#define CERR(a)
#endif

int main() {
    #ifndef HOME
    #define FILE "calc"
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
    #endif

    ll n;
    int a, b, c;
    cin >> n >> a >> b >> c;
    
    vector<int> as = { 0, 1, 2 };
    ll ans = n;
    while (true) {
        ll cur = n;
        for (int i = 0; i < 3; i++) {
            if (as[i] == 0) {
                for (int z = 0; z < a; z++)
                    cur = cur / 2;
            } else if (as[i] == 1) {
                for (int z = 0; z < b; z++)
                    cur = (cur + 1) / 2;
            } else {
                for (int z = 0; z < c; z++)
                    cur = (cur - 1) / 2;
            }
        }
        ans = min(ans, cur);
        if (!next_permutation(as.begin(), as.end()))
            break;
    }
    cout << ans;
}