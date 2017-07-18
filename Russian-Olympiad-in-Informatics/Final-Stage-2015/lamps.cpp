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
 
 
 
 
 
const int N = 300000 + 5;
const ll MOD = 1000000007;
 
ll ans = 0;
 
int maxi[N];
 
char ch[N];
int n;
 
void sett(int a, int b) {
    for(int i = a; i <= b; i++) {
        //maxi[i] = max(maxi[i], b);
        if(maxi[i] == -1) {
            ans += b - i + 1;
            maxi[i] = b;
        } else if(maxi[i] < b) {
            ans += b - maxi[i];
            maxi[i] = b;
        }
    }
}
 
void obr() {
    int a = -1;
    for(int i = 0; i < n; i++) {
        if(ch[i] == '1') {
            if(a == -1)
                a = i;
        } else if(a != -1) {
            sett(a, i - 1);
            a = -1;
        }
    }
    if(a != -1)
        sett(a, n - 1);
}
 
int main() {
    #ifdef ONLINE_JUDGE
    //    freopen("lamps.in", "r", stdin);
    //    freopen("lamps.out", "w", stdout);
    #endif // ONLINE_JUDGE
 
    fill(maxi, maxi + N, -1);
 
    int q;
    scanf("%d%d", &n, &q);
    scanf("%s", &ch);
 
    obr();
    printf("%I64d\n", ans);
 
    while(q--) {
        int a, b, x;
        scanf("%d%d%d", &a, &b, &x);
        a--;
        b--;
        x += '0';
        for(int i = a; i <= b; i++)
            ch[i] = x;
        if(x == '1')
            obr();
        printf("%I64d\n", ans);
    }
}