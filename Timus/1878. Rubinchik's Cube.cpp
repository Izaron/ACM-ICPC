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

#define as(a,b) for(int xxx = 0; xxx < 4; xxx++) \
                    for(int yyy = 0; yyy < 4; yyy++) \
                        a[xxx][yyy] = b[xxx][yyy];


int main() {
    int LOL = 100500;

    int m[4][4];
    for(int i = 0; i < 4; i++) {
        for(int z = 0; z < 4; z++) {
            cin >> m[i][z];
        }
    }

    int a, b, c, d;

    int tmp[4][4];

    for(int i = 0; i < 4; i++) {
        int t[4][4];
        as(t, m);
        if(i == 0) {
            a = 0;
        } else if(i == 1) {
            a = 1;
            as(tmp,t);
            t[1][0] = tmp[3][1];
            t[3][1] = tmp[2][3];
            t[2][3] = tmp[0][2];
            t[0][2] = tmp[1][0];
        } else if(i == 2) {
            a = 2;
            as(tmp,t);
            t[1][0] = tmp[2][3];
            t[3][1] = tmp[0][2];
            t[2][3] = tmp[1][0];
            t[0][2] = tmp[3][1];
        } else if(i == 3) {
            a = 1;
            as(tmp,t);
            t[1][0] = tmp[0][2];
            t[3][1] = tmp[1][0];
            t[2][3] = tmp[3][1];
            t[0][2] = tmp[2][3];
        }


        for(int z = 0; z < 4; z++) {
            int q[4][4];
            as(q, t);

            if(z == 0) {
                b = 0;
            } else if(z == 1) {
                b = 1;
                as(tmp,q);
                q[2][0] = tmp[0][1];
                q[0][1] = tmp[1][3];
                q[1][3] = tmp[3][2];
                q[3][2] = tmp[2][0];
            } else if(z == 2) {
                b = 2;
                as(tmp,q);
                q[2][0] = tmp[1][3];
                q[0][1] = tmp[3][2];
                q[1][3] = tmp[2][0];
                q[3][2] = tmp[0][1];
            } else if(z == 3) {
                b = 1;
                as(tmp,q);
                q[2][0] = tmp[3][2];
                q[0][1] = tmp[2][0];
                q[1][3] = tmp[0][1];
                q[3][2] = tmp[1][3];
            }

            for(int s = 0; s < 4; s++) {
                int r[4][4];
                as(r, q);

                if(s == 0) {
                    c = 0;
                } else if(s == 1) {
                    c = 1;
                    as(tmp,r);
                    r[1][1] = tmp[1][2];
                    r[1][2] = tmp[2][2];
                    r[2][1] = tmp[1][1];
                    r[2][2] = tmp[2][1];
                } else if(s == 2) {
                    c = 2;
                    as(tmp,r);
                    r[1][1] = tmp[2][2];
                    r[1][2] = tmp[2][1];
                    r[2][1] = tmp[1][2];
                    r[2][2] = tmp[1][1];
                } else if(s == 3) {
                    c = 1;
                    as(tmp,r);
                    r[1][1] = tmp[2][1];
                    r[1][2] = tmp[1][1];
                    r[2][2] = tmp[1][2];
                    r[2][1] = tmp[2][2];
                }

                for(int su = 0; su < 4; su++) {
                    int ans[4][4];
                    as(ans, r);

                    if(su == 0) {
                        d = 0;
                    } else if(su == 1) {
                        d = 1;
                        as(tmp,ans);
                        ans[0][0] = tmp[0][3];
                        ans[0][3] = tmp[3][3];
                        ans[3][3] = tmp[3][0];
                        ans[3][0] = tmp[0][0];
                    } else if(su == 2) {
                        d = 2;
                        as(tmp,ans);
                        ans[0][0] = tmp[3][3];
                        ans[0][3] = tmp[3][0];
                        ans[3][3] = tmp[0][0];
                        ans[3][0] = tmp[0][3];
                    } else if(su == 3) {
                        d = 1;
                        as(tmp,ans);
                        ans[0][0] = tmp[3][0];
                        ans[0][3] = tmp[0][0];
                        ans[3][3] = tmp[0][3];
                        ans[3][0] = tmp[3][3];
                    }

                    bool fak = true;

                    if(ans[0][0] != ans[1][0] || ans[0][0] != ans[0][1] || ans[0][0] != ans[1][1]) {
                        fak = false;
                    }
                    if(ans[2][0] != ans[3][0] || ans[2][0] != ans[2][1] || ans[2][0] != ans[3][1]) {
                        fak = false;
                    }
                    if(ans[0][2] != ans[1][2] || ans[0][2] != ans[0][3] || ans[0][2] != ans[1][3]) {
                        fak = false;
                    }
                    if(ans[2][2] != ans[3][2] || ans[2][2] != ans[2][3] || ans[2][2] != ans[3][3]) {
                        fak = false;
                    }

                    if(fak) {
                        LOL = min(LOL, a + b + c + d);
                    }
                }
            }
        }
    }

    cout << LOL;
}

// WHAT THE FUCKING HELL IS THIS TASK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!






















