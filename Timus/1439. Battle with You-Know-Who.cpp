// The solution of the problem was written by Izaron
// Date: 14:00:40   15 May 2016
// Execution time: 0.686

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <set>
#include <map>
#include <string>
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
typedef pair<int, int> pii;

const int N = 100000 + 5;


template<typename T> using ordered_set = tree<T, null_type, less<T>,
        rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<int> st;

int compare(int v, int real) {
    int cmp = v + st.order_of_key(real);
    if (real > cmp)
        return 1;
    else if (real < cmp)
        return -1;
    return 0;
}

int getReal(int v) {
    int a = v, b = 1000000001;
    while (a != b) {
        int la = a, lb = b;
        int mid = (a + b) / 2;

        int cmp = compare(v, mid);

        if (cmp >= 1)
            b = mid;
        else
            a = mid;

        if (la == a && lb == b) {
            if (compare(v, a) == 0)
                return a;
            else
                return b;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string com;
        int v;
        cin >> com >> v;
        if (com == "L") {
            cout << getReal(v) << "\n";
        } else {
            int inss = getReal(v);
            st.insert(inss);
        }
    }
}