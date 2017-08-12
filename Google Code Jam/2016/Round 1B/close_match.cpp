#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vint;

struct solver {
    void solve() {
        string sa, sb;
        cin >> sa >> sb;

        vector<ull> vec(19);
        vec[0] = 1;
        for (int i = 1; i < 19; i++)
            vec[i] = vec[i - 1] * 10;

        ull a = 0, b = 0;
        for (int i = 0; i < sa.size(); i++) {
            if (sa[i] != '?')
                a += (ull)(sa[i] - '0') * vec[sa.size() - i - 1];
        }
        for (int i = 0; i < sb.size(); i++) {
            if (sb[i] != '?')
                b += (ull)(sb[i] - '0') * vec[sb.size() - i - 1];
        }
        for (int i = 0; i < sa.size(); i++) {
            ull mn = vec[sa.size() - 1 - i];
            if (sa[i] == '?' && sb[i] == '?') {
                int inda = 0;
                int indb = 0;
                ull res = ULLONG_MAX;
                for (int z = 0; z < 10; z++) {
                    for (int q = 0; q < 10; q++) {
                        ull tmpa = a + z * mn;
                        ull tmpb = b + q * mn;
                        ull ab;
                        if (tmpa < tmpb)
                            ab = tmpb - tmpa;
                        else
                            ab = tmpa - tmpb;
                        if (ab < res) {
                            res = ab;
                            inda = z;
                            indb = q;
                        }
                    }
                }
                a += inda * mn;
                b += indb * mn;
            } else if (sa[i] == '?') {
                int ind = 0;
                ull res = ULLONG_MAX;
                for (int z = 0; z < 10; z++) {
                    ull tmp = a + z * mn;
                    ull ab;
                    if (tmp < b)
                        ab = b - tmp;
                    else
                        ab = tmp - b;
                    if (ab < res) {
                        res = ab;
                        ind = z;
                    }
                }
                a += ind * mn;
            } else if (sb[i] == '?') {
                int ind = 0;
                ull res = ULLONG_MAX;
                for (int z = 0; z < 10; z++) {
                    ull tmp = b + z * mn;
                    ull ab;
                    if (tmp < a)
                        ab = a - tmp;
                    else
                        ab = tmp - a;
                    if (ab < res) {
                        res = ab;
                        ind = z;
                    }
                }
                b += ind * mn;
            }
        }

        int st = sa.size();
        sa = to_string(a);
        while (sa.size() < st) sa = "0" + sa;
        sb = to_string(b);
        while (sb.size() < st) sb = "0" + sb;

        cout << sa << " " << sb << endl;
    }
};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": ";
        solver s;
        s.solve();
        cerr << "Case #" << i + 1 << " is done" << endl;
    }
}
