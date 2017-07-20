#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

string sub() {
    string s;
    int k;
    cin >> s >> k;
    
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '+')
            continue;
        else {
            if (i + k - 1 >= (int)s.size())
                return "IMPOSSIBLE";
            cnt++;
            for (int z = i; z < i + k; z++)
                if (s[z] == '+')
                    s[z] = '-';
                else
                    s[z] = '+';
        }
    }

    stringstream ss;
    ss << cnt;
    string res;
    ss >> res;
    return res;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        cout << "Case #" << i + 1 << ": " << sub() << endl;
}
