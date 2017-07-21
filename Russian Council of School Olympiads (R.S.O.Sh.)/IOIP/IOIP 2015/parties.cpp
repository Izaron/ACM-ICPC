#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define pss pair<int,int>
#define pdd pair<double,double>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define ff first
#define ss second
typedef unsigned long long int ll;
typedef long double ld;






const int N = 100000 + 5;


int sum = 0;
vector<int> vec;
bool can = false;
int n;
int ms[N];

void kek() {
    for(int i = 0, cnt = 1; i < n; i += 2, cnt++) {
        sum += ms[i];
        vec.pb(ms[i]);
        if(cnt + sum == n) {
            can = true;
            break;
        }
    }

    if(can)
        return;
    sum = 0;
    vec.clear();

    for(int i = 1, cnt = 1; i < n; i += 2, cnt++) {
        sum += ms[i];
        vec.pb(ms[i]);
        if(cnt + sum == n) {
            can = true;
            break;
        }
    }

    if(can)
        return;
    sum = 0;
    vec.clear();

    for(int i = n - 1, cnt = 1; i >= 0; i -= 2, cnt++) {
        sum += ms[i];
        vec.pb(ms[i]);
        if(cnt + sum == n) {
            can = true;
            break;
        }
    }

    if(can)
        return;
    sum = 0;
    vec.clear();

    for(int i = n - 2, cnt = 1; i >= 0; i -= 2, cnt++) {
        sum += ms[i];
        vec.pb(ms[i]);
        if(cnt + sum == n) {
            can = true;
            break;
        }
    }

    if(can)
        return;

    sum = 0;
    vec.clear();
}

int main() {
    freopen("parties.in", "r", stdin);
    freopen("parties.out", "w", stdout);

    cin >> n;

    int lol[N];
    for(int i = 0; i < n; i++) {
        cin >> ms[i];
        lol[i] = ms[i];
    }

    sort(ms, ms + n);

    kek();

    if(vec.size() == 0) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;

    multiset<int> st;

    for(auto it : vec)
        st.insert(it);

    for(int i = 0; i < n; i++) {
        if(st.count(lol[i])) {
            cout << 1 << " ";
            st.erase(st.find(lol[i]));
        } else {
            cout << 2 << " ";
        }
    }
}