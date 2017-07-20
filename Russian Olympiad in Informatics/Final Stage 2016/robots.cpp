#include <bits/stdc++.h>
using namespace std;
#define mkp make_pair
#define pb push_back
#define ins insert
#define mt make_tuple

typedef long long int ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;


const int N = 1000 + 5;
const int CNT = 1000 * 1000 + 5;

int n, m, g;
string s[N];
string slow[N];
bool hasRobot[N][N];
int used[N][N];
int usedCnt[N][N];
int cycleNum[N][N];
int toCycle[N][N];
int cycleLen[CNT];
int cycleLenBeen[CNT];
int tme = 0;
int cyclesAll = 0;
int posA[CNT];
int posB[CNT];
int ttimerr[CNT];

int findCycleNum(int a, int b, int cnt) {
    if (cycleNum[a][b] != -1) {
        return cycleNum[a][b];
    }

    if (used[a][b] == tme) {
        toCycle[a][b] = 0;
        cycleNum[a][b] = cyclesAll;
        cycleLen[cyclesAll] = cnt - usedCnt[a][b];
        cycleLenBeen[cyclesAll] = cycleLen[cyclesAll];
        cyclesAll++;
        return cyclesAll - 1;
    }

    usedCnt[a][b] = cnt;
    used[a][b] = tme;

    if (slow[a][b] == 'n') {
        int num = findCycleNum(a - 1, b, cnt + 1);
        cycleNum[a][b] = num;
        toCycle[a][b] = toCycle[a - 1][b] + 1;
        return num;
    }
    if (slow[a][b] == 's') {
        int num = findCycleNum(a + 1, b, cnt + 1);
        cycleNum[a][b] = num;
        toCycle[a][b] = toCycle[a + 1][b] + 1;
        return num;
    }
    if (slow[a][b] == 'w') {
        int num = findCycleNum(a, b - 1, cnt + 1);
        cycleNum[a][b] = num;
        toCycle[a][b] = toCycle[a][b - 1] + 1;
        return num;
    }
    if (slow[a][b] == 'e') {
        int num = findCycleNum(a, b + 1, cnt + 1);
        cycleNum[a][b] = num;
        toCycle[a][b] = toCycle[a][b + 1] + 1;
        return num;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("robots.in", "r", stdin);
    freopen("robots.out", "w", stdout);

    memset(used, 0, sizeof(used));
    memset(hasRobot, false, sizeof(hasRobot));
    memset(cycleNum, -1, sizeof(cycleNum));
    memset(toCycle, -1, sizeof(cycleNum));

    cin >> n >> m >> g;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        slow[i] = s[i];
        for (int z = 0; z < m; z++) {
            if (s[i][z] != tolower(s[i][z]))
                hasRobot[i][z] = true;
            slow[i][z] = tolower(slow[i][z]);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int z = 0; z < m; z++) {
            tme++;
            int num = findCycleNum(i, z, 1);
            if (cycleLen[num] > 0 && hasRobot[i][z]) {
                posA[ans] = i + 1;
                posB[ans] = z + 1;
                ttimerr[ans] = 10000000 - toCycle[i][z] + cycleLenBeen[num] - cycleLen[num];
                ans++;
                cycleLen[num]--;
            }
        }
    }

    cout << ans << endl;

    if (g == 1) {
        for (int i = 0; i < ans; i++) {
            printf("%d %d %d\n", posA[i], posB[i], ttimerr[i]);
        }
    }

    /*for (int i = 0; i < n; i++) {
        for (int z = 0; z < m; z++) {
            cout << toCycle[i][z];
        }
        cout << endl;
    }*/
}