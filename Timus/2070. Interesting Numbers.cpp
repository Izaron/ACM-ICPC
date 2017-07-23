#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int N = 1000000 + 5;


int main() {
    ll L, R;
    cin >> L >> R;

    bool prost[N];
    fill(prost, prost + N, false);
    prost[0] = true;
    prost[1] = true;

    for (int i = 2; i < N; i++) {
        if (prost[i])
            continue;
        for (int z = 2 * i; z < N; z += i)
            prost[z] = true;
    }

    ll ans = R - L + 1;

    for (int ch = 2; ch < N; ch++) {
        if (prost[ch])
            continue;
        //if (ch >= L && ch <= R)
        //    cout << ch << endl;
        ll curr = 1;
        for (int step = 1; ; step++) {
            curr *= ch;
            if (curr > R)
                break;
            if (!prost[step + 1] && step != 1 && curr >= L && curr <= R) {
                ans--;
                //cout << curr << endl;
            }
        }
    }

    cout << ans;
}
