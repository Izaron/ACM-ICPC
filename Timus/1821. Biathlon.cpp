#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define mem0(m) memset((m), 0, sizeof(m));
#define memb(m) memset((m), false, sizeof(m));
typedef long long int ll;
typedef long double ld;





int main() {
    int n;
    cin >> n;
    vector<tuple<int,int,string>> v;    // time/realtime/name
    vector<string> ans;

    int curr = 1000000;

    for(int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        int time = atoi(t.substr(0,2).c_str()) * 600 +
                atoi(t.substr(3,2).c_str()) * 10 + atoi(t.substr(6,1).c_str());
        v.push_back(mt(time, time + i * 300, s));
    }

    sort(begin(v), end(v));

    for(int z = 0; z < v.size(); z++) {
        if(curr > get<1>(v[z])) {
            ans.pb(get<2>(v[z]));
            curr = get<1>(v[z]);
        }
    }

    sort(begin(ans), end(ans));

    cout << ans.size() << endl;
    for(auto it: ans)
        cout << it << endl;
}




























