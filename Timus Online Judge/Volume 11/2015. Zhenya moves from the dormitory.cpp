// The solution of the problem was written by Izaron
// Date: 17:12:35   14 May 2015
// Execution time: 0.031

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

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
    int prem = -1, kvi = -1, fri = -1;

    int maxi, a, b;
    cin >> maxi >> a >> b;

    int n;
    cin >> n;
    tuple<int,int> fr[1000];
    for(int i = 0; i < n; i++) {
        int g, d;
        cin >> g >> d;
        fr[i] = mt(g, d);
    }

    int m;
    cin >> m;
    tuple<int,int,int> kv[1000];
    for(int i = 0; i < m; i++) {
        int g, d, l;
        cin >> g >> d >> l;
        kv[i] = mt(g, d, l);
    }

    // one
    for(int i = 0; i < m; i++) {
        if(get<1>(kv[i]) > maxi)
            continue;
        int d = get<2>(kv[i]);
        if(get<0>(kv[i]) == 1)
            d += a;
        else
            d += b;
        if(d > prem) {
            prem = d;
            kvi = i;
        }
    }

    // two
    for(int i = 0; i < m; i++) {
        if(get<0>(kv[i]) == 1)
            continue;
        for(int z = 0; z < n; z++) {
            if((get<1>(kv[i]) + 1) / 2 > get<0>(fr[z]))
                continue;
            if((get<1>(kv[i]) + 1) / 2 > maxi)
                continue;
            if(get<2>(kv[i]) + get<1>(fr[z]) > prem) {
                prem = get<2>(kv[i]) + get<1>(fr[z]);
                kvi = i;
                fri = z;
            }
        }
    }

    if(prem == -1) {
        cout << "Forget about apartments. Live in the dormitory.";
    } else if(fri == -1) {
        cout << "You should rent the apartment #" << kvi + 1 << " alone.";
    } else {
        cout << "You should rent the apartment #" << kvi + 1 << " with the friend #" << fri + 1 << ".";
    }
}





















