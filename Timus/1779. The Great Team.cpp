#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define eb emplace_back
#define pb push_back
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define mem0(m) memset((m), 0, sizeof(m));
#define mem0d(m) memset((m), 0.0, sizeof(m));
#define memb(m) memset((m), false, sizeof(m));
typedef long long int ll;
typedef long double ld;





int main() {
    int n;
    cin >> n;
    vector<pii> v;

    int k = n - 1;
    for(int i = 0; i < n; i++) {
        for(int z = i + 1; z < i + 1 + k; z++) {
            v.pb({i + 1, z + 1});
        }
        k -= 2;
    }

    cout << v.size() << endl;
    for(auto it: v) {
        cout << it.first << " " << it.second << endl;
    }
}
























