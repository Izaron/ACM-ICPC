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


const int N = (1 << 21);

bool used[N];
int ans[N];

int main() {
	fill(used, used + N, false);
	int n;
	scanf("%d", &n);
	int len = (1 << n) + n - 1;
	for (int i = 0; i < n; i++)
		ans[i] = 0;
	used[0] = true;
	int curr = 0;
	int mod = (1 << n);
	for (int i = n; i < len; i++) {
		curr *= 2;
		curr %= mod;
		if (!used[curr + 1]) {
			curr++;
			ans[i] = 1;
		} else {
			ans[i] = 0;
		}
		used[curr] = true;
	}
	for (int i = 0; i < len; i++)
		printf("%d", ans[i]);
}

