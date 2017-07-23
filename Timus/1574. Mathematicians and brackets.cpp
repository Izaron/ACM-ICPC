#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
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
typedef tuple<int, int, int> tt;

const int N = 100000 + 5;


string s;

int main() {
    cin >> s;
    int bal = 0;
    int ans = 1;

    int sums[N], mins[N], starts[N];

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            bal++;
        else
            bal--;
        sums[i] = bal;
        mins[i] = bal;
        starts[i] = bal;
        if (i > 0)
            starts[i] = min(starts[i], starts[i - 1]);
    }

    for (int i = (int)s.size() - 2; i >= 0; i--)
        mins[i] = min(mins[i], mins[i + 1]);

    int kz = bal;
    bal = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            bal++;
        else
            bal--;
        if (bal < 0) {
            bal = 0;
            ans--;
            break;
        }
    }
    if (bal != 0)
        ans--;

    if (kz == 0) {
        for (int i = 0; i < s.size() - 1; i++) {
            int minn = mins[i + 1] - sums[i];
            if (minn < 0)
                continue;

            int tmp = sums[s.size() - 1];
                tmp -= sums[i];
            if (starts[i] + tmp < 0)
                continue;

            ans++;
        }
    }

    cout << ans;
}
