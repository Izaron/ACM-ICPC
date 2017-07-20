#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;

const int maxn = (36927037 + 2000000) * 3;

int fir, n;
int as, bs, cs;
int used[3][maxn];
bool val[3][maxn];
int glob;

bool us(int f, int a, int b, int c) {
    return (used[f][(a * (bs * cs + 2000)) + (b * (cs + 2000)) + c] == glob);
}

bool gv(int f, int a, int b, int c) {
    return (val[f][(a * (bs * cs + 2000)) + (b * (cs + 2000)) + c]);
}

void sv(int f, int a, int b, int c, bool v) {
    //cerr << "sv " << f << " (" << a << "," << b << "," << c << ") " << v << endl;
    val[f][(a * (bs * cs + 2000)) + (b * (cs + 2000)) + c] = v;
    used[f][(a * (bs * cs + 2000)) + (b * (cs + 2000)) + c] = glob;
}

bool dp(int lst, int a, int b, int c) {
    if (a + b + c == 0)
        return lst != fir;
    if (us(lst, a, b, c))
        return gv(lst, a, b, c);
    bool k = false;

    if (!k && lst != 0 && a > 0)
        if (dp(0, a - 1, b, c))
            k = true;

            if (!k && lst != 1 && b > 0)
                if (dp(1, a, b - 1, c))
                    k = true;

                    if (!k && lst != 2 && c > 0)
                        if (dp(2, a, b, c - 1))
                            k = true;

    sv(lst, a, b, c, k);
    return k;
}

void vosst(int lst, int a, int b, int c) {
    if (a + b + c == 0)
        return;

    //cerr << "  RES " << a << " " << b << " " << c << endl;

    if (lst != 0 && a > 0)
        if (dp(0, a - 1, b, c)) {
            cout << "R";
            vosst(0, a - 1, b, c);
            return;
        }

        if (lst != 1 && b > 0)
            if (dp(1, a, b - 1, c)) {
                cout << "Y";
                vosst(1, a, b - 1, c);
                return;
            }

            if (lst != 2 && c > 0)
                if (dp(2, a, b, c - 1)) {
                    cout << "B";
                    vosst(2, a, b, c - 1);
                    return;
                }
}

void sub() {
    glob++;
    //cerr << "Wait..." << glob << endl;
    int tmp;
    cin >> n >> as >> tmp >> bs >> tmp >> cs >> tmp;
    if (as > 0) {
        as--;
        fir = 0;
    } else if (bs > 0) {
        bs--;
        fir = 1;
    } else {
        cs--;
        fir = 2;
    }
    if (!dp(fir, as, bs, cs)) {
        cout << "IMPOSSIBLE";
    } else {
        if (fir == 0)
            cout << "R";
        else if (fir == 1)
            cout << "Y";
        else
            cout << "B";
        vosst(fir, as, bs, cs);
    }
}

int main() {
    memset(used, 0, sizeof(used));
    glob = 0;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": ";
        sub();
        cout << endl;
    }
}
