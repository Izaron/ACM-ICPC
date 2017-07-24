// The solution of the problem was written by Izaron
// Date: 16:47:08   8 Oct 2015
// Execution time: 0.14

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define pss pair<string,string>
#define pdd pair<ld,ld>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define ff first
#define ss second
typedef long long int ll;
typedef long double ld;



const int N = 100000 + 5;


string minCyclicShift(string s) {
	s += s;

	int n = (int)s.length();
	int i = 0, ans = 0;

	while(i < n / 2) {
		ans = i;
		int j= i + 1, k = i;
		while(j < n && s[k] <= s[j]) {
			if (s[k] < s[j])
				k = i;
			else
				++k;
			++j;
		}
		while(i <= k)
            i += j - k;
	}

	return s.substr (ans, n/2);
}

int minCyclicShiftInt(string s) {
	s += s;

	int n = (int)s.length();
	int i = 0, ans = 0;

	while(i < n / 2) {
		ans = i;
		int j= i + 1, k = i;
		while(j < n && s[k] <= s[j]) {
			if (s[k] < s[j])
				k = i;
			else
				++k;
			++j;
		}
		while(i <= k)
            i += j - k;
	}

	return ans + 1;
}


int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if(minCyclicShift(a) != minCyclicShift(b)) {
        cout << -1;
        return 0;
    }

    int aa = minCyclicShiftInt(a);
    int bb = minCyclicShiftInt(b);

    //cout << aa << " " << bb << endl;

    if(aa > bb) {
        cout << n - aa + bb;
    } else {
        cout << bb - aa;
    }
}



