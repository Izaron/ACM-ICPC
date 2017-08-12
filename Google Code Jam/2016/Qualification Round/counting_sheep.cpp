#include <iostream>
#include <set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < 100; i++) {
        int tmp = n * (i + 1);
        while (tmp) {
            st.insert(tmp % 10);
            tmp /= 10;
        }
        if (st.size() == 10) {
            cout << n * (i + 1) << endl;
            return;
        }
    }
    cout << "INSOMNIA" << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
