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

int n, k;

ll work() {
    ll ans = 0;
    ordered_set<int> st;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        ans += st.order_of_key(-tmp);
        st.insert(-tmp);
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &k);
    ll maxi = 0;
    int v = 1;
    for (int i = 0; i < k; i++) {
        ll curr = work();
        if (maxi < curr) {
            maxi = curr;
            v = i + 1;
        }
    }
    printf("%d", v);
}