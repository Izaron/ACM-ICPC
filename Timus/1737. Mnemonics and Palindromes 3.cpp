#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <sstream>
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
typedef tuple<int, int, int, int, int> tt;

const int N = 20000 + 5;


int n;
bool tooLong = false;
int anss[N][4][4];

int dfs(int v, int a, int b) {
    if (v >= n)
        return 1;
    if (anss[v][a][b] != -1)
        return anss[v][a][b];

    int ans = 0;
    for (int i = 1; i <= 3; i++) {
        if (i != a && i != b) {
            ans += dfs(v + 1, b, i);
            ll kek = (ll)ans * (ll)n;
            if (kek > 100000)
                tooLong = true;
        }
    }

    anss[v][a][b] = ans;
    return ans;
}

string str = "";
void print(int v, int a, int b) {
    if (v >= n) {
        cout << str << endl;
        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (i != a && i != b) {
            str += (i - 1 + 'a');
            print(v + 1, b, i);
            str.erase(str.begin() + str.size() - 1);
        }
    }
}

int main() {
    memset(anss, -1, sizeof(anss));
    scanf("%d", &n);
    dfs(0, 0, 0);
    if (tooLong) {
        printf("TOO LONG");
        return 0;
    } else {
        print(0, 0, 0);
    }
}
