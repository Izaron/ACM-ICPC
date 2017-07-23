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

const int N = 30000 + 5;


int main() {
    int s, n;
    scanf("%d%d", &s, &n);
    int ms[N];
    int sum = 0, maxi = 0;
    for (int i = 0; i < s; i++) {
        scanf("%d", &ms[i]);
        ms[i]--;
        sum += ms[i];
        sum = max(sum, 0);
        maxi = max(maxi, sum);
    }
    if (maxi > n)
        cout << "NO";
    else
        cout << "YES";
}