#pragma comment(linker, "/STACK:16777216")
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

const int N = 100000 + 5;


ll SZ = 15;
ll numbers[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };

int main() {
    ll big = 1;
    for (int i = 0; i < SZ; i++)
        big *= numbers[i];

    ll ost[N];
    ost[0] = 1;
    for (int i = 1; i < N; i++) {
        for (int z = 0; z < 10; z++) {
            ost[i] += ost[i - 1];
            ost[i] %= big;
        }
    }

    map<ll, ll> ans;
    set<ll> cs;
    map<ll, int> cnter;
    int cnt = 0;

    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    int m;
    cin >> m;
    ll coms[N], as[N], bs[N];
    ll ukz[N], zn[N];
    vector<ll> vec;

    for (int i = 0; i < m; i++) {
        cin >> coms[i] >> as[i];
        if (coms[i] == 1) {
            cin >> bs[i];
            as[i]--;
        } else {
            if (!cnter.count(as[i])) {
                cnter[as[i]] = cnt;
                ukz[cnt] = as[i];
                zn[cnt] = 0;
                vec.pb(as[i]);
                cnt++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (coms[i] == 0) {
            as[i] = cnter[as[i]];
        }
    }

    ll st = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int z = 0; z < s[i] - '0'; z++) {
            st += ost[i];
            st %= big;
        }
    }

    for (int i = 0; i < cnt; i++)
        zn[i] = st % ukz[i];

    for (int i = 0; i < m; i++) {
        if (coms[i] == 0) {
            cout << zn[as[i]] << endl;
        } else {
            ll change = 0;
            int raz = (char)(bs[i] + '0') - s[as[i]];
            s[as[i]] = (char)(bs[i] + '0');

            for (int z = 0; z < abs(raz); z++) {
                change += ost[as[i]];
                change %= big;
            }
            ll mod = 1;
            if (raz < 0)
                mod = -mod;

            for (int z = 0; z < cnt; z++) {
                ll curr = zn[z];
                curr += mod * change;
                curr %= ukz[z];
                while (curr < 0)
                    curr += ukz[z];
                zn[z] = curr;
            }
        }
    }
}
