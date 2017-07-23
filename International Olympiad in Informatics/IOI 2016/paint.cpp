#include "paint.h"
#include <bits/stdc++.h>
using namespace std;

int n;
string S;
vector<int> C;
vector<bool> canWhite;
vector<bool> canBlack;
vector<int> diffBlack;
vector<int> hasWhite;
vector<int> hasBlack;
int calc[200000 + 5][100 + 5][2];

bool isHasWhite(int a, int b) {
    int val = hasWhite[b];
    if (a > 0)
        val -= hasWhite[a - 1];
    return val > 0;
}

int dp(int v, int k, int last) {
    if (v > n)
        return 0;
    if (v == n && k != (int) C.size())
        return 0;
    if (v == n)
        return 1;

    if (calc[v][k][last] != -1)
        return calc[v][k][last];

    int ans = 0;

    // place white
    if (hasBlack[v] == 0 &&
            dp(v + 1, k, 0) == 1) {
        ans = 1;
        canWhite[v] = true;
    }

    // place black
    if (k < (int) C.size() &&
            last == 0 &&
            v + C[k] <= n &&
            !isHasWhite(v, v + C[k] - 1) &&
            dp(v + C[k], k + 1, 1) == 1) {
        ans = 1;
        diffBlack[v]++;
        diffBlack[v + C[k]]--;
    }

    calc[v][k][last] = ans;
    return ans;
}

string solve_puzzle(string s, vector<int> c) {
    n = (int) s.size();
    S = s;
    C = c;
    canWhite.resize(n);
    canBlack.resize(n);
    diffBlack.resize(n + 1);
    hasWhite.resize(n);
    hasBlack.resize(n);

    for (int i = 0; i < n; i++) {
        if (s[i] == '_') {
            canWhite[i] = true;
            hasWhite[i]++;
        }

        if (s[i] == 'X') {
            canBlack[i] = true;
            hasBlack[i]++;
        }

        if (i > 0)
            hasWhite[i] += hasWhite[i - 1];
    }

    memset(calc, -1, sizeof(calc));
    dp(0, 0, 0);

    for (int i = 0; i < n; i++) {
        if (i > 0)
            diffBlack[i] += diffBlack[i - 1];
        if (diffBlack[i] > 0)
            canBlack[i] = true;
    }

    string ans = "";
    for (int i = 0; i < n; i++) {
        if (canWhite[i] && canBlack[i]) {
            ans += "?";
        } else if (canWhite[i]) {
            ans += "_";
        } else if (canBlack[i]) {
            ans += "X";
        }
    }

    return ans;
}
