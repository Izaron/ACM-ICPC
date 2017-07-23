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
typedef tuple<int, int, int> tt;

const int N = 7500 + 5;


int n;
int ms[N];
vector<int> neig[N];
int cnt[N];
set<int> st;

int main() {
    memset(cnt, 0, sizeof(cnt));
    string s;
    getline(cin, s);
    stringstream ss(s);

    while (!ss.eof()) {
        ss >> ms[n];
        ms[n]--;
        n++;
    }

    for (int i = 0; i < n; i++)
        cnt[ms[i]]++;

    for (int i = 0; i <= n; i++) {
        if (cnt[i] == 0)
            st.insert(i);
    }

    for (int i = 0; i < n; i++) {
        int curr = *st.begin();
        st.erase(curr);
        neig[ms[i]].pb(curr);
        neig[curr].pb(ms[i]);
        cnt[ms[i]]--;
        if (cnt[ms[i]] == 0)
            st.insert(ms[i]);
    }

    for (int i = 0; i <= n; i++) {
        sort(neig[i].begin(), neig[i].end());
        cout << i + 1 << ": ";
        for (auto it : neig[i])
            cout << it + 1 << " ";
        cout << endl;
    }
}
