// The solution of the problem was written by Izaron
// Date: 12:31:43   30 Apr 2016
// Execution time: 0.015

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
#include <cstdlib>
#include <ctime>
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int N = 100000 + 5;


char getOth(char a, char b) {
    if ('A' != a && 'A' != b)
        return 'A';
    if ('B' != a && 'B' != b)
        return 'B';
    if ('C' != a && 'C' != b)
        return 'C';
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    reverse(s.begin(), s.end());
    string curr = "";
    for (int i = 0; i < n; i++)
        curr += "A";
    ll st = n;
    for (int i = 0; i < s.size(); i++) {
        st--;
        if (s[i] == curr[i])
            continue;
        else {
            ans += (1LL << st);
            char from = curr[i], to = s[i];
            char oth = getOth(from, to);
            curr[i] = to;
            for (int z = i + 1; z < s.size(); z++)
                curr[z] = oth;
        }
        //cout << curr << endl;
    }
    cout << ans;
}
