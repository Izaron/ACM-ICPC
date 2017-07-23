// The solution of the problem was written by Izaron
// Date: 16:01:56   30 May 2015
// Execution time: 0.062

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
#define For(i,st,n) for(int (i) = (st); (i) < (n); (i)++)
#define rof(i,st,n) for(int (i) = (st); (i) > (n); (i)--)
#define rep(i,st) for(auto &(i) : (st))
typedef long long int ll;
typedef long double ld;



vector<int> t;
int ans[32010];
int n;

int sum (int r)
{
    int result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        result += t[r];
    return result;
}

void inc (int i, int delta)
{
    for (; i <= 32000; i = (i | (i + 1)))
        t[i] += delta;
}

int main() {
    pii m[15005];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &m[i].first, &m[i].second);
        m[i].first++;
        m[i].second++;
    }
    sort(m, m + n);
    t.assign(32010, 0);
    mem0(ans);
    for(int i = 0; i < n; i++) {
        inc(m[i].second - 1, 1);
        int kek = sum(m[i].second - 1);
        ans[kek]++;
    }
    for(int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
}



















