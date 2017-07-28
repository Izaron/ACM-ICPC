// The solution of the problem was written by Izaron
// Date: 19:57:15   25 Jul 2017
// Execution time: 0.546

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <vector>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 50 + 3;

int ans[maxn][maxn][maxn][maxn];
string s;
int n;

int maxi(int a, int b, int c, int d) {
    return max(max(a, b), max(c, d));
}

int mini(int a, int b, int c, int d) {
    return min(min(a, b), min(c, d));
}

int gpos(int pos, int v) {
    return abs(pos - v);
}

int gdist(int num, char v) {
    if (num == 0) {
        return (int)(v);
    } else {
        return abs(s[num - 1] - v);
    }
}

int dp(int a, int b, int c, int d) {
    int m = maxi(a, b, c, d);
    if (m == n)
        return 0;
    if (ans[a][b][c][d] != -1)
        return ans[a][b][c][d];

    int& res = ans[a][b][c][d];

    int pos = 0;
    if (m == b) pos = 1;
    if (m == c) pos = 2;
    if (m == d) pos = 3;

    int aa = gpos(pos, 0) + gdist(a, s[m]) + 1 + dp(m + 1, b, c, d);
    int bb = gpos(pos, 1) + gdist(b, s[m]) + 1 + dp(a, m + 1, c, d);
    int cc = gpos(pos, 2) + gdist(c, s[m]) + 1 + dp(a, b, m + 1, d);
    int dd = gpos(pos, 3) + gdist(d, s[m]) + 1 + dp(a, b, c, m + 1);

    res = mini(aa, bb, cc, dd);
    return res;
}

void move_pos(int a, int b) {
    while (a < b) {
        cout << ">";
        a++;
    }
    while (a > b) {
        cout << "<";
        a--;
    }
}

void move_ptr(int a, int b) {
    if (a == 0) {
        for (int i = 0; i < 97; i++)
            cout << "+";
        for (char ch = 'a'; ch < s[b]; ch++)
            cout << "+";
        return;
    }

    a--;

    int cur = s[a], tar = s[b];

    while (cur < tar) {
        cout << "+";
        cur++;
    }

    while (cur > tar) {
        cout << "-";
        cur--;
    }
}

void put() {
    cout << ".";
}

void vosst(int a, int b, int c, int d) {
    put();
    int m = maxi(a, b, c, d);
    if (m == n)
        return;

    int pos = 0;
    if (m == b) pos = 1;
    if (m == c) pos = 2;
    if (m == d) pos = 3;

    int aa = gpos(pos, 0) + gdist(a, s[m]) + 1 + dp(m + 1, b, c, d);
    int bb = gpos(pos, 1) + gdist(b, s[m]) + 1 + dp(a, m + 1, c, d);
    int cc = gpos(pos, 2) + gdist(c, s[m]) + 1 + dp(a, b, m + 1, d);
    int dd = gpos(pos, 3) + gdist(d, s[m]) + 1 + dp(a, b, c, m + 1);

    int res = ans[a][b][c][d];
    if (res == aa) {
        move_pos(pos, 0);
        move_ptr(a, m);
        vosst(m + 1, b, c, d);
    } else if (res == bb) {
        move_pos(pos, 1);
        move_ptr(b, m);
        vosst(a, m + 1, c, d);
    } else if (res == cc) {
        move_pos(pos, 2);
        move_ptr(c, m);
        vosst(a, b, m + 1, d);
    } else {
        move_pos(pos, 3);
        move_ptr(d, m);
        vosst(a, b, c, m + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    n = s.size();

    memset(ans, -1, sizeof(ans));

    int aa = gdist(0, s[0]) + 1 + dp(1, 0, 0, 0);
    int bb = gdist(0, s[0]) + 1 + dp(0, 1, 0, 0);
    int cc = gdist(0, s[0]) + 1 + dp(0, 0, 1, 0);
    int dd = gdist(0, s[0]) + 1 + dp(0, 0, 0, 1);

    int res = mini(aa, bb, cc, dd);

    if (res == aa) {
        move_ptr(0, 0);
        vosst(1, 0, 0, 0);
    } else if (res == bb) {
        move_ptr(0, 0);
        vosst(0, 1, 0, 0);
    } else if (res == cc) {
        move_ptr(0, 0);
        vosst(0, 0, 1, 0);
    } else {
        move_ptr(0, 0);
        vosst(0, 0, 0, 1);
    }
}
