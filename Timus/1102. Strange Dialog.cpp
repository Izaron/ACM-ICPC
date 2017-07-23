//#include <bits/stdc++.h>
#include <fstream>
#include <bitset>
#include <stdio.h>
#include <cstring>
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


char s[10000010];
int len;
bitset<10000010> mp;
bitset<10000010> used;


bool dfs(int a) {
    if(used[a])
        return mp[a];

    if(a == len) {
        mp.set(a);
        used.set(a);
        return 1;
    }

    bool can = false;

    if(a + 6 <= len) {
        bool kek = false;

        if(s[a] == 'o' && s[a + 1] == 'u' && s[a + 2] == 't' &&
                s[a + 3] == 'p' && s[a + 4] == 'u' && s[a + 5] == 't')
            kek = true;

        if(kek) {
            if(dfs(a + 6)) can = 1;
        }
    }

    if(a + 5 <= len) {
        bool kek = false;

        if(s[a] == 'p' && s[a + 1] == 'u' && s[a + 2] == 't' &&
                s[a + 3] == 'o' && s[a + 4] == 'n')
            kek = true;

        if(s[a] == 'i' && s[a + 1] == 'n' && s[a + 2] == 'p' &&
                s[a + 3] == 'u' && s[a + 4] == 't')
            kek = true;

        if(kek) {
            if(dfs(a + 5)) can = 1;
        }
    }

    if(a + 3 <= len) {
        bool kek = false;

        if(s[a] == 'o' && s[a + 1] == 'u' && s[a + 2] == 't')
            kek = true;

        if(s[a] == 'o' && s[a + 1] == 'n' && s[a + 2] == 'e')
            kek = true;

        if(kek) {
            if(dfs(a + 3)) can = 1;
        }
    }

    if(a + 2 <= len) {
        bool kek = false;

        if(s[a] == 'i' && s[a + 1] == 'n')
            kek = true;

        if(kek) {
            if(dfs(a + 2)) can = 1;
        }
    }

    used.set(a);
    mp.set(a, can);
    return can;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", &s);
        len = strlen(s);

        for(int z = len - 1; z >= 0; z--)
            dfs(z);
        
        if(dfs(0))
            printf("YES\n");
        else
            printf("NO\n");
        for(int z = 0; z < len; z++) {
            mp.set(z, 0);
            used.set(z, 0);
        }
    }
}















