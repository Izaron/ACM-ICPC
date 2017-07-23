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

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        if (i < k - 1) {
            if (i % 2 == 0)
                printf("%d ", (i / 2) + 1);
            else
                printf("%d ", -(i / 2) - 1);
        } else {
            printf("0 ");
        }
    }
}
