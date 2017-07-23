// The solution of the problem was written by Izaron
// Date: 20:57:20   28 Apr 2016
// Execution time: 0.062

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int N = 1500000 + 5;

int n;
vector<string> out;

void write(int number, int stolb, string s) {
    if (stolb == 0) {
        for (int i = 0; i < s.size(); i++) {
            out[number * 2 + 1][i + 1] = s[i];
        }
    } else if (stolb == 1) {
        for (int i = 0; i < s.size(); i++) {
            out[number * 2 + 1][i + 32] = s[i];
        }
    } else {
        for (int i = 0; i < s.size(); i++) {
            out[number * 2 + 1][i + 41] = s[i];
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n * 2 + 3; i++) {
        if (i % 2 == 0)
            out.pb("+------------------------------+--------+-------------+");
        else
            out.pb("|                              |        |             |");
    }

    write(0, 0, "Contest name");
    write(0, 1, "Date");
    write(0, 2, "ABCDEFGHIJKLM");

    for (int i = 1; i <= n; i++) {
        string name, date;
        getline(cin, name);
        getline(cin, name);
        cin >> date;
        write(i, 0, name);
        write(i, 1, date);

        string task = "";
        int p, s;
        cin >> p >> s;
        for (int z = 0; z < p; z++)
            task += ".";
        for (int z = 0; z < s; z++) {
            string kek;
            cin >> kek;
            int num = kek[0] - 'A';
            cin >> kek;

            if (kek == "Wrong" || kek == "Runtime" || kek == "Compilation")
                cin >> kek;
            else if (kek != "Accepted") {
                cin >> kek;
                cin >> kek;
            }

            if (kek == "Accepted") {
                task[num] = 'o';
            } else if (task[num] != 'o') {
                task[num] = 'x';
            }
        }

        write(i, 2, task);
    }

    for (int i = 0; i < out.size(); i++)
        cout << out[i] << endl;
}
