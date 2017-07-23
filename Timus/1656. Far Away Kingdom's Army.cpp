// The solution of the problem was written by Izaron
// Date: 21:28:09   17 Jul 2015
// Execution time: 0.001

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

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
    int n;
    cin >> n;
    int ms[100];
    int ans[10][10];
    for(int i = 0; i < n * n; i++)
        cin >> ms[i];
    for(int i = 0; i < n; i++) {
        for(int z = 0; z < n; z++)
            ans[i][z] = 0;
    }
    sort(ms, ms + n * n);

    deque<pii> q;
    q.push_back(mkp(n / 2, n / 2));

    int cr = n * n - 1;
    while(!q.empty()) {
        pii p = q.front();
        q.pop_front();
        int x = p.ff, y = p.ss;
        if(x < 0 || y < 0 || x >= n || y >= n)
            continue;
        if(ans[x][y] != 0) continue;
        ans[x][y] = ms[cr];
        cr--;
        q.push_back(mkp(x - 1, y));
        q.push_back(mkp(x, y - 1));
        q.push_back(mkp(x + 1, y));
        q.push_back(mkp(x, y + 1));
    }

    for(int i = 0; i < n; i++) {
        for(int z = 0; z < n; z++)
            cout << ans[i][z] << " ";
        cout << endl;
    }
}



