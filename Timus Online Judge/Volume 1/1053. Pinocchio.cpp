// The solution of the problem was written by Izaron
// Date: 19:43:47   28 Jul 2017
// Execution time: 0.015

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<ll> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        st.insert(tmp);
    }

    while (st.size() > 1) {
        ll a = (*st.begin());
        st.erase(st.begin());
        ll b = (*st.begin());
        st.erase(st.begin());
        st.insert(__gcd(a, b));
    }

    cout << (*st.begin()) << endl;
}
