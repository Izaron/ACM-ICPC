#include <bits/stdc++.h>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;

const int N = 300000 + 5;

int borCnt = 0;

class bor {
public:
    bor* to0;
    bor* to1;
    ll c;

    bor() {
        to0 = nullptr;
        to1 = nullptr;
        c = 1000000000000000000;
    }
};
bor* mbor = new bor();

ll ans[N];

int m, n, L;
string masa;

ll dfs(int v) {
    if (v == m)
        return 0LL;

    if (ans[v] != -1)
        return ans[v];

    bor* tmp = mbor;
    ll curr = 1000000000000000000;
    for (int i = v; i < m; i++) {
        if (masa[i] == '0') {
            if (tmp->to0 == nullptr) {
                break;
            } else {
                tmp = tmp->to0;
                if (tmp->c >= 1000000000000000000)
                    continue;
                curr = min(curr, tmp->c + dfs(i + 1));
            }
        } else {
            if (tmp->to1 == nullptr) {
                break;
            } else {
                tmp = tmp->to1;
                curr = min(curr, tmp->c + dfs(i + 1));
            }
        }
    }

    ans[v] = curr;
    return curr;
}

void insertBor() {
    ll nc;
    string s;
    cin >> nc >> s;

    bor* tmp = mbor;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (tmp->to0 == nullptr)
                tmp->to0 = new bor();
            tmp = tmp->to0;
        } else {
            if (tmp->to1 == nullptr)
                tmp->to1 = new bor();
            tmp = tmp->to1;
        }
        tmp->c = min(tmp->c, nc);
    }

    for (int i = 0; i < s.size(); i++) {
        tmp = mbor;
        for (int z = i; z < s.size(); z++) {
            if (s[z] == '0') {
                if (tmp->to0 == nullptr)
                    tmp->to0 = new bor();
                tmp = tmp->to0;
            } else {
                if (tmp->to1 == nullptr)
                    tmp->to1 = new bor();
                tmp = tmp->to1;
            }
        }
        tmp->c = min(tmp->c, nc);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("typing.in", "r", stdin);
    freopen("typing.out", "w", stdout);

    memset(ans, -1, sizeof(ans));

    cin >> m >> n >> L;
    cin >> masa;

    for (int i = 0; i < n; i++)
        insertBor();

    ll kek =  dfs(0);
    if (kek >= 1000000000000000000)
        kek = -1;
    cout << kek;
}