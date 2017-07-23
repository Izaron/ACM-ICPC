// The solution of the problem was written by Izaron
// Date: 23:04:52   15 Apr 2015
// Execution time: 1.703

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#define TRUE FALSE
//  _           _                                          _              _               _          _                _                    ___
// | |         | |                                        | |            (_)             | |        | |              | |                  |__ \
// | |     ___ | |     __ _ _ __ ___   _   _  ___  _   _  | |_ _ __ _   _ _ _ __   __ _  | |_ ___   | |__   __ _  ___| | __  _ __ ___   ___  ) |
// | |    / _ \| |    / _` | '__/ _ \ | | | |/ _ \| | | | | __| '__| | | | | '_ \ / _` | | __/ _ \  | '_ \ / _` |/ __| |/ / | '_ ` _ \ / _ \/ /
// | |___| (_) | |_  | (_| | | |  __/ | |_| | (_) | |_| | | |_| |  | |_| | | | | | (_| | | || (_) | | | | | (_| | (__|   <  | | | | | |  __|_|
// \_____/\___/|_( )  \__,_|_|  \___|  \__, |\___/ \__,_|  \__|_|   \__, |_|_| |_|\__, |  \__\___/  |_| |_|\__,_|\___|_|\_\ |_| |_| |_|\___(_)
//               |/                     __/ |                        __/ |         __/ |
//

#include <string>
#include <sstream>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include <cmath>
#include <math.h>
#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

#define pp /*system("pause")*/
#define ct double ttme = clock()
#define p_ct cout << (clock() - ttme) / CLOCKS_PER_SEC << endl
#define all(c) (c).begin(),(c).end()
#define fft ifstream fin("input.txt"); ofstream fout("output.txt")
#define fft_c FILE *fin, *fout
#define fft_c_open fin = fopen("input.txt","r"); fout = fopen("output.txt","w")
#define fft_c_cl fclose(fin); fclose(fout)
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define mkp(a,b) make_pair((a),(b))
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pss pair<string, string>
#define M_PI 3.14159265358979323846
#define mem0(m) memset((m), 0, sizeof(m));
#define memb(m) memset((m), false, sizeof(m));
#define memi(m) memset((m), 0, sizeof(m));
#define rep(i,n) for(i = 0; i < (int)(n); i++)
#define repi(a, n) for(int i = a; i < (int)(n); i++)
#define repp(i, a, n) for(int (i) = a; (i) < (int)(n); (i)++)
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
ll gcd(ll a, ll b)
{
    ll c;
    while(a) {
        c = a;
        a = b % a;
        b = c;
    }

    return b;
}
const int INF = 1e8;
const int DEL = 687134561;
const long long MODULO = 1e9 + 7;
const int MAX = 1e7;



int main() {
    int n;
    scanf("%d", &n);

    set<pair<ll, string>> cities;
    map<string, ll> moneys;
    map<string, ll> bankirs;
    map<string, string> bankirsCity;

    for(int i = 0; i < n; i++) {
        string name, city;
        ll money;
        cin >> name >> city >> money;
        bankirs[name] = money;
        bankirsCity[name] = city;
        moneys[city] += money;
    }

    for(auto it = moneys.begin(); it != moneys.end(); it++) {
        cities.insert(mkp((*it).second, (*it).first));
    }

    vector< pair<int, pair<string, string> > > v;
    int m, q;
    cin >> m >> q;

    for(int i = 0; i < q; i++) {
        int day;
        string name, city;
        cin >> day >> name >> city;
        v.push_back(mkp(day, mkp(name, city)));
    }

    sort(all(v));

    map<string, int> ans;

    int curr = 0;
    for(int i = 0; i <= m - 1; i++) {
        while(curr < v.size() && v[curr].first == i) {
            string bankir, oldCity, newCity;
            ll sum;
            bankir = v[curr].second.first;
            oldCity = bankirsCity[bankir];
            newCity = v[curr].second.second;
            sum = bankirs[bankir];

            if(cities.count(mkp(moneys[oldCity], oldCity)))
                cities.erase(mkp(moneys[oldCity], oldCity));
            if(cities.count(mkp(moneys[newCity], newCity)))
                cities.erase(mkp(moneys[newCity], newCity));
            bankirsCity[bankir] = newCity;
            moneys[oldCity] -= sum;
            moneys[newCity] += sum;
            cities.insert(mkp(moneys[oldCity], oldCity));
            cities.insert(mkp(moneys[newCity], newCity));

            curr++;
        }

        if(cities.size() > 1) {
            pair<ll, string> a = *cities.rbegin();
            cities.erase(a);
            pair<ll, string> b = *cities.rbegin();
            if(a.first > b.first)
                ans[a.second]++;
            cities.insert(a);
        } else {
            ans[(*cities.rbegin()).second]++;
        }
    }

    for(auto it = ans.begin(); it != ans.end(); it++) {
        if((*it).second == 0) continue;
        cout << (*it).first << " " << (*it).second << endl;
    }
}
















