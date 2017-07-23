// The solution of the problem was written by Izaron
// Date: 14:35:01   24 Jun 2017
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main() {
    int cnt = 2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cnt++;
        if (s.size() >= 4 && s[s.size() - 4] == '+')
            cnt++;
    }
    if (cnt == 13) cnt++;
    cout << cnt * 100 << endl;
}
