#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef vector<int> vint;

struct solver {
    void rm(map<char, int>& mp, string s) {
        for (auto it : s)
            mp[it]--;
    }

    void solve() {
        string s;
        cin >> s;
        map<char, int> mp;
        for (auto it : s)
            mp[it]++;
        vector<int> vec;
        while (true) {
            if (mp['Z']) {
                rm(mp, "ZERO");
                vec.push_back(0);
            } else if (mp['X']) {
                rm(mp, "SIX");
                vec.push_back(6);
            } else if (mp['U']) {
                rm(mp, "FOUR");
                vec.push_back(4);
            } else if (mp['G']) {
                rm(mp, "EIGHT");
                vec.push_back(8);
            } else if (mp['S']) {
                rm(mp, "SEVEN");
                vec.push_back(7);
            } else if (mp['W']) {
                rm(mp, "TWO");
                vec.push_back(2);
            } else if (mp['H']) {
                rm(mp, "THREE");
                vec.push_back(3);
            } else if (mp['O']) {
                rm(mp, "ONE");
                vec.push_back(1);
            } else if (mp['F']) {
                rm(mp, "FIVE");
                vec.push_back(5);
            } else if (mp['N']) {
                rm(mp, "NINE");
                vec.push_back(9);
            } else {
                break;
            }
        }
        sort(vec.begin(), vec.end());
        for (auto it : vec)
            cout << it;
        cout << endl;
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
