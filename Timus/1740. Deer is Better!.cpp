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
    int l, k, h;
    cin >> l >> k >> h;
    if(l % k == 0) {
        cout << fixed << setprecision(10) << (double)(l / k * h) << " " << (double)(l / k * h);
    } else {
        cout << fixed << setprecision(10) << (double)(l / k * h) << " " << (double)((l / k + 1) * h);
    }
}























