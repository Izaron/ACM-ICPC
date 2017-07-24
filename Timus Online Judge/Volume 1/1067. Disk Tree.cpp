// The solution of the problem was written by Izaron
// Date: 23:46:47   17 May 2016
// Execution time: 0.062

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

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
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;

const int N = 10000 + 5;


struct bor {
    string name;
    map<string, bor*> next;
    bor() {
        name = "";
    }
};

bor* br = new bor();

int n;

void add() {
    string s;
    cin >> s;
    vector<string> vec;
    string curr = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '\\') {
            if (curr != "")
                vec.pb(curr);
            curr = "";
        } else {
            curr += s[i];
        }
    }
    if (curr != "")
        vec.pb(curr);

    bor* tmp = br;
    for (int i = 0; i < vec.size(); i++) {
        if (!tmp->next.count(vec[i])) {
            tmp->next[vec[i]] = new bor();
            tmp->next[vec[i]]->name = vec[i];
        }
        tmp = tmp->next[vec[i]];
    }
}

void print(bor* tmp, int spaces) {
    if (spaces != -1) {
        for (int i = 0; i < spaces; i++)
            cout << " ";
        cout << tmp->name << endl;
    }
    for (auto it : tmp->next) {
        print(it.second, spaces + 1);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        add();
    print(br, -1);
}