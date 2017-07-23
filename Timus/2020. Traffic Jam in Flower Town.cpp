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
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int cnt = 0;
    while(a.size() || b.size()) {
        cnt++;
        if(a.size() > 0) {
            if(b.size() > 0) {
                if(a[a.size() - 1] == 'L' && b[b.size() - 1] != 'L') {
                    b.erase(b.begin() + b.size() - 1);
                } else if(a[a.size() - 1] != 'L' && b[b.size() - 1] == 'L') {
                    a.erase(a.begin() + a.size() - 1);
                } else {
                    a.erase(a.begin() + a.size() - 1);
                    b.erase(b.begin() + b.size() - 1);
                }
            } else {
                a.erase(a.begin() + a.size() - 1);
            }
        } else {
            b.erase(b.begin() + b.size() - 1);
        }
    }
    cout << cnt;
}
























