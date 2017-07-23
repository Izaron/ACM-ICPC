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

    if(n == 1) {
        cout << "0";
        return 0;
    } else if(n == 2) {
        cout << "1\n1";
        return 0;
    }

    vector<int> ans;
    while(n > 1) {
        int cnt = n / 2;
        ans.pb(cnt);
        n -= cnt;
    }
    cout << ans.size() << endl;
    for(auto it: ans)
        cout << it << " ";
}














