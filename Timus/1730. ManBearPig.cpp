#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <sstream>
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
typedef tuple<int, int, int, int, int> tt;

const int N = 100000 + 5;



int main() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '-')
            s[i] = ' ';
    stringstream ss(s);
    vector<string> names;
    while (!ss.eof()) {
        string tmp;
        ss >> tmp;
        names.pb(tmp);
    }
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '/')
            s[i] = ' ';
    stringstream ss2(s);

    int msA[N], msB[N];
    int curr = 0;
    int gc = 1;

    while (!ss2.eof()) {
        ss2 >> msA[curr] >> msB[curr];
        int kek = __gcd(msA[curr], msB[curr]);
        msA[curr] /= kek;
        msB[curr] /= kek;
        
        gc = gc * msB[curr] / __gcd(gc, msB[curr]);
        curr++;
    }

    if (curr == 1) {
        cout << 1 << endl << names[0];
        return 0;
    }

    for (int i = 0; i < curr; i++)
        msA[i] = msA[i] * gc / msB[i];

    int tmp = gc;
    while (tmp % 2 == 0)
        tmp /= 2;

    if (tmp != 1) {
        cout << "No solution";
        return 0;
    }

    cout << 2 * gc - 1 << endl;
    int cnt = 0;
    for (int i = 0; i < curr; i++) {
        for (int z = 0; z < msA[i]; z++) {
            cout << names[i] << endl;
            cnt++;
        }
    }

    map<pii, int> mp;

    for (int i = 0; i < gc; i += 2) {
        cout << i + 1 << " " << i + 2 << endl;
        mp[mkp(i + 1, i + 2)] = cnt;
        cnt++;
    }

    for (int plus = 4; plus <= gc; plus *= 2) {
        for (int i = plus; i <= gc; i += plus) {
            int a1 = i - plus + 1;
            int b1 = i - plus / 2;
            int a2 = i - plus / 2 + 1;
            int b2 = i;
            cout << mp[mkp(a1, b1)] + 1 << " " << mp[mkp(a2, b2)] + 1 << endl;
            mp[mkp(a1, b2)] = cnt;
            cnt++;
        }
    }
}
