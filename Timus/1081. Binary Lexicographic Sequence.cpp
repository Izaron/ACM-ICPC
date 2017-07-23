#include <iostream>
#include <string>
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
typedef long long int ll;
typedef long double ld;






int main() {
    /*int cnt = 1;
    for(int v = 0; v < 2000; v++) {
        bool can = true;
        for(int z = 0; z < 24; z++) {
            if((v & (1 << z)) != 0 && (v & (1 << (z + 1))) != 0) {
                can = false;
                break;
            }
        }
        if(can) {
            for(int z = 24 - 1; z >= 0; z--) {
                cout << min(1, (v & (1 << z)));
            }
            cout << " " << cnt << endl;
            cnt++;
            //cout << v << endl;
        }
    }*/

    ll f[100];
    f[0] = 1;
    f[1] = 1;
    for(int i = 2; i < 50; i++)
        f[i] = f[i - 2] + f[i - 1];
    //cout << f[44 + 1];

    ll n, k;
    cin >> n >> k;

    if(k > f[n + 1]) {
        cout << -1;
        return 0;
    }

    int curr = 45;
    string s = "";
    while(k > 1) {
        if(k >= f[curr - 1] + 1 && k <= f[curr]) {
            s += "1";
            k -= f[curr - 1];
        } else {
            s += "0";
        }
        curr--;
    }
    while(curr > 1) {
        s += "0";
        curr--;
    }

    cout << s.substr(s.size() - n);
}



