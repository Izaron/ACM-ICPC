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





const int N = 3 * 100000 + 5;


int main() {
    #ifdef ONLINE_JUDGE
        freopen("battle.in", "r", stdin);
        freopen("battle.out", "w", stdout);
    #endif // ONLINE_JUDGE

    int n, k;
    cin >> n >> k;

    int ms[N];
    for(int i = 0; i < n; i++)
        cin >> ms[i];

    for(int i = 0; i < k; i++) {
        for(int z = 0; z < n - 1; z++) {
            if(ms[z] > ms[z + 1])
                swap(ms[z], ms[z + 1]);
        }
    }

    for(int i = 0; i < n; i++)
        cout << ms[i] << " ";
}
