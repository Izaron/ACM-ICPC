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





int main() {
    int a = 0, b = 0;
    char ch;
    string s = "";
    while(scanf("%c", &ch) != EOF) {
        if(((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))) {
            s += ch;
        } else {
            if(s == "tram")
                a++;
            else if(s == "trolleybus")
                b++;
            s = "";
        }
    }

    if(a > b) {
        cout << "Tram driver";
    } else if(a < b) {
        cout << "Trolleybus driver";
    } else {
        cout << "Bus driver";
    }
}














