// The solution of the problem was written by Izaron
// Date: 13:08:22   30 Apr 2016
// Execution time: 0.031

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


int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;

    if (k > s.size()) {
        cout << -1;
        return 0;
    }

    set<char> st;
    int adds = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            adds++;
            continue;
        }
        st.ins(s[i]);
    }

    if (k > st.size() + adds) {
        cout << -1;
        return 0;
    }


    vector<int> zs, as;

    int cmin = 'a', cmax = 'z';
    int cnmi = 1, cnma = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            if (i % 2 == 1) {
                st.ins(cmin);
                s[i] = cmin;
                as.pb(i);
            } else {
                st.ins(cmax);
                s[i] = cmax;
                zs.pb(i);
            }
        } else if (s[i] == 'a') {
            cnmi = 0;
        } else if (s[i] == 'z') {
            cnma = 0;
        }
    }

    int addA = 0, addB = 0;

    while (st.size() < k) {
        while (st.count(cmin)) {
            cmin++;
            addA++;
        }
        while (st.count(cmax)) {
            cmax--;
            addB++;
        }

        if (addA > addB) {
            if (zs.size() > cnma) {
                st.ins(cmax);
                s[zs[zs.size() - 1]] = cmax;
                zs.erase(zs.begin() + zs.size() - 1);
            } else if (as.size() > 1) {
                st.ins(cmin);
                s[as[as.size() - 1]] = cmin;
                as.erase(as.begin() + as.size() - 1);
            }
        } else {
            if (as.size() > cnmi) {
                st.ins(cmin);
                s[as[as.size() - 1]] = cmin;
                as.erase(as.begin() + as.size() - 1);
            } else if (zs.size() > cnma) {
                st.ins(cmax);
                s[zs[zs.size() - 1]] = cmax;
                zs.erase(zs.begin() + zs.size() - 1);
            }
        }
    }

    cout << s;
}
