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
typedef unsigned long long int ll;
typedef long double ld;






const int N = 200000 + 5;

int a[N];
int t[4*N];

void build(int v, int l, int r) {
    if(l == r) {
        t[v] = a[l];
    } else {
        build(v*2, l, (l+r)/2);
        build(v*2+1, (l+r)/2+1, r);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int gett(int v, int L, int R, int l, int r) {
    if(r < L || R < l)
        return 0;
    if(l >= L && r <= R)
        return t[v];
    return gett(v*2, L, R, l, (l+r)/2) +
            gett(v*2+1, L, R, (l+r)/2+1, r);
}

void sett(int v, int l, int r, int pos) {
    if(l == r) {
        t[v] = 1;
    } else {
        if(pos <= (l+r)/2)
            sett(v*2, l, (l+r)/2, pos);
        else
            sett(v*2+1, (l+r)/2+1, r, pos);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main() {
    freopen("longqueue.in", "r", stdin);
    freopen("longqueue.out", "w", stdout);

    fill(a, a + N, 0);

    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp >= x)
            a[i] = 1;
        else
            a[i] = 0;
    }

    build(1, 0, N - 1);

    int m;
    cin >> m;
    int st = 0, en = n - 1;
    while(m--) {
        int com;
        cin >> com;
        if(com == 1) {
            en++;
            int tmp;
            cin >> tmp;
            if(tmp >= x)
                sett(1, 0, N - 1, en);
        } else if(com == 2) {
            st++;
        } else {
            int kek;
            cin >> kek;
            cout << gett(1, st, st + kek - 1, 0, N - 1) << endl;
        }
    }
}