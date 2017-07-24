// The solution of the problem was written by Izaron
// Date: 18:10:43   23 May 2016
// Execution time: 0.031

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <vector>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int, int> tt;

const int N = 5;
const ld EPS = 0.00000001;
const ld g = 9.81;

ld xs[N], ys[N];
ld u, gr;

ld gett(int a, int b, ld alpha) {
    ld x = xs[a], y = ys[a];
    ld uSqr = (g * x * x) / (2.0 * cos(alpha) * cos(alpha) * (x * tan(alpha) - y));
    //uSqr = abs(uSqr);

    ld tarX = xs[b];
    ld tarY = tarX * tan(alpha) - g * tarX * tarX / (2 * uSqr * cos(alpha) * cos(alpha));
    return abs(tarY - ys[b]);
}


ld us;
bool can(int a, int b) {
    ld f = 0, s = 1.5708;
    f = asin(ys[a] / sqrt(xs[a] * xs[a] + ys[a] * ys[a]));

    ld ansi = 1000000000, v = -10;
    for (int i = 0; i < 100; i++) {
        ld kek = gett(a, b, (f + s) / 2);
        if (kek < ansi) {
            ansi = kek;
            v = (f + s) / 2;
        }
        ld raz = (s - f) / 3;
        ld f1 = f + raz;
        ld f2 = s - raz;
        if (gett(a, b, f1) > gett(a, b, f2))
            f = f1;
        else
            s = f2;
    }

    us = v;
    return ansi <= EPS;
}

bool can(int a, int b, ld uss) {
    ld ansi;
    ansi = gett(a, b, uss);
    return ansi <= EPS;
}


int main() {
    for (int i = 0; i < N; i++)
        cin >> xs[i] >> ys[i];

    int perm[] = { 0, 1, 2, 3, 4 };
    int kek = 5;

    while (true) {
        int ans = 0;
        int kz = 0;
        for (int i = 0; i < N; i++) {
            if (i == N - 1) {
                ans++;
            } else {
                if (kz == 0) {
                    if (!can(perm[i], perm[i + 1])) {
                        ans++;
                    } else {
                        kz = 1;
                    }
                } else {
                    if (!can(perm[i], perm[i + 1], us)) {
                        ans++;
                        kz = 0;
                    }
                }
            }
        }

        kek = min(kek, ans);

        if (!next_permutation(perm, perm + 5))
            break;
    }

    cout << kek;
}
