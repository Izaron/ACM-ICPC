#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <vector>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int, int> tt;

const int N = 2000 + 5;


string s[12];

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        for (int z = 0; z < 12; z++)
            cin >> s[z];
        int a = atoi(s[6].c_str());
        int b = atoi(s[10].c_str());
        int k1 = 1000, k2 = 0;
        if (s[3] == "home") {
            for (int glA = 0; glA <= 30; glA++) {
                for (int glB = 0; glB <= 30; glB++) {
                    a += glA;
                    b += glB;

                    if (a > b) {
                        k1 = min(k1, glA);
                    } else if (a == b && glA >= (b - glB)) {
                        k1 = min(k1, glA);
                    } else {
                        k2 = max(k2, glA);
                    }

                    if (a == b && glA == (b - glB))
                        k2 = max(k2, glA);

                    a -= glA;
                    b -= glB;
                }
            }
        } else {
            for (int glA = 0; glA <= 30; glA++) {
                for (int glB = 0; glB <= 30; glB++) {
                    a += glA;
                    b += glB;

                    if (a > b) {
                        k1 = min(k1, glA);
                    } else if (a == b && (a - glA) >= glB) {
                        k1 = min(k1, glA);
                    } else {
                        k2 = max(k2, glA);
                    }

                    if (a == b && (a - glA) == glB)
                        k2 = max(k2, glA);

                    a -= glA;
                    b -= glB;
                }
            }
        }

        cout << k1 << " " << k2 << endl;
    }
}
