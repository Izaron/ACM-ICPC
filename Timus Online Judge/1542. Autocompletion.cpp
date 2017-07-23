// The solution of the problem was written by Izaron
// Date: 19:54:19   14 May 2016
// Execution time: 0.28

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

const int N = 100000 + 5;

class bor {
public:
    vector<pair<int, int>> st;
    bor* nxt[26];
    bool used;

    bor() {
        used = false;
        //st = set<pair<int, int>>();
        for (int i = 0; i < 26; i++)
            nxt[i] = nullptr;
    }
};

int n, m;
int cn;
bor* br = new bor();
string s;
pair<string, int> stt[N];
string nado[N];

void ins(string s, int cost, int num) {
    bor* tmp = br;
    for (int i = 0; i < s.size(); i++) {
        int ch = s[i] - 'a';
        if (tmp->nxt[ch] == nullptr)
            return;
        tmp = tmp->nxt[ch];
        if (tmp->used) {
            tmp->st.pb(mkp(-cost, num));
            sort(tmp->st.begin(), tmp->st.end());
            if (tmp->st.size() > 12) {
                tmp->st.erase(tmp->st.begin() + tmp->st.size() - 1);
            }
        }
    }
}

void use(string s) {
    bor* tmp = br;
    for (int i = 0; i < s.size(); i++) {
        int ch = s[i] - 'a';
        if (tmp->nxt[ch] == nullptr)
            tmp->nxt[ch] = new bor();
        tmp = tmp->nxt[ch];
    }
    tmp->used = true;
}

void print() {
    bor* tmp = br;
    for (int i = 0; i < s.size(); i++) {
        int ch = s[i] - 'a';
        if (tmp->nxt[ch] == nullptr) {
            cn = 0;
            return;
        }
        tmp = tmp->nxt[ch];
    }
    int cnt = 0;
    for (auto it : tmp->st) {
        cnt++;
        if (cnt > 10) {
            cnt--;
            break;
        }
    }
    cn = cnt;

    int tr = 0;
    for (auto it : tmp->st) {
        tr++;
        cout << stt[it.second].first;
        if (tr != cnt)
            cout << "\n";
        if (tr == cnt)
            break;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int cost;
        cin >> s >> cost;
        stt[i] = mkp(s, cost);
    }
    sort(stt, stt + n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> nado[i];
        use(nado[i]);
    }

    for (int i = 0; i < n; i++) {
        string s = stt[i].first;
        int cost = stt[i].second;
        ins(s, cost, i);
    }

    for (int i = 0; i < m; i++) {
        s = nado[i];
        print();
        if (i != m - 1) {
            if (cn != 0)
                cout << "\n";
            cout << "\n";
        }
    }
}