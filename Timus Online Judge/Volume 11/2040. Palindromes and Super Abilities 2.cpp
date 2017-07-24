// The solution of the problem was written by Izaron
// Date: 22:28:57   18 Aug 2016
// Execution time: 0.265

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <stdio.h>
#include <random>
#include <string.h>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef long double ld;

const int maxn = 100000 + 5;

struct node {
    int len;
    int link;
    int next[2];

    node() {
        for (int i = 0; i < 2; i++)
            next[i] = -1;
        len = 0;
        link = -1;
    }

    node(int len) {
        for (int i = 0; i < 2; i++)
            next[i] = -1;
        this->len = len;
        link = -1;
    }
};


vector<node> vec;
int sz = 2;

int root_even = 1;
int root_odd = 0;
int last = root_even;
char s[5000005];
char ans[5000005];
int cnt;

int gv(char ch) {
    return ch - 'a';
}

int findParent(int index, int x) {
    int ans = last;
    while (true) {
        if (index - vec[ans].len - 1 >= 0 && gv(s[index - vec[ans].len - 1]) == x)
            return ans;
        ans = vec[ans].link;
    }
}

int find_link(int nd, int index, int x) {
    int ans = vec[nd].link;
    while (true) {
        if (index - vec[ans].len - 1 >= 0 && gv(s[index - vec[ans].len - 1]) == x)
            return vec[ans].next[x];
        ans = vec[ans].link;
    }
}

int add(int index, int x) {
    cnt = 0;
    int parent = findParent(index, x);
    if (vec[parent].next[x] == -1) {
        int nnode = sz++;
        vec[nnode].len = vec[parent].len + 2;
        vec[parent].next[x] = nnode;
        if (parent == root_odd)
            vec[nnode].link = root_even;
        else
            vec[nnode].link = find_link(parent, index, x);
        cnt++;
    }
    last = vec[parent].next[x];
    return cnt;
}

void gen() {
    int n = 5000000;
    srand(13);
    freopen("input.txt", "w", stdout);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            printf("a");
        else
            printf("b");
    }
}

int main() {
    //gen();
    //return 0;

    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vec.resize(5000005);

    vec[root_odd].len = -1;
    vec[root_odd].link = root_odd;
    vec[root_even].link = root_odd;

    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int c = gv(s[i]);
        ans[i] = add(i, c) + '0';
    }
    puts(ans);
}
