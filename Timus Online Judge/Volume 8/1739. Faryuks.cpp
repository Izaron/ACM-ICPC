// The solution of the problem was written by Izaron
// Date: 14:41:19   26 Jul 2017
// Execution time: 0.889

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <vector>
#include <string.h>
#include <sstream>
#include <iostream>
#include <map>
#include <limits.h>
#include <set>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = (1 << 12);

int n;
vector<int> vec;
vector<string> coms[maxn][4];

string take(vector<int>& vals) {
    stringstream ss;
    ss << "take ";
    ss << vals.size() << " ";
    for (auto it : vals)
        ss << it + 1 << " ";
    return ss.str();
}

string dearomatize(vector<int>& vals, int v) {
    stringstream ss;
    ss << "dearomatize ";
    ss << vals[v] + 1 << " ";
    return ss.str();
}

string aromatize(vector<int>& vals, int v) {
    stringstream ss;
    ss << "aromatize ";
    ss << vals[v] + 1 << " ";
    return ss.str();
}

// mask - subset of indexes, f - used aromats
void generate(int mask, int f) {
    vector<int> vals;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0)
            continue;
        vals.push_back(i);
    }

    int sum = 0;
    for (auto it : vals)
        sum += vec[it];

    // simple sum
    if (sum % 256 == 0) {
        coms[mask][f].push_back(take(vals));
        return;
    }

    // one dearomatize
    if ((f | 2) == f) {
        for (int i = 0; i < vals.size(); i++) {
            if (vec[vals[i]] % 4 == 0) {
                int tsum = sum - vec[vals[i]] + vec[vals[i]] / 4 * 3;
                if (tsum % 256 == 0) {
                    coms[mask][f].push_back(dearomatize(vals, i));
                    coms[mask][f].push_back(take(vals));
                    return;
                }
            }
        }
    }

    // one aromatize
    if ((f | 1) == f) {
        for (int i = 0; i < vals.size(); i++) {
            if (vec[vals[i]] % 10 == 0) {
                int tsum = sum - vec[vals[i]] + vec[vals[i]] / 10 * 11;
                if (tsum % 256 == 0) {
                    coms[mask][f].push_back(aromatize(vals, i));
                    coms[mask][f].push_back(take(vals));
                    return;
                }
            }
        }
    }

    // dearomatize + aromatize on ONE fruit
    if ((f | 3) == f) {
        for (int i = 0; i < vals.size(); i++) {
            if (vec[vals[i]] % 40 == 0) {
                int tsum = sum - vec[vals[i]] + vec[vals[i]] / 40 * 33;
                if (tsum % 256 == 0) {
                    coms[mask][f].push_back(dearomatize(vals, i));
                    coms[mask][f].push_back(aromatize(vals, i));
                    coms[mask][f].push_back(take(vals));
                    return;
                }
            }
        }
    }

    // dearomatize + aromatize on TWO fruits
    if ((f | 3) == f) {
        for (int i = 0; i < vals.size(); i++) {
            for (int z = 0; z < vals.size(); z++) {
                if (i == z)
                    continue;
                //if (vec[vals[i]] % 4 != 0)
                //    continue;
                //if (vec[vals[z]] % 10 != 0)
                //    continue;
                int tsum = sum - vec[vals[i]] - vec[vals[z]];

                int kek = 15 * vec[vals[i]] + 22 * vec[vals[z]];
                if (kek % 20 != 0)
                    continue;
                tsum += kek / 20;

                if (tsum % 256 == 0) {
                    coms[mask][f].push_back(dearomatize(vals, i));
                    coms[mask][f].push_back(aromatize(vals, z));
                    coms[mask][f].push_back(take(vals));
                    return;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    for (int i = 1; i < (1 << n); i++) {
        for (int z = 0; z < 4; z++) {
            generate(i, z);
            //if (!coms[i][z].empty())
            //    cerr << "generated " << i << " " << z << endl;
        }
    }

    vector<int> masks;
    vector<int> pushes;
    vector<int> index_back;
    vector< vector<string> > do_command;

    masks.push_back(0);
    pushes.push_back(0);
    index_back.push_back(0);
    do_command.push_back(vector<string>());

    vector<int> used(1 << (n + 2));

    int best_ind, ind_p = INT_MAX / 2;

    for (int i = 0; i < masks.size(); i++) {
        int cur = masks[i] >> 2;    // current mask
        int f = masks[i] & 3;     // aromats available
        int p = pushes[i];      // number of pushes
        used[masks[i]] = true;

        //cerr << "mask is " << cur << " aroms is " << f << endl;

        if (cur == (1 << n) - 1) {
            if (ind_p > p) {
                ind_p = p;
                best_ind = i;
            }
            continue;
        }

        for (int sub = 1; sub < (1 << n); sub++) {
            // stole from the farm (maybe using arom/dearom)
            for (int use_f = 0; use_f < 4; use_f++) {
                if ((sub & cur) == 0 && (f & use_f) == 0 && !coms[sub][use_f].empty() &&
                                !used[(use_f ^ f) + (sub | cur) * 4]) {
                    used[(use_f ^ f) + (sub | cur) * 4] = true;
                    masks.push_back((use_f ^ f) + (sub | cur) * 4);
                    pushes.push_back(p + 1);

                    index_back.push_back(i);
                    do_command.push_back(coms[sub][use_f]);
                }
            }

            // push back at the farm
            if ((cur | sub) == cur) {
                if (!used[f + (cur ^ sub) * 4]) {
                    used[f + (cur ^ sub) * 4] = true;
                    masks.push_back(f + (cur ^ sub) * 4);
                    pushes.push_back(p);

                    index_back.push_back(i);

                    int cnt = __builtin_popcount(sub);
                    string s = "return " + to_string(cnt);
                    for (int z = 0; z < n; z++) {
                        if ((sub & (1 << z)) != 0) {
                            s += " " + to_string(z + 1);
                        }
                    }
                    vector<string> vs = { s };
                    do_command.push_back(vs);
                }
            }
        }
    }

    if (ind_p >= INT_MAX / 2) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<string> res;
    int ind = best_ind;
    while (true) {
        if (ind == 0)
            break;
        vector<string> vs = do_command[ind];
        ind = index_back[ind];
        reverse(vs.begin(), vs.end());
        for (auto it : vs)
            res.push_back(it);
    }

    //cout << "YES" << endl;
    //cout << p << endl;

    if (res.size() > 20000)
        throw 0;

    cout << res.size() << endl;
    reverse(res.begin(), res.end());
    for (auto it : res)
        cout << it << endl;

    return 0;
}
