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
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int N = 100 + 5;


int x, y, tmp, curr, kz;
vector<int> vec;

bool can(int v) {
    vec.clear();
    tmp = y;
    curr = 0;
    while (tmp > 0) {
        vec.pb(tmp % v);
        tmp /= v;
    }
    tmp = x;
    while (tmp > 0) {
        kz = tmp % v;
        if (curr < vec.size() && kz == vec[curr]) {
            curr++;
            if (curr == vec.size())
                return true;
        }
        tmp /= v;
    }

    return false;
}

int main() {
    scanf("%d%d", &x, &y);
    for (int i = 2; i <= max(x, y); i++) {
        if (can(i)) {
            printf("%d", i);
            return 0;
        }
    }
    printf("No solution");
}
