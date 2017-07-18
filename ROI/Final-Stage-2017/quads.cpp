#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n;
vector<pii> vec;
vector<char> res;

bool query(int a, int b) {
    cout << "? " << a + 1 << " " << b + 1 << endl;
    string s; cin >> s;
    return tolower(s[0]) == 'y';
}

void extend(pii & p) {
    res[p.first] = '(';
    res[p.second] = ')';

    while (vec.size() > 0) {
        pii l = vec.back();
        if (l.second == p.first - 1) {
            p.first = l.first;
            vec.pop_back();
            extend(p);
            return;
        } else {
            break;
        }
    }

    if (p.first == 0 || p.second == n - 1)
        return;
   
    if (query(p.first - 1, p.second + 1)) {
        p.first--;
        p.second++;
        extend(p);
    }
}

int main() {
    cin >> n;
    res.resize(n);
    for (int i = 0; i + 1 < n; ) {
        if (query(i, i + 1)) {
            pii p = make_pair(i, i + 1);
            i += 2;
            extend(p);
            vec.push_back(p);
        } else {
            i++;
        }
    }
    cout << "! ";
    for (int i = 0; i < n; i++)
        cout << res[i];
    cout << endl;
}
