#include <bits/stdc++.h>
#include <ctime>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define eb emplace_back
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define pii pair<ll,ll>
#define pss pair<int,int>
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



const int N = 1005;

string s;
int d[N][N][2];
bool used[N][N][2];
pii a[N][N][2];

void solve();

int main() {
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
}

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    cin >> s;

    d[1][1][0] = (s[0] == '1');
    d[1][1][1] = (s[0] == '0');
    a[1][1][0] = mkp(0, 0);
    a[1][1][1] = mkp(0, 1);

    for(int i = 1; i < n; i++) {
        for(int m = 1; m <= min(k, i); m++) {
            if(!used[i + 1][m][0]) {
                d[i + 1][m][0] = d[i][m][0] + (s[i] != '0');
                a[i + 1][m][0] = mkp(m, 0);
                used[i + 1][m][0] = true;
            } else {
                if(d[i + 1][m][0] > d[i][m][0] + (s[i] != '0')) {
                    d[i + 1][m][0] = d[i][m][0] + (s[i] != '0');
                    a[i + 1][m][0] = mkp(m, 0);
                }
            }

            if(!used[i + 1][m + 1][0]) {
                d[i + 1][m + 1][0] = d[i][m][1] + (s[i] != '0');
                a[i + 1][m + 1][0] = mkp(m, 1);
                used[i + 1][m + 1][0] = true;
            } else {
                if(d[i + 1][m + 1][0] > d[i][m][1] + (s[i] != '0')) {
                    d[i + 1][m + 1][0] = d[i][m][1] + (s[i] != '0');
                    a[i + 1][m + 1][0] = mkp(m, 1);
                }
            }

            if(!used[i + 1][m][1]) {
                d[i + 1][m][1] = d[i][m][1] + (s[i] != '1');;
                a[i + 1][m][1] = mkp(m, 1);
                used[i + 1][m][1] = true;
            } else {
                if(d[i + 1][m][1] > d[i][m][1] + (s[i] != '1')) {
                    d[i + 1][m][1] = d[i][m][1] + (s[i] != '1');
                    a[i + 1][m][1] = mkp(m, 1);
                }
            }

            if(!used[i + 1][m + 1][1]) {
                d[i + 1][m + 1][1] = d[i][m][0] + (s[i] != '1');
                a[i + 1][m + 1][1] = mkp(m, 0);
                used[i + 1][m + 1][1] = true;
            } else {
                if(d[i + 1][m + 1][1] > d[i][m][0] + (s[i] != '1')) {
                    d[i + 1][m + 1][1] = d[i][m][0] + (s[i] != '1');
                    a[i + 1][m + 1][1] = mkp(m, 0);
                }
            }
        }
    }

    int ans = d[n][k][0];
    int kk = k, c = 0;
    pii p = a[n][k][0];
    for(int i = k; i >= 1; i--) {
        if(d[n][i][0] < ans) {
            ans = d[n][i][0];
            p = a[n][i][0];
            c = 0;
        }
        if(d[n][i][1] < ans) {
            ans = d[n][i][1];
            p = a[n][i][1];
            c = 1;
        }
    }

    string cs = "";
    cs += (char)(c + '0');

    int nn = n;
    while(true) {
        if(nn <= 1) break;
        p = a[nn][p.first][p.second];
        cs += (char)(p.second + '0');
        nn--;
        if(nn == 1)
            break;
    }

    reverse(cs.begin(), cs.end());

    cout << cs << endl;

    for(int i = 0; i <= max(k, n); i++) {
        for(int z = 0; z <= max(k, n); z++) {
            used[i][z][0] = false;
            used[i][z][1] = false;
        }
    }
}