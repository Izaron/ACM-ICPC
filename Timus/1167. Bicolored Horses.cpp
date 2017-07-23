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

//map<pair<ushi, ushi>, ushi> m;
int m[505][505];
int n;
int ms[505];

int dfs(int i, int k) {
    if(m[i][k] > -1)
        return m[i][k];
    if(k == 1) {
        int a = 0, b = 0;
        for(int z = i; z <= n; z++) {
            if(ms[z] == 1)
                a++;
            else
                b++;
        }
        m[i][k] = a * b;
        return m[i][k];
    }
    int a = 0, b = 0;
    int mini = 65530;
    for(int z = i; z < n; z++) {
        if(ms[z] == 1)
            a++;
        else
            b++;
        mini = min(mini, a * b + dfs(z + 1, k - 1));
    }

    m[i][k] = mini;
    return mini;
}

int main() {
    for(int i = 0; i < 505; i++) {
        for(int z = 0; z < 505; z++) {
            m[i][z] = -1;
        }
    }

    int k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> ms[i];
    }
    cout << dfs(1, k);
}














