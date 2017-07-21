#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef pair<int, int> pii;

#ifdef USE_CERR
#define CERR(a) cerr << "dump: " << a << endl;
#else
#define CERR(a)
#endif

const int maxn = 4e3 + 5;
const int infi = 1e9 + 7;

template<typename T> using ordered_set = tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    #ifndef HOME
    #define FILE "pencils"
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
    #endif // HOME

    int n, k;
    cin >> n >> k;
    vector<pii> vec(n);
    ordered_set<pii> ends;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        int a = INT_MAX, b = INT_MIN;
        for (int z = 0; z < c; z++) {
            int k;
            cin >> k;
            a = min(a, k);
            b = max(b, k);
        }
        vec[i] = {a, b};
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++)
        ends.insert({vec[i].second, i});

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (ends.size() < k)
            continue;
        ans = min(ans, (*ends.find_by_order(k - 1)).first - vec[i].first);
        // erase i
        pii er = {vec[i].second, i};
        ends.erase(er);
    }
    cout << ans;
}