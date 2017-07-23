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
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int N = 10000 + 5;

set<int> st;
set<int> stt;
vector<pii> sobss;
int color[N];
int starts[N];
int ens[N];
int clr[N];
int ms[N];
int n;
int a, b;

void work(ll delta) {
    if (delta == 0)
        return;
    if (st.size() == 0) {
        color[1] += delta * b;
        return;
    }

    stt.clear();
    sobss.clear();

    for (auto it : st) {
        sobss.pb(mkp(starts[it], -it - 1));
        sobss.pb(mkp(ens[it], +it + 1));
    }
    sort(sobss.begin(), sobss.end());

    int curr = 0;
    for (auto it : sobss) {
        if (stt.size() > 0)
            color[clr[*stt.rbegin()]] += (it.first - curr) * delta;
        else
            color[1] += (it.first - curr) * delta;
        curr = it.first;
        if (it.second > 0)
            stt.erase(it.second - 1);
        else
            stt.ins(-it.second - 1);
    }

    color[1] += (b - sobss.back().first) * delta;
}

int main() {
    memset(color, 0, sizeof(color));
    cin >> a >> b >> n;
    swap(a, b);

    vector<pii> sobs;
    for (int i = 0; i < n; i++) {
        int llx, lly, urx, ury, cl;
        cin >> llx >> lly >> urx >> ury >> cl;
        starts[i] = llx;
        ens[i] = urx;
        clr[i] = cl;
        sobs.pb(mkp(lly, i + 1));
        sobs.pb(mkp(ury, -i - 1));
    }

    sort(sobs.begin(), sobs.end());

    ll curr = 0;
    for (int i = 0; i < sobs.size(); i++) {
        work(sobs[i].first - curr);
        curr = sobs[i].first;
        if (sobs[i].second > 0) {
            st.insert(sobs[i].second - 1);
        } else {
            st.erase(-sobs[i].second - 1);
        }
    }
    color[1] += (a - sobs.back().first) * b;

    for (int i = 0; i < N; i++) {
        if (color[i] > 0) {
            cout << i << " " << color[i] << endl;
        }
    }
}