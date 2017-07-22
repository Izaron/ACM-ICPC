#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n, k;
int up, down;
set<pii> st;

pii get_red() {
    if (!st.count({ up, 1 }))
        return { up, 1 };
    return { up, 2 };
}

pii get_blue() {
    if (!st.count({ up, 2 }))
        return { up, 2 };
    return { up, 1 };
}

pii get_black() {
    if (!st.count({ down, 1 }))
        return { down, 1 };
    return { down, 2 };
}

pii get_yellow() {
    if (!st.count({ down, 2 }))
        return { down, 2 };
    return { down, 1 };
}

void upd() {
    while (st.count({ up, 1 }) && st.count({ up, 2 }))
        up++;
    while (st.count({ down, 1 }) && st.count({ down, 2 }))
        down--;
}

int main() {
    #ifndef HOME
    freopen("seats.in", "r", stdin);
    freopen("seats.out", "w", stdout);
    #endif

    cin >> n >> k;
    up = 1;
    down = n;

    vector< vector<int> > vec(5);

    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        pii pr = { x, y };
        pii a = get_red();
        pii b = get_blue();
        pii c = get_black();
        pii d = get_yellow();
        if (a == pr) vec[0].push_back(i);
        if (b == pr) vec[1].push_back(i);
        if (c == pr) vec[2].push_back(i);
        if (d == pr) vec[3].push_back(i);
        vec[4].push_back(i);
        st.insert(pr);
        upd();
    }

    for (auto it : vec) {
        cout << it.size() << " ";
        for (auto itt : it)
            cout << itt << " ";
        cout << endl;
    }
}
