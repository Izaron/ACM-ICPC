// The solution of the problem was written by Izaron
// Date: 15:19:38   27 Jul 2017
// Execution time: 0.109

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

string s;
vector<int> vec;

void split() {
    int cur = 0;
    for (auto it : s) {
        if (tolower(it) >= 'a' && tolower(it) <= 'z') {
            cur++;
        } else {
            if (cur > 0)
                vec.push_back(cur);
            cur = 0;
        }
    }
    if (cur > 0)
        vec.push_back(cur);
}

int calced[10000 + 5][2];

int dp(int v, int rep) {
    if (v == vec.size())
        return 0;
    int& ans = calced[v][rep];
    if (ans != -1)
        return ans;
    ans = 0;
    ans = max(ans, dp(v + 1, 0));
    if (rep == 0) {
        ans = max(ans, vec[v] + dp(v + 1, 1));
    }
    return ans;
}

int main() {
    string tmp;
    while (getline(cin, tmp))
        s += " " + tmp;
    split();
    memset(calced, -1, sizeof(calced));
    cout << dp(0, 0) << endl;
}
