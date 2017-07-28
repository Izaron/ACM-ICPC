// The solution of the problem was written by Izaron
// Date: 16:07:35   25 Jul 2017
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int maxn = 100 + 5;

string s;
int n;
int calc[maxn][maxn];

void print_diff(int v) {
    if (s[v] == '(' || s[v] == ')') {
        cout << "()";
    } else {
        cout << "[]";
    }
}

void print(int v) {
    cout << s[v];
}

bool are_closers(int a, int b) {
    if (s[a] == '(' && s[b] == ')')
        return true;
    if (s[a] == '[' && s[b] == ']')
        return true;
    return false;
}

int dp(int a, int b) {
    if (a == b)
        return 1;
    if (a > b)
        return 0;
    if (calc[a][b] != -1)
        return calc[a][b];
    int cur = INT_MAX / 3;
    for (int i = a; i < b; i++)
        cur = min(cur, dp(a, i) + dp(i + 1, b));
    if (are_closers(a, b))
        cur = min(cur, dp(a + 1, b - 1));
    cur = min(cur, 1 + dp(a + 1, b));
    cur = min(cur, 1 + dp(a, b - 1));
    calc[a][b] = cur;
    return cur;
}

void vosst(int a, int b) {
    if (a == b) {
        print_diff(a);
        return;
    }
    if (a > b)
        return;
    int cur = dp(a, b);

    for (int i = a; i < b; i++) {
        if (cur == dp(a, i) + dp(i + 1, b)) {
            vosst(a, i);
            vosst(i + 1, b);
            return;
        }
    }

    if (are_closers(a, b)) {
        if (cur == dp(a + 1, b - 1)) {
            print(a);
            vosst(a + 1, b - 1);
            print(b);
            return;
        }
    }

    if (cur == 1 + dp(a + 1, b)) {
        print_diff(a);
        vosst(a + 1, b);
        return;
    }

    if (cur == 1 + dp(a, b - 1)) {
        print_diff(b);
        vosst(a, b - 1);
        return;
    }
}

int main() {
    memset(calc, -1, sizeof(calc));
    cin >> s;
    int n = s.size();
    vosst(0, n - 1);
    cout << endl;
}
