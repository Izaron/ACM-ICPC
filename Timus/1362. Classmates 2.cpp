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

const int N = 100000 + 5;


vector<int> neig[N];

int calc(int id, int last) {
    int maxi = 0;
    vector<int> all;
    for (auto it : neig[id]) {
        if (it == last)
            continue;
        all.pb(calc(it, id));
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    for (int i = 0; i < all.size(); i++) {
        all[i] += i + 1;
        maxi = max(maxi, all[i]);
    }

    return maxi;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int tmp;
        while (true) {
            scanf("%d", &tmp);
            if (tmp == 0)
                break;
            tmp--;
            neig[i].pb(tmp);
            neig[tmp].pb(i);
        }
    }
    int id;
    scanf("%d", &id);
    id--;

    cout << calc(id, id);
}
