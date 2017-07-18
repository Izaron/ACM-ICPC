#include <bits/stdc++.h>
using namespace std;

void extend(string & s, int len) {
    string add = "0";
    while (add.size() + s.size() < len)
        add += "0";
    s = add + s;
}

int main() {
    string a, b;
    cin >> a >> b;
    int len = max(a.size(), b.size()) + 1;
    extend(a, len);
    extend(b, len);

    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (a[len - 1 - i] != b[len - 1 - i])
            cnt = i + 1;
    }
    cout << cnt << endl;
}