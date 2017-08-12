#include <iostream>
#include <set>
using namespace std;

void solve() {
    string s;
    cin >> s;

    string cur = "";
    for (auto it : s) {
        string a = it + cur;
        string b = cur + it;
        if (b > a)
            cur = b;
        else
            cur = a;
    }
    cout << cur << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
