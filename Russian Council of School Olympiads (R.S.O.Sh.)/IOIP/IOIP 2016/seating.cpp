#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

int n, d;
vector<int> vec;
vector< set<pii> > delta;

int gr(int v) {
   v %= n;
   v += n;
   v %= n;
   return v;
}

int comp = 0;
vector<int> comps;
vector< vector<int> > alls;
vector<bool> used;
vector<int> ans;
bool can = true;
int xmin, xmax;

void dfs(int v, int d) {
   if (used[v]) {
       if (d != ans[v])
           can = false;
       return;
   }

   used[v] = true;
   ans[v] = d;

   comps.push_back(v);

   xmin = min(xmin, d);
   xmax = max(xmax, d);

   for (auto it : delta[v]) {
       dfs(it.first, d + it.second);
       if (!can)
           return;
   }
}

void set_to(vector<int>& vec, int v) {
   for (auto it : vec)
       ans[it] = v;
}

vector<int> sums;

int cs(int l, int r) {
   return sums[r] - (l > 0 ? sums[l - 1] : 0);
}

int calc_sum(int l, int r) {
   if (l < 0)
       return calc_sum(0, r) + cs(gr(l), n - 1);
   if (r >= n)
       return calc_sum(l, n - 1) + cs(0, gr(r));
   return cs(l, r);
}

bool check_ans() {
   for (int i = 0; i < n; i++) {
       sums[i] = ans[i];
       if (i - 1 >= 0)
           sums[i] += sums[i - 1];
   }

   for (int i = 0; i < n; i++) {
       int s = calc_sum(i - d, i + d);
       if (s != vec[i]) {
           return false;
       }
   }

   return true;
}

int main() {
   #ifndef HOME
   freopen("seating.in", "r", stdin);
   freopen("seating.out", "w", stdout);
   #endif

   cin >> n >> d;
   vec.resize(n);
   sums.resize(n);
   for (int i = 0; i < n; i++)
       cin >> vec[i];

   for (int i = 0; i < n; i++) {
       if (abs(vec[i] - vec[(i + 1) % n]) > 1) {
           cout << "NO" << endl;
           return 0;
       }
   }

   delta.resize(n);
   for (int i = 0; i < n; i++) {
       int a = i, b = (i + 1) % n;
       int l = gr(i - d), r = gr(i + 1 + d);

       if (vec[a] == vec[b]) {
           delta[l].insert({ r, 0 });
           delta[r].insert({ l, 0 });
       } else if (vec[a] < vec[b]) {
           delta[l].insert({ r, 1 });
           delta[r].insert({ l, -1 });
       } else {
           delta[l].insert({ r, -1 });
           delta[r].insert({ l, 1 });
       }
   }

   used.resize(n);
   ans.resize(n);

   for (int i = 0; i < n; i++) {
       if (used[i])
           continue;

       comps.clear();
       xmin = INT_MAX;
       xmax = INT_MIN;
       comp++;
       can = true;

       dfs(i, 0);

       if (!can) {
           cout << "NO" << endl;
           return 0;
       }

       if (xmax - xmin > 1) {
           cout << "NO" << endl;
           return 0;
       }

       for (auto it : comps)
           ans[it] -= xmin;

       if (xmin == xmax) {
           alls.push_back(comps);
       }
   }

   if (alls.size() > 0) {
       if (alls.size() <= 10) {
           for (int i = 0; i < (1 << alls.size()); i++) {
               for (int z = 0; z < alls.size(); z++) {
                   if ((i & (1 << z)) == 0)
                       set_to(alls[z], 0);
                   else
                       set_to(alls[z], 1);
               }
               if (check_ans())
                   break;
           }
       } else {
           for (int i = 0; i < alls.size(); i++)
               set_to(alls[i], 0);
           if (!check_ans()) {
               for (int i = 0; i < alls.size(); i++) {
                   set_to(alls[i], 1);
                   if (check_ans())
                       break;
               }
           }
       }
   }

   if (!check_ans()) {
       cout << "NO" << endl;
       return 0;
   }

   cout << "YES" << endl;
   for (auto it : ans)
       cout << it << " ";
   cout << endl;
}
