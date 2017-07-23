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
typedef pair<int, int> pii;

const int N = 10000 + 5;


int ans[N];
int ms[55];
int n, m;

int gett(int v) {
    if (v == 0)
        return 1;
    if (ans[v] != -1)
        return ans[v];
    int curr = 2;
    for (int i = 0; i < m; i++) {
        if (v >= ms[i]) {
            if (gett(v - ms[i]) == 2) {
                curr = 1;
            }
        }
    }
    ans[v] = curr;
    return curr;
}

int main() {
    memset(ans, -1, sizeof(ans));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &ms[i]);
    printf("%d\n", gett(n));
}