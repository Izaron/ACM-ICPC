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
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tt;

const int N = 2 * 100000 + 5;


void work(int n) {
    string s1, s2;
    cin >> s1;
    s2 = s1;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    reverse(s2.begin(), s2.end());

    int a = 0, b = 1;
    bool nado = true;
    for (int i = 0; i < n; i++) {
    	for (int z = i + 1; z < n; z++) {
    		if (s1[i] == s1[z] && s2[i] == s2[z] && nado) {
    			a = i;
    			b = z;
    			nado = false;
    		}
    	}
    }

    for (int i = n; i >= 1; i--) {
        for (int z = i - 1; z >= 1; z--) {
            cout << "? " << i << " " << z << endl;
        }
    }

    cout << "! " << a + 1 << " " << b + 1 << endl;
}

int main() {
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
    	work(i + 2);
    }
}

