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
typedef tuple<int, int, int, int> tt;

const int N = 3 * 100000 + 5;


int n;
string s;
ll starts[N];
ll ens[N];

bool has(int a, int b) {
    int cnt = 0;
    for (int i = a; i <= b; i++) {
        if (s[a + cnt] != s[b - cnt])
            return false;
        cnt++;
    }
    return true;
}

int main() {
    cin >> s;
    memset(ens, 0, sizeof(ens));
    memset(starts, 0, sizeof(starts));

    /*for (int i = 0; i < s.size(); i++) {
        for (int z = i; z < s.size(); z++) {
            if (has(i, z)) {
                starts[i]++;
                //if ((z - i + 1) % 2 == 0)
                //    ens[z]++;
            }
        }
    }*/

    n = s.size();

    int d1[N], d2[N];
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));

    int l=0, r=-1;
    for(int i = 0; i < n; i++){
        int k;
        if(i > r) k = 1;
        else k = min(d1[l + r - i], r - i);

        while(0 <= i-k && i+k < n && s[i - k] == s[i + k]) k++;
        d1[i] = k;
        if(i + k - 1 > r)
            r = i + k - 1, l = i - k + 1;
    }

    l=0, r=-1;
    for(int i = 0; i < n; i++){
        int k;
        if(i > r) k = 0;
        else k = min(d2[l + r - i + 1], r - i + 1);

        while(i + k < n && i - k - 1 >= 0 && s[i+k] == s[i - k - 1]) k++;
        d2[i] = k;

        if(i + k - 1 > r)
            l = i - k, r = i + k - 1;
    }

    vector<int> ens1(n + 1);
    for (int i = 0; i < n; i++) {
        int start = i - d1[i] + 1;
        int end = i + 1;
        ens1[start]++;
        ens1[end]--;
    }
    for (int i = 0; i < n; i++) {
        int start = i - d2[i];
        int end = i;
        ens1[start]++;
        ens1[end]--;
    }
    starts[0] += ens1[0];
    for (int i = 1; i < n; i++) {
        ens1[i] += ens1[i - 1];
        starts[i] += ens1[i];
    }

    vector<int> ens2(n + 1);
    for (int i = 0; i < n; i++) {
        int start = i;
        int enk = i + d1[i];
        ens2[start]++;
        ens2[enk]--;
    }
    for (int i = 0; i < n; i++) {
        int start = i;
        int enk = i + d2[i];
        ens2[start]++;
        ens2[enk]--;
    }

    ens[0] += ens2[0];
    for (int i = 1; i < n; i++) {
        ens2[i] += ens2[i - 1];
        ens[i] += ens2[i];
    }


    ll ans = 0;
    for (int i = 1; i < s.size(); i++)
        ans += ens[i - 1] * starts[i];
    cout << ans;
}
