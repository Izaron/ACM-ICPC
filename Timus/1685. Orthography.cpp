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
typedef unsigned int uint;
typedef long long int ll;
typedef long double ld;


string s;
string kek;

int curr = 0;

void dfs(int a, int b) {
    if(a > b) return;
    int z = (a + b) / 2;
    kek[z] = s[curr];
    curr++;
    dfs(a, z - 1);
    dfs(z + 1, b);
}

int main() {
    getline(cin, s);
    kek = s;
    for(int i = 0; i < kek.size(); i++) kek[i] = ' ';
    dfs(0, s.size() - 1);
    cout << kek;
}















