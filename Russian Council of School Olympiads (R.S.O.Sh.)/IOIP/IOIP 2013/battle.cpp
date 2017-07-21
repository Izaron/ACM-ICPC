#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define pss pair<int,int>
#define pdd pair<double,double>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define ff first
#define ss second
typedef long long int ll;
typedef long double ld;





const int N = 3 * 100000 + 5;


int main() {
    #ifdef ONLINE_JUDGE
        freopen("battle.in", "r", stdin);
        freopen("battle.out", "w", stdout);
    #endif // ONLINE_JUDGE

    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    set<int> st;
    for (int i = 0; i < k; i++)
        st.insert(vec[i]);

    int ptr = k;
    while (ptr < n) {
        st.insert(vec[ptr++]);
        cout << (*st.begin()) << " ";
        st.erase(st.begin());
    }

    for (auto it : st)
        cout << it << " ";
    cout << endl;
}
