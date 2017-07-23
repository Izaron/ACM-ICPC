#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

const int N = 3000 + 5;


string good = "=+-*/0123456789)(";

bool bad(char ch) {
    return good.find(ch) == -1;
}

int main() {
    //freopen("/home/izaron/ClionProjects/untitled/input.txt", "r", stdin);
    //freopen("/home/izaron/ClionProjects/untitled/output.txt", "w", stdout);

    char str[30010];
    int strsize = 0;
    while (fgets(str + strsize, 20000, stdin)) strsize = strlen(str) - 1;
    ++strsize;

    bool can = true;
    string ans = "";
    for (int i = 0; i < strsize; i++) {
        if (can) {
            if (i + 1 < strsize && str[i] == '(' && str[i + 1] == '*') {
                can = false;
                i++;
            } else {
                ans += str[i];
            }
        } else {
            if (i + 1 < strsize && str[i] == '*' && str[i + 1] == ')') {
                can = true;
                i++;
            }
        }
    }
    if (!can) {
        cout << "NO";
        return 0;
    }

    int opened = 0;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == '(') {
            opened++;
        } else if (ans[i] == ')') {
            opened--;
            if (opened < 0) {
                cout << "NO";
                return 0;
            }
        } else {
            if (opened > 0 && bad(ans[i])) {
                cout << "NO";
                return 0;
            }
        }
    }
    if (opened != 0) {
        cout << "NO";
        return 0;
    }

    cout << "YES";
}