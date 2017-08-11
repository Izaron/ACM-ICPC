#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

string s;

vector< vector<int> > calced[2];

int dp(int v, int lst, int b) {
    if (lst > 9)
        return 0;
    if (v == (int)s.size())
        return 1;
    if (b == 0 && s[v] - '0' < lst)
        return 0;
    if (calced[b][v][lst] != -1)
        return calced[b][v][lst];

    calced[b][v][lst] = 0;
    if (dp(v, lst + 1, b) == 1)
        calced[b][v][lst] = 1;
    if (dp(v + 1, lst, (lst >= s[v] - '0' ? b : 1)) == 1)
        calced[b][v][lst] = 1;
    return calced[b][v][lst];
}

string p(int v, int lst, int b) {
    //cerr << "v = " << v << " lst = " << lst << " b = " << b << endl;

    if (v == (int)s.size())
        return "";
    if (dp(v, lst + 1, b) == 1) {
        return p(v, lst + 1, b);
    } else {
        string ss = "";
        if (lst != 0)
            ss += (char)(lst + '0');
        if (dp(v + 1, lst, (lst >= s[v] - '0' ? b : 1)) == 1)
            return ss + p(v + 1, lst, (lst >= s[v] - '0' ? b : 1));
    }
    throw 0;
}

string sub() {
    cin >> s;
    for (int i = 0; i < 2; i++) {
        calced[i].clear();
        calced[i].resize(100);
        for (int z = 0; z < 100; z++)
            calced[i][z].resize(100, -1);
    }

    return p(0, 0, 0);
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        cout << "Case #" << i + 1 << ": " << sub() << endl;
}
