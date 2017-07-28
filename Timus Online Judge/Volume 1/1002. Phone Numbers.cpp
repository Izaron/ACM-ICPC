// The solution of the problem was written by Izaron
// Date: 15:55:34   25 Jul 2017
// Execution time: 0.109

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pii;

struct node {
    bool leaf;
    string leaf_str;
    vector<node*> next;

    node() {
        leaf = false;
        next.resize(10, nullptr);
    }
};

struct solver {

    node* nd;

    int gnum(char ch) {
        if (ch >= 'i' && ch <= 'j') return 1;
        if (ch >= 'a' && ch <= 'c') return 2;
        if (ch >= 'd' && ch <= 'f') return 3;
        if (ch >= 'g' && ch <= 'h') return 4;
        if (ch >= 'k' && ch <= 'l') return 5;
        if (ch >= 'm' && ch <= 'n') return 6;
        if (ch >= 'p' && ch <= 's') return 7;
        if (ch >= 't' && ch <= 'v') return 8;
        if (ch >= 'w' && ch <= 'y') return 9;
        if (ch >= 'o' && ch <= 'z') return 0;
    }

    void insert(string s) {
        node* n = nd;
        for (int i = 0; i < s.size(); i++) {
            int ind = gnum(s[i]);
            if (n->next[ind] == nullptr)
                n->next[ind] = new node();
            n = n->next[ind];
        }
        if (!n->leaf) {
            n->leaf = true;
            n->leaf_str = s;
        }
    }

    string tel;
    int m;
    vector<int> ans;

    int dp(int v) {
        if (v == m)
            return 0;
        if (ans[v] != -1)
            return ans[v];
        node* n = nd;
        int cur = INT_MAX / 2;
        for (int i = v; i < m; i++) {
            int ind = tel[i] - '0';
            if (n->next[ind] == nullptr)
                break;
            n = n->next[ind];
            if (n->leaf) {
                cur = min(cur, 1 + dp(i + 1));
            }
        }
        ans[v] = cur;
        return cur;
    }

    void vosst(int v) {
        if (v == m)
            return;
        node* n = nd;
        for (int i = v; i < m; i++) {
            int ind = tel[i] - '0';
            if (n->next[ind] == nullptr)
                break;
            n = n->next[ind];
            if (n->leaf) {
                if (ans[v] == 1 + dp(i + 1)) {
                    cout << n->leaf_str << " ";
                    vosst(i + 1);
                    return;
                }
            }
        }
    }

    bool solve() {
        nd = new node();
        cin >> tel;
        if (tel[0] == '-')
            return false;

        m = tel.size();
        ans.resize(m, -1);

        int cnt;
        cin >> cnt;
        for (int i = 0; i < cnt; i++) {
            string s;
            cin >> s;
            insert(s);
        }

        int res = dp(0);
        if (res >= INT_MAX / 2) {
            cout << "No solution." << endl;
        } else {
            vosst(0);
            cout << endl;
        }

        return true;
    }
};

int main() {
    while (true) {
        solver s;
        if (!s.solve()) break;
    }
}
