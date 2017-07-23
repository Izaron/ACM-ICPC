// The solution of the problem was written by Izaron
// Date: 18:47:17   16 May 2016
// Execution time: 0.015

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
typedef pair<int, int> pii;

const int N = 10000 + 5;


bool simple(int v) {
    for (int i = 2; i <= sqrt(v); i++) {
        if (v % i == 0)
            return false;
    }
    return true;
}

void work() {
    int n;
    cin >> n;
    vector<int> vec;

    if (simple(n)) {
        cout << n << endl;
        return;
    }

    if (simple(n - 2)) {
        cout << 2 << " " << n - 2 << endl;
        return;
    }

    if (n % 2 == 1) {
        vec.pb(3);
        n -= 3;
    }

    if (simple(n)) {
        vec.pb(n);
    } else {
        for (int i = 2; i < n; i++) {
            if (simple(i) && simple(n - i)) {
                vec.pb(i);
                vec.pb(n - i);
                break;
            }
        }
    }

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        work();
}