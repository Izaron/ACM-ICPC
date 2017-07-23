#include <bits/stdc++.h>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define gv(v, i) get<i>(v)
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int maxn = 100000 + 5;

int main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;
    int ms[105][105];
    int cnt[105][105];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        for (int z = 0; z < m; z++) {
            cin >> ms[i][z];
            if (ms[i][z] == 1)
                cnt[z][i] = 1;
        }
    }

    int ans = 1000000000, i = 0, z = 1;
    for (int a = 0; a < m; a++) {
        for (int b = a + 1; b < m; b++) {
            int i1 = 0, i2 = 0, i3 = 0, i4 = 0;
            for (int s = 0; s < n; s++) {
                if (cnt[a][s] && cnt[b][s])
                    i1++;
                else if (!cnt[a][s] && cnt[b][s])
                    i2++;
                else if (cnt[a][s] && !cnt[b][s])
                    i3++;
                else
                    i4++;
            }
            i1 = max(i1, i2);
            i1 = max(i1, i3);
            i1 = max(i1, i4);
            if (i1 < ans) {
                ans = i1;
                i = a;
                z = b;
            }
        }
    }

    cout << ans << endl << i + 1 << " " << z + 1;
}
