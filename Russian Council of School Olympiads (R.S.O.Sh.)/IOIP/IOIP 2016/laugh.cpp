#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

#ifdef USE_CERR
#define CERR(a) cerr << "dump: " << a << endl;
#else
#define CERR(a)
#endif

int main() {
    #ifndef HOME
    #define FILE "laugh"
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
    #endif // HOME

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0, cnt = 0;
    char ch;
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            if (s[i] == 'a' || s[i] == 'h') {
                cnt = 1;
                ch = (s[i] == 'a' ? 'h' : 'a');
            }
        } else if (s[i] == ch) {
            cnt++;
            ch = (s[i] == 'a' ? 'h' : 'a');
        } else {
            ans = max(ans, cnt);
            cnt = 0;
            if (s[i] == 'a' || s[i] == 'h') {
                cnt = 1;
                ch = (s[i] == 'a' ? 'h' : 'a');
            }
        }
    }
    ans = max(ans, cnt);

    cout << ans;
}