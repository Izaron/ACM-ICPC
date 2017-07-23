#include "messy.h"
#include <bits/stdc++.h>
using namespace std;

int maxn;

void put(int l, int r) {
    if (l == r)
        return;

    string s = "";
    for (int i = 0; i < maxn; i++)
        s += '0';
    for (int i = l; i <= r; i++)
        s[i] = '1';

    for (int i = l; i <= (l + r) / 2; i++) {
        s[i] = '0';
        add_element(s);
        cerr << s << endl;
        s[i] = '1';
    }

    put(l, (l + r) / 2);
    put((l + r) / 2 + 1, r);
}

vector<int> restore(vector<int> vec, int l, int r) {
    if (l == r)
        return vec;

    string s = "";
    for (int i = 0; i < maxn; i++)
        s += '0';
    for (auto it : vec)
        s[it] = '1';

    vector<int> a, b;
    for (auto it : vec) {
        s[it] = '0';
        if (check_element(s)) {
            a.push_back(it);
        } else {
            b.push_back(it);
        }
        s[it] = '1';
    }

    vector<int> _a = restore(a, l, (l + r) / 2);
    //for (int i = 0; i < _a.size(); i++)
    //    a[_a[i]] = i;

    vector<int> _b = restore(b, (l + r) / 2 + 1, r);
    //for (int i = 0; i < _b.size(); i++)
    //    b[_b[i]] = i;

    vector<int> ans;
    for (auto it : _a)
        ans.push_back(it);
    for (auto it : _b)
        ans.push_back(it);
    return ans;
}

vector<int> restore_permutation(int n, int w, int r) {
    maxn = n;
    put(0, n - 1);
    compile_set();

    vector<int> ans;
    for (int i = 0; i < n; i++)
        ans.push_back(i);
    ans = restore(ans, 0, n - 1);
    vector<int> tmp(n);
    for (int i = 0; i < n; i++)
        tmp[ans[i]] = i;
    return tmp;
}

/*
4 256 256
0 1 2 3

4 256 256
2 1 3 0

8 256 256
0 1 2 3 4 5 6 7

8 256 256
3 2 5 0 4 7 6 1
*/
