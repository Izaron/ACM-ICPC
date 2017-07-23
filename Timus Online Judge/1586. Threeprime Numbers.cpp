// The solution of the problem was written by Izaron
// Date: 20:44:50   13 Oct 2015
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define pss pair<string,string>
#define pdd pair<ld,ld>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define ff first
#define ss second
typedef long long int ll;
typedef long double ld;



const int N = 10000 + 5;



vector<int> nxt[10][10];
int n;
ll ansi[N][10][10];

ll dfs(int v, int a, int b) {
    if(v == n)
        return 1;
    if(ansi[v][a][b] != -1)
        return ansi[v][a][b];
    ll ans = 0;
    for(auto it : nxt[a][b]) {
        ans += dfs(v + 1, b, it);
        ans %= 1000000009;
    }
    ansi[v][a][b] = ans;
    return ans;
}

bool isPrime(int v) {
    for(int i = 2; i <= sqrt(v); i++)
        if(v % i == 0)
            return false;
    return true;
}

int main() {
    int kek = 0;
    memset(ansi, -1, sizeof(ansi));
    for(int i = 100; i <= 999; i++) {
        if(isPrime(i)) {
            nxt[i / 100][(i / 10) % 10].pb(i % 10);
            kek++;
        }
    }

    cin >> n;

    if(n == 3) {
        cout << kek;
        return 0;
    }

    ll ans = 0;
    for(int i = 1; i < 10; i++)
    for(int z = 1; z < 10; z++) {
        ans += dfs(2, i, z);
        ans %= 1000000009;
    }

    cout << ans;
}


