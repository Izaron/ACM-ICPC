#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <limits.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    vector<int> vec;
    int cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1])
            cnt++;
        else {
            vec.push_back(cnt);
            cnt = 1;
        }
    }
    if (cnt > 0)
        vec.push_back(cnt);
    ans = vec.size() - 1;
    if (s.back() == '-')
        ans++;

    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
