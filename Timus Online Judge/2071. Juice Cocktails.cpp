// The solution of the problem was written by Izaron
// Date: 23:12:02   29 Apr 2016
// Execution time: 0.171

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
#include <map>
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int N = 100000 + 5;


// a, b, p, ab, ap, bp, abp
int n;
int perm[] = { 0, 1, 2, 3, 4, 5, 6 };
int cool[] = { 0, 1, 2, 3, 4, 5, 6 };
vector<int> vec[7];
bool hasA[7];
bool hasB[7];
bool hasP[7];
int cnt[7];

int gett() {
    int ans = 0;

    int lst = -1;
    for (int i = 0; i < 7; i++) {
        int ii = perm[i];
        if (cnt[ii] == 0)
            continue;
        if (hasA[ii]) {
            if (lst == -1) {
                ans++;
                lst = i;
            }
        } else {
            lst = -1;
        }
    }

    lst = -1;
    for (int i = 0; i < 7; i++) {
        int ii = perm[i];
        if (cnt[ii] == 0)
            continue;
        if (hasB[ii]) {
            if (lst == -1) {
                ans++;
                lst = i;
            }
        } else {
            lst = -1;
        }
    }

    lst = -1;
    for (int i = 0; i < 7; i++) {
        int ii = perm[i];
        if (cnt[ii] == 0)
            continue;
        if (hasP[ii]) {
            if (lst == -1) {
                ans++;
                lst = i;
            }
        } else {
            lst = -1;
        }
    }

    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < 7; i++) {
        cnt[i] = 0;
        hasA[i] = false;
        hasB[i] = false;
        hasP[i] = false;
    }

    hasA[0] = true;
    hasB[1] = true;
    hasP[2] = true;

    hasA[3] = true;
    hasB[3] = true;

    hasA[4] = true;
    hasP[4] = true;

    hasB[5] = true;
    hasP[5] = true;

    hasA[6] = true;
    hasB[6] = true;
    hasP[6] = true;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "A")
            cnt[0]++;
        if (s == "B")
            cnt[1]++;
        if (s == "P")
            cnt[2]++;
        if (s == "AB")
            cnt[3]++;
        if (s == "AP")
            cnt[4]++;
        if (s == "BP")
            cnt[5]++;
        if (s == "ABP")
            cnt[6]++;

        if (s == "A")
            vec[0].pb(i);
        if (s == "B")
            vec[1].pb(i);
        if (s == "P")
            vec[2].pb(i);
        if (s == "AB")
            vec[3].pb(i);
        if (s == "AP")
            vec[4].pb(i);
        if (s == "BP")
            vec[5].pb(i);
        if (s == "ABP")
            vec[6].pb(i);
    }

    int ans = 1000000000;
    while (true) {
        ans = min(ans, gett());
        if (ans == gett()) {
            for (int i = 0; i < 7; i++) {
                cool[i] = perm[i];
            }
        }
        if (!next_permutation(perm, perm + 7))
            break;
    }

    cout << ans << endl;
    vector<int> pr;

    for (int i = 0; i < 7; i++) {
        int ii = cool[i];
        for (int z = 0; z < vec[ii].size(); z++)
            pr.pb(vec[ii][z]);
    }

    for (int i = 0; i < n; i++)
        cout << pr[i] + 1 << " ";
}
