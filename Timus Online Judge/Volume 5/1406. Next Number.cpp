// The solution of the problem was written by Izaron
// Date: 22:01:30   19 May 2016
// Execution time: 0.001

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

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


int main() {
    string s;
    cin >> s;
    int v = -1, sum = 0, kk = 0;
    for (int i = (int)s.size() - 1; i >= 1; i--) {
        kk += s[i] - '0';
        if (s[i - 1] < '9' && kk > 0) {
            v = i;
            sum = -1;
            s[i - 1]++;
            break;
        }
    }

    if (v == -1) {
        cout << -1;
        return 0;
    }

    for (int i = v; i < s.size(); i++) {
        sum += s[i] - '0';
        s[i] = '0';
    }

    for (int i = s.size() - 1; i >= v; i--) {
        int kek = min(sum, 9);
        sum -= kek;
        s[i] = kek + '0';
    }

    cout << s;
}
