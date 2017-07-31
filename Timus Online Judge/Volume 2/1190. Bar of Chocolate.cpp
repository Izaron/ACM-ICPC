// The solution of the problem was written by Izaron
// Date: 16:11:17   29 Jul 2017
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <limits.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> vec(n, 1);
    vector<bool> setted(n);
    for (int i = 0; i < n; i++) {
        string s;
        int a;
        cin >> s >> a;
        if (a == 1) {
            cin >> vec[i];
            setted[i] = true;
        }
    }

    vector<int> ril(n, 1);
    for (int i = n - 1; i >= 0; i--) {
        ril[i] = max(ril[i], vec[i]);
        if (i + 1 < n)
            ril[i] = max(ril[i], ril[i + 1]);
    }

    for (int i = 0; i < n; i++) {
        if (setted[i] && ril[i] != vec[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    int min_sum = 0, max_sum = 0;
    for (auto it : ril)
        min_sum += it;

    int cur = 10000;
    for (int i = 0; i < n; i++) {
        if (setted[i])
            cur = vec[i];
        //cerr << "cur is " << cur << " " << vec[i] << endl;
        max_sum += max(vec[i], cur);
    }

    //cerr << min_sum << " " << max_sum << endl;

    if (min_sum <= 10000 && max_sum >= 10000) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
