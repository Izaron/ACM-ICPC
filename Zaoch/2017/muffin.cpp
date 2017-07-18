#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n;
string s;

void err() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    cin >> n;
    cin >> s;

    int ls = 0, us = 0, rs = 0, ds = 0;
    for (auto c : s)
        if (c == 'L') ls++; else
        if (c == 'U') us++; else
        if (c == 'R') rs++; else
        ds++;

    int x, y;
    cin >> x >> y;

    int lb = 0, ub = 0, rb = 0, db = 0;

    if (x < 0) {
        if (ls < abs(x)) err();
        int tar = abs(x);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') tar--;
            if (tar == 0) {
                lb = i + 1;
                break;
            }
        }
    }

    if (x > 0) {
        if (rs < abs(x)) err();
        int tar = abs(x);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') tar--;
            if (tar == 0) {
                rb = i + 1;
                break;
            }
        }
    }

    if (y < 0) {
        if (ds < abs(y)) err();
        int tar = abs(y);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'D') tar--;
            if (tar == 0) {
                db = i + 1;
                break;
            }
        }
    }

    if (y > 0) {
        if (us < abs(y)) err();
        int tar = abs(y);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'U') tar--;
            if (tar == 0) {
                ub = i + 1;
                break;
            }
        }
    }

    cout << lb << " " << ub << " " << rb << " " << db << endl;
}