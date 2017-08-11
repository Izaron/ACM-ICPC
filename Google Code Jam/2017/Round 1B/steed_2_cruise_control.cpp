#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;

bool can(int n, vector<ld> & init, vector<ld> & speed, ld d, ld may) {
    ld way, how;
    for (int i = 0; i < n; i++) {
        if (speed[i] >= may)
            continue;
        way = init[i];
        how = way / (may - speed[i]);
        if (how * may >= d)
            continue;
        return false;
    }
    return true;
}

void sub() {
    ld d;
    int n;
    cin >> d >> n;

    vector<ld> init(n);
    vector<ld> speed(n);
    for (int i = 0; i < n; i++) {
        cin >> init[i] >> speed[i];
    }

    ld a = 0, b = LLONG_MAX, eps = 0.000001;
    while (b - a > eps) {
        ld mid = (a + b) / 2;
        if (can(n, init, speed, d, mid))
            a = mid;
        else
            b = mid;
    }
    cout << fixed << setprecision(12) << a;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": ";
        sub();
        cout << endl;
    }
}
