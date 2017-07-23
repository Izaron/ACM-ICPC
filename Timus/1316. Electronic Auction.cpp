// The solution of the problem was written by Izaron
// Date: 00:05:31   18 May 2016
// Execution time: 0.28

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int N = 10000 + 5;


template <typename T> using ordered_set = tree<T, null_type, less<T>,
        rb_tree_tag, tree_order_statistics_node_update>;


int main() {
    ordered_set<pair<float, int>> st;
    map<float, int> cnt;
    ll ans = 0;

    char ch[6];

    while (true) {
        scanf("%s", ch);
        if (ch[0] == 'Q') {
            break;
        } else if (ch[0] == 'B') {
            float ff;
            scanf("%f", &ff);
            ff = -ff;

            st.insert(mkp(ff, cnt[ff]));
            cnt[ff]++;
        } else if (ch[0] == 'D') {
            float ff;
            scanf("%f", &ff);
            ff = -ff;

            cnt[ff]--;
            st.erase(mkp(ff, cnt[ff]));
        } else if (ch[0] == 'S') {
            float ff;
            scanf("%f", &ff);
            ff = -ff;
            int k;
            scanf("%d", &k);

            int kolvo = st.order_of_key(mkp(ff + 0.001, 0));
            kolvo = min(kolvo, k);
            ans += kolvo;
        }
    }

    if (ans % 100 > 9)
        cout << ans / 100 << "." << ans % 100;
    else
        cout << ans / 100 << ".0" << ans % 100;
}