// The solution of the problem was written by Izaron
// Date: 17:36:47   29 Jul 2017
// Execution time: 0.015

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

const int maxn = 5e4 + 5;

// 0 - ouths win
// 1 - draw
// 2 - crosses win

int gc(char ch) {
    if (ch == 'X')
        return 2;
    if (ch == 'O')
        return 0;
    return 1;
}

int calc(vector<string>& vec) {
    for (int i = 0; i < 3; i++) {
        if (vec[i][0] == vec[i][1] && vec[i][1] == vec[i][2])
            if (gc(vec[i][0]) != 1)
                return gc(vec[i][0]);

        if (vec[0][i] == vec[1][i] && vec[1][i] == vec[2][i])
            if (gc(vec[0][i]) != 1)
                return gc(vec[0][i]);
    }

    if (vec[0][0] == vec[1][1] && vec[1][1] == vec[2][2])
        if (gc(vec[0][0]) != 1)
            return gc(vec[0][0]);

    if (vec[2][0] == vec[1][1] && vec[1][1] == vec[0][2])
        if (gc(vec[2][0]) != 1)
            return gc(vec[2][0]);

    return 1;
}

int dp(vector<string> vec, int ost) {
    //for (auto it : vec)
    //    cerr << it << endl;
    //cerr << endl;

    if (calc(vec) != 1)
        return calc(vec);
    if (ost == 0)
        return 1;

    if (ost % 2 == 1) {
        // crosses move
        int ans = 0;
        vector<string> v = vec;
        for (int i = 0; i < 3; i++) {
            for (int z = 0; z < 3; z++) {
                if (gc(v[i][z]) != 1) continue;
                v[i][z] = 'X';
                ans = max(ans, dp(v, ost - 1));
                v[i][z] = '#';
            }
        }
        return ans;
    } else {
        // ouths move
        int ans = 2;
        vector<string> v = vec;
        for (int i = 0; i < 3; i++) {
            for (int z = 0; z < 3; z++) {
                if (gc(v[i][z]) != 1) continue;
                v[i][z] = 'O';
                ans = min(ans, dp(v, ost - 1));
                v[i][z] = '#';
            }
        }
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<string> vec(3);
    for (int i = 0; i < 3; i++)
        cin >> vec[i];
    int res = dp(vec, 3);
    if (res == 0)
        cout << "Ouths win" << endl;
    else if (res == 1)
        cout << "Draw" << endl;
    else
        cout << "Crosses win" << endl;
}
