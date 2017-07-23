// The solution of the problem was written by Izaron
// Date: 15:06:37   22 Jun 2015
// Execution time: 0.608

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define eb emplace_back
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define pii pair<ll,ll>
#define pss pair<int,int>
#define pdd pair<double,double>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define mem0(m) memset((m), 0, sizeof(m));
#define mem0d(m) memset((m), 0.0, sizeof(m));
#define memb(m) memset((m), false, sizeof(m));
#define For(i,st,n) for(int (i) = (st); (i) < (n); (i)++)
#define rof(i,st,n) for(int (i) = (st); (i) > (n); (i)--)
#define rep(i,st) for(auto &(i) : (st))
typedef long long int ll;
typedef long double ld;



int main() {
    set< tuple<int, int, string> > st;
    st.insert(mt(0, 1000000000, "w"));
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a, b;
        string s;
        scanf("%d%d", &a, &b);

        // wtf?
        b--;

        vector< tuple<int, int, string> > dels;

        cin >> s;
        for(auto it: st) {
            // [  (  ] ) -> [ ](    )
            if(get<0>(it) < a && get<1>(it) >= a && get<1>(it) <= b) {
                st.insert(mt(get<0>(it),a - 1, get<2>(it)));
                dels.pb(it);
            }
            // ( [ ] ) -> (     )
            else if(get<0>(it) >= a && get<1>(it) <= b) {
                dels.pb(it);
            }
            // (  [  )  ] -> (     )[ ]
            else if(get<0>(it) >= a && get<0>(it) <= b && get<1>(it) > b) {
                st.insert(mt(b + 1, get<1>(it), get<2>(it)));
                dels.pb(it);
            }
            // [   (  )  ] -> [  ](  )[ ]
            else if(get<0>(it) < a && get<1>(it) > b) {
                st.insert(mt(get<0>(it), a - 1, get<2>(it)));
                st.insert(mt(b + 1, get<1>(it), get<2>(it)));
                dels.pb(it);
            }
        }

        for(auto it: dels) {
            st.erase(it);
        }

        st.insert(mt(a, b, s));
    }

    //cout << endl;
    //for(auto it: st) {
    //    cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << endl;
    //}

    vector< tuple<int, int, string> > vec;
    for(auto it: st) {
        if(vec.size() == 0)
            vec.pb(it);
        else {
            if(get<2>(vec[vec.size() - 1]) == get<2>(it)) {
                vec[vec.size() - 1] = mt(
                    get<0>(vec[vec.size() - 1]),
                    get<1>(it),
                    get<2>(it)
                );
            } else {
                vec.pb(it);
            }
        }
    }

    //cout << endl;
    //for(auto it: vec) {
    //    cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << endl;
    //}

    int maxi = 0, a = -1, b = -0;
    for(auto it: vec) {
        if(get<2>(it) == "b") continue;
        if(maxi < min(get<1>(it) + 1, 1000000000) - get<0>(it)) {
            maxi = min(get<1>(it) + 1, 1000000000) - get<0>(it);
            a = get<0>(it);
            b = min(get<1>(it) + 1, 1000000000);
        }
    }

    cout << a << " " << b;
}




