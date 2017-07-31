// The solution of the problem was written by Izaron
// Date: 22:51:43   29 Jul 2017
// Execution time: 0.062

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <limits.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<vint> pic;


struct trie {
    map<int, trie*> nxt;
    map<int, int> res;

    trie() {

    }
};

trie* tup = new trie();
trie* tdown = new trie();

void insert(trie* t, vint& vec, int ind, int mask) {
    for (auto it : vec) {
        if (!t->nxt.count(it))
            t->nxt[it] = new trie();
        t = t->nxt[it];
    }
    t->res[mask] = ind;
}

trie* trie_move(trie* t, vint& vec) {
    for (auto it : vec) {
        if (!t->nxt.count(it))
            return nullptr;
        t = t->nxt[it];
    }
    return t;
}

pic bp() {
    pic p(4);
    for (int i = 0; i < 4; i++)
        p[i].resize(4);
    return p;
}

pic read() {
    pic p = bp();
    for (int i = 0; i < 4; i++)
        for (int z = 0; z < 4; z++)
            cin >> p[i][z];
    return p;
}

void pp(pic& p) {
    for (int i = 0; i < 4; i++) {
        for (int z = 0; z < 4; z++) {
            cerr << p[i][z] << " ";
        }
        cerr << endl;
    }
    cerr << endl;
}

pic revert(pic& p) {
    pic res = bp();
    for (int i = 0; i < 4; i++) {
        for (int z = 0; z < 4; z++) {
            res[i][z] = p[3 - z][i];
        }
    }
    return res;
}

vector<pic> vec[9];

bool equal_bounds(pic& a, pic& b) {
    for (int i = 0; i < 4; i++)
        if (a[i][3] != b[i][0])
            return false;
    return true;
}

vint gen_up(pic& a, pic& b, pic& c) {
    vint res(10);
    int cnt = 0;
    for (int i = 0; i < 4; i++)
        res[cnt++] = a[0][i];
    for (int i = 1; i < 4; i++)
        res[cnt++] = b[0][i];
    for (int i = 1; i < 4; i++)
        res[cnt++] = c[0][i];
    return res;
}

vint gen_down(pic& a, pic& b, pic& c) {
    vint res(10);
    int cnt = 0;
    for (int i = 0; i < 4; i++)
        res[cnt++] = a[3][i];
    for (int i = 1; i < 4; i++)
        res[cnt++] = b[3][i];
    for (int i = 1; i < 4; i++)
        res[cnt++] = c[3][i];
    return res;
}

struct nabor {
    int a, b, c, x, y, z;
    nabor(int _a, int _b, int _c, int _x, int _y, int _z) :
            a(_a), b(_b), c(_c),
            x(_x), y(_y), z(_z) {

    }
};

vector<nabor> nabors;
vector<vint> nabors_up;
vector<vint> nabors_down;

int rocks = 0;

void work(int a, int b, int c, int x, int y, int z) {
    if (!equal_bounds(vec[a][x], vec[b][y]))
        return;
    if (!equal_bounds(vec[b][y], vec[c][z]))
        return;

    //cerr << a << " " << b << " " << c << " "
    //    << x << " " << y << " " << z << " rocks! " << rocks++ << endl;

    vint up = gen_up(vec[a][x], vec[b][y], vec[c][z]);
    insert(tup, up, nabors.size(), (1 << a) | (1 << b) | (1 << c));

    vint down = gen_down(vec[a][x], vec[b][y], vec[c][z]);
    insert(tdown, down, nabors.size(), (1 << a) | (1 << b) | (1 << c));

    nabors.push_back(nabor(a, b, c, x, y, z));
    nabors_up.push_back(up);
    nabors_down.push_back(down);

/*
    cerr << "his up is:   ";
    for (auto it : up)
        cerr << it << " ";
    cerr << endl;

    cerr << "his down is: ";
    for (auto it : up)
        cerr << it << " ";
    cerr << endl;

    cerr << "is ok..." << endl;
*/
}

