#include <iostream>
#include <set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < 2 * n - 1; i++) {
        int tmp;
        for (int z = 0; z < n; z++) {
            cin >> tmp;
            if (st.count(tmp))
                st.erase(tmp);
            else
                st.insert(tmp);
        }
    }
    if (st.size() != n)
        throw 0;
    for (auto it : st)
        cout << it << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
