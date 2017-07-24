// The solution of the problem was written by Izaron
// Date: 20:12:23   12 May 2015
// Execution time: 0.031

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define eb emplace_back
#define pb push_back
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define mem0(m) memset((m), 0, sizeof(m));
#define mem0d(m) memset((m), 0.0, sizeof(m));
#define memb(m) memset((m), false, sizeof(m));
typedef long long int ll;
typedef long double ld;



char m[1000][1000];

int xMin = 1000, xMax = -1000;
int yMin = 1000, yMax = -1000;

void setXYSudo(int x, int y, char ch) {
    x += 400;
    y += 400;

    m[x][y] = ch;
}

void setXY(int x, int y, char ch) {
    x += 400;
    y += 400;

    xMin = min(xMin, x); xMax = max(xMax, x);
    yMin = min(yMin, y); yMax = max(yMax, y);

    m[x][y] = ch;
}

int main() {
    for(int i = 0; i < 1000; i++) {
        for(int z = 0; z < 1000; z++) {
            m[i][z] = '.';
        }
    }

    for(int i = 0; i < 850; i++) {
        for(int z = 0; z < 850; z++) {
            setXYSudo(0, z - 300, '|');
            setXYSudo(i - 300, 0, '-');
        }
    }
    setXYSudo(0, 0, '+');

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        setXY(a, b, '*');
    }

    xMin = min(xMin, 400); xMax = max(xMax, 400);
    yMin = min(yMin, 400); yMax = max(yMax, 400);

    for(int z = yMin; z <= yMax; z++) {
        for(int i = xMin; i <= xMax; i++) {
            cout << m[i][yMax - z + yMin];
        }
        cout << endl;
    }
}






















