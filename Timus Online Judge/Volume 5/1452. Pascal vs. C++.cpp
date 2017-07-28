// The solution of the problem was written by Izaron
// Date: 21:32:13   26 Jul 2017
// Execution time: 0.171

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <vector>
#include <string.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <limits.h>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 2000 + 5;

int n;
int ms[maxn];
map<int, short> ind;
map<int, short> ind2;
short kek[maxn][maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ms[i]);
        ind[ms[i]] = i;
    }
    sort(ms, ms + n);
    for (int i = 0; i < n; i++)
        ind2[ms[i]] = i;

    int st = ms[0], res = 1, step = 0;

    memset(kek, 0, sizeof(kek));

    int diff, sum, cur;
    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 < n && ms[i] == ms[i + 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (ms[j] == ms[i]) continue;
            kek[i][j] = 2;
            if (ind2.count(ms[j] * 2 - ms[i])) {
                int k = ind2[ms[j] * 2 - ms[i]];
                //cerr << i << " " << j << " " << k << endl;
                kek[i][j] = max(kek[i][j], (short)(kek[j][k] + 1));
                if (kek[i][j] > res) {
                    res = kek[i][j];
                    st = ms[i];
                    step = ms[j] - ms[i];
                }
            }
        }
    }

    if (2 > res) {
        for (int i = 0; i + 1 < n; i++) {
            if (ms[i] != ms[i + 1]) {
                st = ms[i];
                res = 2;
                step = ms[i + 1] - ms[i];
            }
        }
    }

    printf("%d\n", res);
    for (int i = 0; i < res; i++)
        printf("%d ", ind[st + i * step] + 1);
    printf("\n");
}
