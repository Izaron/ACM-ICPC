// The solution of the problem was written by Izaron
// Date: 20:49:04   25 Jul 2017
// Execution time: 0.031

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <vector>
#include <string.h>
#include <iostream>
#include <map>
#include <limits.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 1e5 + 5;

int n, m;
string s;
vector<int> non_digits;
ll calced[maxn];

void calc() {
    int l = s.size();
    non_digits.resize(l);
    non_digits[l - 1] = INT_MAX / 2;
    for (int i = l - 1; i >= 0; i--) {
        if ((tolower(s[i]) < 'a' || tolower(s[i]) > 'z') && s[i] != ' ')
            non_digits[i] = i;
        else if (i + 1 < l)
            non_digits[i] = non_digits[i + 1];
    }
}

ll ans;
int inde;

ll dp(int v) {
    if (v >= non_digits.size())
        return 0;

    if (calced[v] != -1)
        return calced[v];

    ans = LLONG_MAX / 2;

    inde = non_digits[v];
    int add = min(m, inde - v);
    //cerr << "v " << v << " add " << add << " index " << inde << endl;
    if (add > 0)
        ans = min(ans, 1 + dp(v + add));
    ans = min(ans, 1 + dp(v + n));

    calced[v] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    getline(cin, s);
    getline(cin, s);
    calc();
    memset(calced, -1, sizeof(calced));
    for (int i = s.size() - 1; i >= 0; i--)
        dp(i);
    cout << dp(0) << endl;
}
