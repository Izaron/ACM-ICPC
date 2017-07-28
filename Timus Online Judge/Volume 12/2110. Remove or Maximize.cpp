// The solution of the problem was written by Izaron
// Date: 13:06:08   28 Jul 2017
// Execution time: 0.093

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <limits.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

const int maxn = 1e5;
const int maxk = 100 + 1;

int n, k;
vector<int> vec;
int cur_pow;
vector<bool> can;
vector<bool> avail;

bitset<maxn> calced[maxk][2];
short ctimer[maxn][maxk][2];
int t;

bool dp(int v, int del, int sum) {
    if (v == n) {
        if (del == 0 && sum == 1)
            return true;
        return false;
    }

    short& tim = ctimer[v][del][sum];
    if (tim == t)
        return calced[del][sum][v];
    else
        calced[del][sum].set(v, false);
    tim = t;

    bool ans = false;
    if ((vec[v] & cur_pow) == cur_pow) {
        if (dp(v + 1, del, 1)) ans = true;
    } else {
        if (dp(v + 1, del, sum)) ans = true;
    }

    if (del > 0 && avail[v]) {
        bool cur = dp(v + 1, del - 1, sum);
        if (cur) ans = true;
        if (cur)
            can[v] = true;
    }

    if (ans)
        calced[del][sum].set(v);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    int resn = n;

    set<int> st;
    int alls = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        alls |= tmp;
        if (st.count(tmp)) {
            if (k > 0) {
                resn--;
                k--;
            }
        } else {
            st.insert(tmp);
        }
    }

    n = resn;
    if (k == 0) {
        cout << alls << endl;
        return 0;
    }

    vec.resize(n);
    can.resize(n);
    avail.resize(n, true);

    int r = 1;
    for (int i = 0; i < n; i++) {
        vec[i] = (*st.begin()); st.erase(st.begin());
        for (int p = 29; p >= 0; p--) {
            if ((vec[i] & (1 << p)) != 0) {
                r = max(r, p);
                break;
            }
        }
    }

    memset(ctimer, 0, sizeof(ctimer));
    t = 100;

    int res = 0;
    for (int p = r; p >= 0; p--) {
        cur_pow = (1 << p);

        fill(can.begin(), can.end(), false);
        t++;
        if (dp(0, k, 0)) {
            res += cur_pow;
            avail = can;
            //cerr << "can add " << cur_pow << endl;
        } else {
            //cerr << "can't add " << cur_pow << endl;
        }

        //cerr << "avail: ";
        //for (auto it : avail)
        //    cerr << it << " ";
        //cerr << endl;
    }

    cout << res << endl;
}
