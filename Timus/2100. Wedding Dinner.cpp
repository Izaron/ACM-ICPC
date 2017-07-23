#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main() {
    int cnt = 2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cnt++;
        if (s.size() >= 4 && s[s.size() - 4] == '+')
            cnt++;
    }
    if (cnt == 13) cnt++;
    cout << cnt * 100 << endl;
}
