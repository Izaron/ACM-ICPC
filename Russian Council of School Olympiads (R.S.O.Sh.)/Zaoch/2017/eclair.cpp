#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n;
vector<int> vec;

void resize(vector<pii> & vec, int cur, int len) {
    if (cur > len) {
        while (cur > len) {
            pii & kz = vec[vec.size() - 1];
            if (cur - kz.second >= len) {
                cur -= kz.second;
                vec.pop_back();
            } else {
                kz.second -= cur - len;
                cur = len;
            }
        }
    } else if (cur < len) {
        vec.push_back({0, len - cur});
    }
}

void upmerge(vector<pii> & vec) {
    while (vec.size() > 1) {
        if (vec[vec.size() - 1].first == vec[vec.size() - 2].first) {
            vec[vec.size() - 2].second += vec[vec.size() - 1].second;
            vec.pop_back();
        } else {
            break;
        }
    }
}

bool add(int c, vector<pii> & vec) {
    if (vec.size() == 1 && vec[0].first == c - 1)
        return false;

    pii & kz = vec[vec.size() - 1];
    if (kz.first == c - 1) {
        int len = kz.second;
        vec.pop_back();
        add(c, vec);
        vec.push_back({0, len});
    } else {
        if (kz.second == 1) {
            kz.first++;
        } else {
            kz.second--;
            vec.push_back({kz.first + 1, 1});
        }
    }

    return true;
}

void dump(int c, int i, vector<pii> & vec) {
    cerr << "alphabet size = " << c << endl;
    cerr << "position = " << i << endl;
    for (auto it : vec)
        cerr << "value = " << it.first << " len = " << it.second << endl;
    cerr << endl;
}

void print(vector<pii> & vec, int pos) {
    cerr << "pos = " << pos << " res = ";
    for (auto it : vec) {
        for (int i = 0; i < it.second; i++)
            cerr << it.first;
    }
    cerr << endl;
}

bool can(int c, bool p) {
    if (c < 1)
        return false;

    vector<pii> s;
    s.push_back({0, vec[0]});
    int cur = vec[0];   // current length

    if (p) print(s, 0);

    // for each len
    for (int i = 1; i < n; i++) {
        // resize
        resize(s, cur, vec[i]);
        upmerge(s);

        // add one
        if (vec[i] <= cur) {
            if (!add(c, s))
                return false;
        }
        upmerge(s);

        cur = vec[i];
        if (p) print(s, i);
    }
    return true;
}

int main() {
    scanf("%d", &n);
    vec.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &vec[i]);
    
    int cur = 0;
    for (int i = 20; i >= 0; i--) {
        if (!can(cur + (1 << i), false))
            cur += (1 << i);
    }

    printf("%d\n", cur + 1);
    //can(cur + 1, true);
}