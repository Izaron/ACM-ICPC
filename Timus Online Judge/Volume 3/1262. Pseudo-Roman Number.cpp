// The solution of the problem was written by Izaron
// Date: 17:21:38   29 Jul 2017
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

const int maxn = 5e4 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    vector<int> vec = {
        1, 2, 3, 2, 1, 2, 3, 4, 2
    };
    int ans = 0;
    for (auto it : s)
        if (it != '0')
            ans += vec[it - '1'];
    cout << ans << endl;
}
