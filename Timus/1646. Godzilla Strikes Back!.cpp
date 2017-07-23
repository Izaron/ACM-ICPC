#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <vector>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int, int> tt;

const int N = 100000 + 5;
const int MOD = 1000000000 + 7;


string dna;
int n;
vector<pair<string, string>> vec;
vector<int> cost;

int main() {
    cin >> dna;
    n = (int)dna.size();

    for (int i = 0; i < 2; i++) {
        string s;
        cin >> s;

        int curr = 0;
        for (int z = 0; z < s.size(); z++) {
            if (z + n > s.size())
                break;
            if (s.substr(z, n) == dna)
                curr++;
        }

        pair<string, string> pr = mkp(s, s);
        if (pr.first.size() >= n)
            pr.first = pr.first.substr(0, n - 1);
        if (pr.second.size() >= n)
            pr.second = pr.second.substr(pr.second.size() - n + 1);

        vec.pb(pr);
        cost.pb(curr);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        string s = vec[a].second + vec[b].first;
        int curr = 0;
        for (int z = 0; z < s.size(); z++) {
            if (z + n > s.size())
                break;
            if (s.substr(z, n) == dna)
                curr++;
        }

        pair<string, string> pr = mkp(vec[a].first, vec[b].second);
        pr.first += vec[b].first;
        if (pr.first.size() >= n)
            pr.first = pr.first.substr(0, n - 1);
        pr.second = vec[a].second + pr.second;
        if (pr.second.size() >= n)
            pr.second = pr.second.substr(pr.second.size() - n + 1);

        curr %= MOD;
        curr += cost[a];
        curr %= MOD;
        curr += cost[b];
        curr %= MOD;

        vec.pb(pr);
        cost.pb(curr);
    }

    cout << cost[cost.size() - 1];
}