void p_nabor(int v) {
    cout << endl << endl;
    cerr << "nabor " << v << ": ";
    nabor& n = nabors[v];
    cout << n.a << " " << n.b << " " << n.c << " " <<
        n.x << " " << n.y << " " << n.z << endl;
    cerr << "his up is:   ";
    for (auto it : nabors_up[v])
        cerr << it << " ";
    cerr << endl;

    cerr << "his down is: ";
    for (auto it : nabors_down[v])
        cerr << it << " ";
    cerr << endl;

    for (auto it : vec[n.a][n.x]) {
        for (auto z : it)
            cerr << z << " ";
        cerr << endl;
    }
    cerr << endl;

    for (auto it : vec[n.b][n.y]) {
        for (auto z : it)
            cerr << z << " ";
        cerr << endl;
    }
    cerr << endl;

    for (auto it : vec[n.c][n.z]) {
        for (auto z : it)
            cerr << z << " ";
        cerr << endl;
    }

    cout << endl << endl;
}

void print_vivint(vector<vint> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int z = 0; z < v[i].size(); z++)
            cout << v[i][z] << " ";
        cout << endl;
    }
}

void set_nabor(vector<vint>& v, int nab, int pos) {
    nabor& n = nabors[nab];
    pic& a = vec[n.a][n.x];
    pic& b = vec[n.b][n.y];
    pic& c = vec[n.c][n.z];
    for (int i = 0; i < 4; i++) {
        for (int z = 0; z < 4; z++) {
            v[i + pos][z] = a[i][z];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int z = 0; z < 4; z++) {
            v[i + pos][z + 3] = b[i][z];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int z = 0; z < 4; z++) {
            v[i + pos][z + 6] = c[i][z];
        }
    }
}

bool check_nabor(int v) {
    trie* tb = trie_move(tup, nabors_down[v]);
    trie* ta = trie_move(tdown, nabors_up[v]);
    if (ta == nullptr || tb == nullptr)
        return false;

    //cerr << "maybe " << v << " is the middle" << endl;
    //return false;

    nabor& n = nabors[v];
    int m = (1 << n.a) | (1 << n.b) | (1 << n.c);

    for (int a = 0; a < 9; a++) {
        for (int b = 0; b < 9; b++) {
            for (int c = 0; c < 9; c++) {
                if (a == b || b == c || a == c) continue;
                int m1 = (1 << a) | (1 << b) | (1 << c);
                if ((m & m1) != 0) continue;

                for (int x = 0; x < 9; x++) {
                    for (int y = 0; y < 9; y++) {
                        for (int z = 0; z < 9; z++) {
                            if (x == y || x == z || y == z) continue;
                            int m2 = (1 << x) | (1 << y) | (1 << z);
                            if ((m & m2) != 0) continue;
                            if ((m1 & m2) != 0) continue;

                            if (ta->res.count(m1) && tb->res.count(m2)) {
                                //cerr << "FOUND!" << endl;

                                int u = ta->res[m1];
                                int d = tb->res[m2];

                                //cerr << u << " is upper" << endl;
                                //cerr << v << " is middle" << endl;
                                //cerr << d << " is lower" << endl;

                                //p_nabor(u);
                                //p_nabor(v);
                                //p_nabor(d);

                                vector<vint> picture(10);
                                for (int i = 0; i < picture.size(); i++)
                                    picture[i].resize(10);

                                set_nabor(picture, u, 0);
                                set_nabor(picture, v, 3);
                                set_nabor(picture, d, 6);

                                print_vivint(picture);

                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}

void work(int a, int b, int c) {
    for (int x = 0; x < 4; x++)
    for (int y = 0; y < 4; y++)
    for (int z = 0; z < 4; z++)
        work(a, b, c, x, y, z);
}

int main() {
    for (int i = 0; i < 9; i++)
        vec[i].resize(4);
    for (int i = 0; i < 9; i++) {
        vec[i][0] = read();
        for (int z = 1; z < 4; z++)
            vec[i][z] = revert(vec[i][z - 1]);
    }

    for (int a = 0; a < 9; a++) {
        for (int b = 0; b < 9; b++) {
            if (a == b) continue;
            for (int c = 0; c < 9; c++) {
                if (a == c || b == c) continue;
                work(a, b, c);
            }
        }
    }

    for (int i = 0; i < nabors.size(); i++) {
        if (check_nabor(i))
            break;
    }

    //cerr << "Fuuuh, all work is done..." << endl;
}
