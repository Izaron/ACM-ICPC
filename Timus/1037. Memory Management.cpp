#include <bits/stdc++.h>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define gv(v, i) get<i>(v)
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int maxn = 100000 + 5;


const int n = 30000, t = 600;

set<int> free_blocks;
set<pii> q;
int using_time[n + 5];

void clear_old(int time) {
    while (!q.empty()) {
        pii pr = *q.begin();
        if (time - pr.first >= t) {
            q.erase(pr);
            free_blocks.insert(pr.second);
        } else {
            break;
        }
    }
}

int allocate_block(int time) {
    int val = *free_blocks.begin();
    free_blocks.erase(val);
    q.insert(mkp(time, val));
    using_time[val] = time;
    return val;
}

char request(int time, int num) {
    if (free_blocks.count(num))
        return '-';
    pii pr = mkp(using_time[num], num);
    q.erase(pr);
    using_time[num] = time;
    pr = mkp(using_time[num], num);
    q.insert(pr);
    return '+';
}

int main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #endif

    memset(using_time, 0, sizeof(using_time));

    for (int i = 1; i <= n; i++)
        free_blocks.insert(i);

    int time;
    string com;
    while (cin >> time) {
        clear_old(time);
        cin >> com;
        if (com == "+") {
            cout << allocate_block(time) << endl;
        } else {
            int num;
            cin >> num;
            cout << request(time, num) << endl;
        }
    }
}
