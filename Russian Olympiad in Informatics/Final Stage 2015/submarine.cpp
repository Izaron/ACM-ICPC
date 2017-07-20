#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define mkp make_pair
#define pb push_back
using namespace std;
 
 
const int N = 2000 + 5;
 
int ms[N][N];
int ukz[26];
int w, h;
 
int upSum[N][N];
int downSum[N][N];
int leftSum[N][N];
int rightSum[N][N];
 
int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> ukz[i];
    cin >> w >> h;
 
    for (int i = 0; i < w; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < h; j++) {
            ms[i][j] = ukz[s[j] - 'a'];
        }
    }
 
    // UP
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            upSum[i][j] = ms[i][j];
            if (i > 0)
                upSum[i][j] = max(upSum[i][j], upSum[i][j] + upSum[i - 1][j]);
            //if (upSum[i][j] > 0) cout << "  ";
            //else if (upSum[i][j] > -10) cout << " ";
            //cout << upSum[i][j] << " ";
        }
        //cout << endl;
    }
    //return 0;
 
    // DOWN
    for (int i = w - 1; i >= 0; i--) {
        for (int j = 0; j < h; j++) {
            downSum[i][j] = ms[i][j];
            if (i + 1 < w)
                downSum[i][j] = max(downSum[i][j], downSum[i][j] + downSum[i + 1][j]);
        }
    }
 
    // LEFT
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            leftSum[i][j] = ms[i][j];
            if (j > 0)
                leftSum[i][j] = max(leftSum[i][j], leftSum[i][j] + leftSum[i][j - 1]);
        }
    }
 
    // RIGHT
    for (int i = 0; i < w; i++) {
        for (int j = h - 1; j >= 0; j--) {
            rightSum[i][j] = ms[i][j];
            if (j + 1 < h)
                rightSum[i][j] = max(rightSum[i][j], rightSum[i][j] + rightSum[i][j + 1]);
        }
    }
 
    // CALC CALC CALC
    int ans = -228000000;
    for (int i = 0; i < w; i++) {
            set<pii> st;
            int ssum = 0;
            for (int z = 0; z < h; z++) {
                ssum += ms[i][z];
                int kz = ssum + upSum[i][z] + downSum[i][z] + rightSum[i][z] - 3 * ms[i][z];
                st.insert(mkp(kz, z));
            }
 
            ssum = 0;
            for (int z = 0; z < h - 1; z++) {
                // erase (kz, z)
                ssum += ms[i][z];
                int kz = ssum + upSum[i][z] + downSum[i][z] + rightSum[i][z] - 3 * ms[i][z];
                st.erase(mkp(kz, z));
 
                pii p = *(st.rbegin());
                int pluss = p.first - ssum;
                pluss += upSum[i][z] + leftSum[i][z] - ms[i][z];
                ans = max(ans, pluss);
            }
    }
 
    cout << ans;
}