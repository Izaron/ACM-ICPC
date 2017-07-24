// The solution of the problem was written by Izaron
// Date: 14:17:39   15 May 2016
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

const int N = 100000 + 5;


int month[] = { 30, 31, 30, 31 };
int cnt[7];

int getDayNum(string s) {
    if (s == "Monday")
        return 0;
    if (s == "Tuesday")
        return 1;
    if (s == "Wednesday")
        return 2;
    if (s == "Thursday")
        return 3;
    if (s == "Friday")
        return 4;
    if (s == "Saturday")
        return 5;
    if (s == "Sunday")
        return 6;
}

int getMonNum(string s) {
    if (s == "September")
        return 0;
    if (s == "October")
        return 1;
    if (s == "November")
        return 2;
    if (s == "December")
        return 3;
}

string getDayName(int v) {
    if (v == 0)
        return "Monday";
    if (v == 1)
        return "Tuesday";
    if (v == 2)
        return "Wednesday";
    if (v == 3)
        return "Thursday";
    if (v == 4)
        return "Friday";
    if (v == 5)
        return "Saturday";
    if (v == 6)
        return "Sunday";
}

void calc() {
    string s;
    cin >> s;
    int inWeek = (getDayNum(s) + 1) % 7;

    int day = 2;
    int mon = 0;

    int maxDay, maxMon;
    cin >> s;
    maxMon = getMonNum(s);
    cin >> maxDay;

    while (true) {
        if (day == maxDay && mon == maxMon)
            break;
        cnt[inWeek]++;
        inWeek = (inWeek + 1) % 7;

        day++;
        if (day > month[mon]) {
            day = 1;
            mon++;
        }
    }
}

int main() {
    fill(cnt, cnt + 7, 0);
    calc();
    int a, b;
    cin >> a >> b;

    for (int mask = 1; mask < (1 << 7); mask++) {
        int sum = 0;
        for (int i = 0; i < 7; i++) {
            if ((mask & (1 << i)) != 0) {
                sum += cnt[i];
            }
        }

        if (sum >= a && sum <= b) {
            cout << __builtin_popcount(mask) << endl;
            for (int i = 0; i < 7; i++) {
                if ((mask & (1 << i)) != 0) {
                    cout << getDayName(i) << endl;
                }
            }
            return 0;
        }
    }

    cout << "Impossible";
}