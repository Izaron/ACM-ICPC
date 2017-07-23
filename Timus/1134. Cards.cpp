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
typedef long long int ll;
typedef long double ld;



int main() {
    int n, m;
    cin >> n >> m;
    bool used[1005];
    fill(used, used + 1005, false);
    int ms[1005];
    for(int i = 0; i < m; i++)
        cin >> ms[i];
    sort(ms, ms + m);
    for(int i = 0; i < m; i++) {
        int ind = -1;
        for(int z = 0; z < n; z++) {
            if((ms[i] == z || ms[i] == z + 1) && !used[z]) {
                ind = z;
                break;
            }
        }
        if(ind == -1) {
            cout << "NO";
            return 0;
        }
        used[ind] = true;
    }
    cout << "YES";
}











