#include "sorting.h"
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> will;
vector<int> s;
vector<int> x;
vector<int> y;

int findSwapPairs(int N, int S[], int M, int X[], int Y[], int P[], int Q[]) {
    n = N;
    m = M;
    will.resize(n);
    s.resize(n);
    for (int i = 0; i < n; i++)
        will[i] = i;
    for (int i = 0; i < m; i++)
        swap(will[X[i]], will[Y[i]]);
    for (int i = 0; i < n; i++)
        s[i] = S[i];

    for (int i = 0; i < n; i++) {
        // Ermek's turn
        swap(s[X[i]], s[Y[i]]);
        for (int z = 0; z < n; z++)
            will[z] = z;
        for (int z = i + 1; z < m; z++)
            swap(will[X[z]], will[Y[z]]);
        vector<int> tmp = will;
        for (int i = 0; i < n; i++)
            will[tmp[i]] = i;

        if (i < n) {
            // where is element I
            int pos = 0;
            while (s[pos] != i) pos++;

            // what element will be on position pos
            int change = 0;
            while (will[change] != i) change++;

            // swap
            P[i] = pos;
            Q[i] = change;
            swap(s[pos], s[change]);
        } else {
            P[i] = 0;
            Q[i] = 0;
        }

        int kek = 0;
    }

	return m;
}
