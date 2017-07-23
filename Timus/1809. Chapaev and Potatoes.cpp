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

const int N = 4;

int xs[N], ys[N];

bool isGood() {
    for (int i = 0; i < N; i++) {
        int kz = 0;
        for (int z = 0; z < N; z++) {
            if (i == z)
                continue;
            if (xs[z] == xs[i] || ys[z] == ys[i])
                kz++;
            if (xs[z] == xs[i] && ys[z] == ys[i])
                return false;
        }
        if (kz != 1)
            return false;
    }
}

int main() {
    for (int i = 0; i < N; i++)
        cin >> xs[i] >> ys[i];

    // 0
    if (isGood()) {
        for (int i = 0; i < N; i++)
            cout << xs[i] << " " << ys[i] << endl;
        return 0;
    }

    // 1
    for (int i = 0; i < N; i++) {
        int lx = xs[i], ly = ys[i];
        for (int a = 1; a <= 20; a++) {
            for (int b = 1; b <= 20; b++) {
                xs[i] = a;
                ys[i] = b;

                if (isGood()) {
                    for (int i = 0; i < N; i++)
                        cout << xs[i] << " " << ys[i] << endl;
                    return 0;
                }
            }
        }
        xs[i] = lx;
        ys[i] = ly;
    }

    // 2
    for (int k1 = 0; k1 < N; k1++) {
        int llx = xs[k1], lly = ys[k1];
        for (int aa = 1; aa <= 20; aa++) {
            for (int bb = 1; bb <= 20; bb++) {
                xs[k1] = aa;
                ys[k1] = bb;

                for (int k2 = k1 + 1; k2 < N; k2++) {
                    int lx = xs[k2], ly = ys[k2];
                    for (int a = 1; a <= 20; a++) {
                        for (int b = 1; b <= 20; b++) {
                            xs[k2] = a;
                            ys[k2] = b;

                            if (isGood()) {
                                for (int i = 0; i < N; i++)
                                    cout << xs[i] << " " << ys[i] << endl;
                                return 0;
                            }
                        }
                    }
                    xs[k2] = lx;
                    ys[k2] = ly;
                }

                if (isGood()) {
                    for (int i = 0; i < N; i++)
                        cout << xs[i] << " " << ys[i] << endl;
                    return 0;
                }
            }
        }
        xs[k1] = llx;
        ys[k1] = lly;
    }
}
