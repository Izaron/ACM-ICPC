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





string days[] = { "monday", "tuesday", "wednesday",
        "thursday", "friday", "saturday", "sunday" };

string mons[] = { "january", "february", "march", "april", "may", "june",
    "july", "august", "september", "october", "november", "december" };

int ans[20][20][20];  // day / month / first-last

int getDay(string s) {
    for(int i = 0; i < 100; i++)
        if(s == days[i])
            return i;
    return -1;  // kek
}

int getMon(string s) {
    for(int i = 0; i < 100; i++)
        if(s == mons[i])
            return i;
    return -1;  // kek
}

int main() {
    freopen("holidays.in", "r", stdin);
    freopen("holidays.out", "w", stdout);

    int n;
    cin >> n;

    int mon[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    string s;
    cin >> s;
    int day = 1;
    int name = getDay(s);

    cin >> s;
    if(s == "yes")
        mon[1]++;

    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < 20; i++)
    for(int z = 0; z < 20; z++)
        ans[i][z][0] = 10000;

    int cmon = 0;
    for(int i = 0; i < 1000; i++) {
        ans[name][cmon][0] = min(ans[name][cmon][0], day);
        ans[name][cmon][1] = max(ans[name][cmon][1], day);
        name++;
        if(name == 7) name = 0;
        day++;
        if(day > mon[cmon]) {
            day = 1;
            cmon++;
            if(cmon == 12)
                break;
        }
    }

    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> s;
        if(s == "first")
            a = 0;
        else
            a = 1;
        cin >> s;
        b = getDay(s);
        cin >> s;
        cin >> s;
        c = getMon(s);
        cout << ans[b][c][a] << endl;
    }
}



