#include <bits/stdc++.h>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int maxn = 100000 + 5;

struct node {
    int len;
    node * link;
    node * next[26];

    node() {
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
        len = 0;
        link = nullptr;
    }

    node(int len) {
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
        this->len = len;
        link = nullptr;
    }
};

node * root_even = new node();
node * root_odd = new node(-1);
node * last = root_even;
string s;
int cnt = 0;

int gv(char ch) {
    return ch - 'a';
}

node * findParent(int index, int x) {
    node * ans = last;
    while (true) {
        if (index - ans->len - 1 >= 0 && gv(s[index - ans->len - 1]) == x)
            return ans;
        ans = ans->link;
    }
}

node * find_link(node * nd, int index, int x) {
    node * ans = nd->link;
    while (true) {
        if (index - ans->len - 1 >= 0 && gv(s[index - ans->len - 1]) == x)
            return ans->next[x];
        ans = ans->link;
    }
}

void add(int index, int x) {
    node * parent = findParent(index, x);
    if (parent->next[x] == nullptr) {
        node * nnode = new node(parent->len + 2);
        parent->next[x] = nnode;
        if (parent == root_odd)
            nnode->link = root_even;
        else
            nnode->link = find_link(parent, index, x);
        cnt++;
    }
    last = parent->next[x];
}

int main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #endif

    root_even->link = root_odd;
    root_odd->link = root_odd;

    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        int c = gv(s[i]);
        add(i, c);
        cout << cnt << " ";
    }
}
