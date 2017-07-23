// The solution of the problem was written by Izaron
// Date: 22:35:40   1 May 2016
// Execution time: 0.001

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
#include <tuple>
#include <bitset>
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tt;

const int N = 1500000 + 5;

int n;
vector<string> out;

void write(int number, int stolb, string s) {
	int plus = 0, cnt = 0, ost = 10;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			int len = 0;
			int z = i + 1;
			while (z < s.size() && tolower(s[z]) >= 'a' && tolower(s[z]) <= 'z') {
				z++;
				len++;
			}
			if (len >= ost) {
				plus++;
				cnt = 0;
				ost = 10;
			} else {
				out[number * 6 + 1 + plus][stolb * 11 + 1 + cnt] = s[i];
				cnt++;
				ost--;
			}
		} else {
			out[number * 6 + 1 + plus][stolb * 11 + 1 + cnt] = s[i];
			cnt++;
			ost--;
		}
	}
}

bool isBad(int v) {
	if (v % 6 <= 1)
		return false;
	for (int i = 0; i < out[v].size(); i++) {
		if (out[v][i] == '-' || (tolower(out[v][i]) >= 'a' && tolower(out[v][i]) <= 'z'))
			return false;
	}
	return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 4 * 6 + 1; i++) {
        if (i % 6 == 0)
            out.pb("+----------+----------+----------+");
        else
            out.pb("|          |          |          |");
    }

    string name, day;
    int num;
    for (int i = 0; i < n; i++) {
    	getline(cin, name);
    	getline(cin, name);
    	cin >> day >> num;
    	num--;
    	if (day == "Tuesday")
    		write(num, 0, name);
    	else if (day == "Thursday")
    		write(num, 1, name);
    	else
    		write(num, 2, name);
    }

    for (int i = 0; i < out.size(); i++) {
    	if (!isBad(i))
    		cout << out[i] << endl;
    }
}

