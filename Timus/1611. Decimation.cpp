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

const int N = 11000 + 5;


string s;
int n;
int maxK;
int anss[N][55];

int dfs(int v, int k) {
    if (v - k >= n)
        return 0;

    if (anss[v][k] != -1)
        return anss[v][k];

    int ans2 = 1000000000;
    ans2 = dfs(v + 1, k);
    if (s[v - k] == '1' && (v + 1) % 10 == 0)
        ans2++;

    int ans1 = 1000000000;

    if (k < maxK) {
        ans1 = dfs(v + 1, k + 1);
        if ((v + 1) % 10 == 0)
            ans1++;
    }

    anss[v][k] = min(ans1, ans2);
    return min(ans1, ans2);
}

vector<int> vec;

void vosst(int v, int k) {
    if (v - k >= n)
        return;

    int ans1 = 1000000000;

    if (k < maxK) {
        ans1 = dfs(v + 1, k + 1);
        if ((v + 1) % 10 == 0)
            ans1++;
    }

    int ans2 = 1000000000;
    ans2 = dfs(v + 1, k);
    if (s[v - k] == '1' && (v + 1) % 10 == 0)
        ans2++;

    if (min(ans1, ans2) == ans2) {
        vosst(v + 1, k);
    } else {
        vec.pb(v + 1);
        vosst(v + 1, k + 1);
    }
}

int main() {
    memset(anss, -1, sizeof(anss));
    cin >> n >> maxK >> s;
    cout << dfs(0, 0) << endl;
    vosst(0, 0);
    cout << vec.size() << " ";
    for (auto it : vec)
        cout << it << " ";
}
