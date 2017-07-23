#include <bits/stdc++.h>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

const int N = 100000 + 5;

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        cout << 14;
    } else if (n == 2) {
        cout << 155;
    } else {
        cout << 1575;
        for (int i = 0; i < n - 3; i++)
            cout << 0;
    }
}