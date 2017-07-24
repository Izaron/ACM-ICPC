// The solution of the problem was written by Izaron
// Date: 19:07:17   30 Apr 2016
// Execution time: 0.499

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
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int N = 100 + 5;

int h, w;
string prog[N];
int reg0 = 0;
int regs[26];
int a = 0, b = 0;
int addA = 0, addB = 1;
int tact = 0;
bool run = true;
int currInt = 0;
vector<int> inputs;

void setMove() {
	if (prog[a][b] == '>') {
		addA = 0;
		addB = 1;
	} else if (prog[a][b] == '<') {
		addA = 0;
		addB = -1;
	} else if (prog[a][b] == 'v') {
		addA = 1;
		addB = 0;
	} else if (prog[a][b] == '^') {
		addA = -1;
		addB = 0;
	}
}

void next() {
	a += addA;
	b += addB;
}

bool isOverflowError() {
	return abs(reg0) > 100000;
}

bool isRuntimeError() {
	if (a < 0 || b < 0 || a >= h || b >= w)
		return true;
	return false;
}

bool isTimeLimitExceeded() {
	return tact == 1000000;
}

int nextInt() {
	int ans = inputs[currInt];
	if (currInt < inputs.size() - 1)
		currInt++;
	return ans;
}

void changeClock() {
	if (addA == 0 && addB == 1) {
		addA = 1;
		addB = 0;
	} else if (addA == 1 && addB == 0) {
		addA = 0;
		addB = -1;
	} else if (addA == 0 && addB == -1) {
		addA = -1;
		addB = 0;
	} else if (addA == -1 && addB == 0) {
		addA = 0;
		addB = 1;
	}
}

void workTask() {
	char com = prog[a][b];
	if (com == '.') {
		return;
	} else if (com >= 'A' && com <= 'Z') {
		int num = com - 'A';
		swap(reg0, regs[num]);
	} else if (com == '?') {
		reg0 = nextInt();
	} else if (com == '!') {
		cout << reg0 << endl;
		reg0 = 0;
	} else if (com == '+') {
		reg0++;
	} else if (com == '-') {
		reg0--;
	} else if (com == '@') {
		if (reg0 == 0) {
			changeClock();
			changeClock();
			changeClock();
		} else {
			changeClock();
		}
	} else if (com == '#') {
		run = false;
	}
}

void work() {
	while (run) {
		if (isRuntimeError()) {
			cout << "RUNTIME ERROR";
			return;
		}
		if (isTimeLimitExceeded()) {
			cout << "TIME LIMIT EXCEEDED";
			return;
		}
		setMove();
		workTask();
		next();
		tact++;
		if (isOverflowError()) {
			cout << "OVERFLOW ERROR";
			return;
		}
	}
}

int main() {
	fill(regs, regs + 26, 0);
	cin >> h >> w;
	for (int i = 0; i < h; i++)
		cin >> prog[i];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		inputs.pb(tmp);
	}
	work();
}



