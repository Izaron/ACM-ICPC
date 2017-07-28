// The solution of the problem was written by Izaron
// Date: 12:02:32   28 Jul 2017
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

struct data {
    int count;
    string name;
    vector<int> type;   // 0 -int, 1 - strings
    vector<int> spaces;
    vector<string> data_name;
    vector< vector<string> > write_before;

    data() {
        count = 0;
    }
};

vector<data> datas;
map<string, int> data_map;

string s;
int ptr = 0;

ll read_int() {
    ll res = 0;
    for (int i = 0; i < 8; i++) {
        res *= 16LL;
        char ch = s[ptr++];
        if (ch >= '0' && ch <= '9')
            res += (int)(ch - '0');
        else
            res += (int)(ch - 'A' + 10);
    }
    return res;
}

string read_string() {
    int len = read_int();
    string res = "";
    for (int i = 0; i < len; i++) {
        char ch = s[ptr++];
        int a;
        if (ch >= '0' && ch <= '9')
            a = ch - '0';
        else
            a = ch - 'A' + 10;

        ch = s[ptr++];
        int b;
        if (ch >= '0' && ch <= '9')
            b = ch - '0';
        else
            b = ch - 'A' + 10;

        int kek = a * 16 + b;
        //if (kek > 127)
        //    throw 0;
        res += (char)(a * 16 + b);
    }
    return res;
}

void ps(int spaces) {
    for (int i = 0; i < spaces; i++)
        cout << " ";
}

void write_data() {
    int num = read_int() - 1;
    data d = datas[num];

    cout << d.name << endl;
    int s = 1;
    for (int i = 0; i < d.count; i++) {
        s = max(1, (int)(d.spaces[i] - d.write_before[i].size()));
        for (auto it : d.write_before[i]) {
            ps(s); s++;
            cout << it << endl;
        }

        s = d.spaces[i];
        ps(s);
        if (d.type[i] == 0) {
            cout << "int " << read_int() << endl;
        } else {
            cout << "string " << read_string() << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    string tmp;
    cin >> tmp;

    int lines = 0;
    for (int i = 0; i < n; i++) {
        data d;
        cin >> d.name;
        lines++;
        bool add = true;
        while (true) {
            if (lines >= l) break;
            cin >> tmp;
            //cerr << d.name << ": " << tmp << endl;
            if (tmp == "struct")
                break;
            //cerr << d.name << " " << d.count << " " << lines << endl;
            lines++;
            if (add) {
                d.count++;
                if (tmp == "int") {
                    d.type.push_back(0);
                    d.spaces.push_back(1);
                    d.data_name.push_back("");
                    d.write_before.push_back(vector<string>());
                } else if (tmp == "string") {
                    d.type.push_back(1);
                    d.spaces.push_back(1);
                    d.data_name.push_back("");
                    d.write_before.push_back(vector<string>());
                } else {
                    data dd = datas[data_map[tmp]];
                    int minus = d.count;
                    for (int i = 0; i < dd.count; i++) {
                        if (i > 0) d.count++;

                        d.type.push_back(dd.type[i]);
                        d.spaces.push_back(dd.spaces[i] + 1);
                        d.data_name.push_back(tmp);

                        if (i > 0) {
                            vector<string> vec = dd.write_before[i];
                            d.write_before.push_back(vec);
                        } else {
                            vector<string> vec;
                            vec.push_back(dd.name);
                            for (auto it : dd.write_before[0])
                                vec.push_back(it);
                            d.write_before.push_back(vec);
                        }

                        if (d.count >= 1300) {
                            add = false;
                            break;
                        }
                    }
                }

                if (d.count >= 1300)
                    add = false;
            }
        }
        datas.push_back(d);
        data_map[d.name] = datas.size() - 1;
    }

    /*
    cerr << "Full dump:" << endl;
    for (int i = 0; i < n; i++) {
        data d = datas[i];
        for (int z = 0; z < d.count; z++) {
            cout << d.type[z] << " " << d.spaces[z] << " " << d.data_name[z] << endl;
        }
    }
    cerr << "Full dump over" << endl;
    */

    /*
    data d = datas[n - 1];
    for (int i = 0; i < d.count; i++)
        cerr << i << ": " << d.spaces[i] << endl;
    */

    cin >> s;
    while (ptr < s.size())
        write_data();
}
