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
    int n1, c1;
    cin >> n1 >> c1;
    int n2, t, c2;
    cin >> n2 >> t >> c2;
    int n3;
    cin >> n3;

    int a = n1, b = n2, c = n3;

    int n;
    cin >> n;

    t *= -1;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int mins = atoi(s.substr(0, 2).c_str());
        int secs = atoi(s.substr(3, 2).c_str());

        if(mins == 0 && secs <= 6) {
            continue;
        }

        if(secs != 0)
            mins++;

        a += c1 * mins;
        t += mins;
    }

    b += c2 * max(0, t);

    cout << "Basic:     " << a << endl;
    cout << "Combined:  " << b << endl;
    cout << "Unlimited: " << c << endl;
}
























