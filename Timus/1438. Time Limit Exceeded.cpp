#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <vector>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int, int> tt;

const int N = 1000000 + 5;


string lines[N];
int type[N];
int lineCount = 0;
int labelCount = 0;
int variableCount = 0;
map<string, int> labelNumber;
map<string, int> variableNumber;
map<int, string> variableNumberReversed;

int variables[N];

int prints[N];
int gotos[N];
int ifType[N];
int ifLeft[N];
int ifRight[N];
int equatResult[N];
int equatType[N];
int equatLeft[N];
int equatRight[N];
bool activated[N];

bool run = true;


string toLower(string s) {
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ans += s[i] - 'A' + 'a';
        } else {
            ans += s[i];
        }
    }
    return ans;
}

int toNum(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            if (i != 0)
                return -1000000001;
        } else {
            if (s[i] < '0' || s[i] > '9')
                return -1000000001;
        }
    }
    return atoi(s.c_str());
}

int parseIfType(string s) {
    s = toLower(s);

    if (s == "==")
        return 0;
    if (s == "!=")
        return 1;
    if (s == ">=")
        return 2;
    if (s == ">")
        return 3;
    if (s == "<=")
        return 4;
    if (s == "<")
        return 5;

    return -1;
}

int parseEquatType(string s) {
    s = toLower(s);

    if (s == "+")
        return 0;
    if (s == "-")
        return 1;
    if (s == "*")
        return 2;
    if (s == "/")
        return 3;
    if (s == "%")
        return 4;
    if (s == "or")
        return 5;
    if (s == "and")
        return 6;
    if (s == "xor")
        return 7;
    if (s == "not")
        return 8;

    return -1;
}

void parse(int line) {
    stringstream ss(lines[line]);
    string tmp = lines[line];
    if (tmp == "")
        return;
    if (tmp.empty())
        return;
    int lul = 0;
    if (ss.eof())
        return;

    ss >> tmp;
    if (toLower(tmp) == "end") {
        type[line] = 0;
    } else if (toLower(tmp) == "print") {
        type[line] = 1;
    } else if (toLower(tmp) == "goto") {
        type[line] = 3;
    } else if (toLower(tmp) == "if") {
        type[line] = 4;
    } else {
        type[line] = 2;
    }


    // END

    // PRINT
    if (type[line] == 1) {
        ss >> tmp;
        if (!variableNumber.count(tmp)) {
            variableNumber[tmp] = variableCount;
            prints[line] = variableCount;
            variableCount++;
        } else {
            prints[line] = variableNumber[tmp];
        }
    }

    // EQUAT
    if (type[line] == 2) {
        if (!variableNumber.count(tmp)) {
            variableNumber[tmp] = variableCount;
            equatResult[line] = variableCount;
            variableCount++;
        } else {
            equatResult[line] = variableNumber[tmp];
        }

        ss >> tmp;  // '='

        ss >> tmp;

        if (toLower(tmp) == "not") {
            equatType[line] = parseEquatType(tmp);
            ss >> tmp;
            if (!variableNumber.count(tmp)) {
                variableNumber[tmp] = variableCount;
                equatLeft[line] = variableCount;
                variableCount++;
            } else {
                equatLeft[line] = variableNumber[tmp];
            }
        } else {
            if (!variableNumber.count(tmp)) {
                variableNumber[tmp] = variableCount;
                equatLeft[line] = variableCount;
                variableCount++;
            } else {
                equatLeft[line] = variableNumber[tmp];
            }

            if (ss.eof()) {
                equatType[line] = parseEquatType("+");
                tmp = "0";
                if (!variableNumber.count(tmp)) {
                    variableNumber[tmp] = variableCount;
                    equatRight[line] = variableCount;
                    variableCount++;
                } else {
                    equatRight[line] = variableNumber[tmp];
                }
            } else {
                ss >> tmp;
                equatType[line] = parseEquatType(tmp);
                ss >> tmp;
                if (!variableNumber.count(tmp)) {
                    variableNumber[tmp] = variableCount;
                    equatRight[line] = variableCount;
                    variableCount++;
                } else {
                    equatRight[line] = variableNumber[tmp];
                }
            }
        }
    }

    // GOTO
    if (type[line] == 3) {
        ss >> tmp;
        tmp = toLower(tmp);
        gotos[line] = labelNumber[tmp];
    }

    // IF
    if (type[line] == 4) {
        ss >> tmp;
        if (!variableNumber.count(tmp)) {
            variableNumber[tmp] = variableCount;
            ifLeft[line] = variableCount;
            variableCount++;
        } else {
            ifLeft[line] = variableNumber[tmp];
        }

        ss >> tmp;
        ifType[line] = parseIfType(tmp);

        ss >> tmp;
        if (!variableNumber.count(tmp)) {
            variableNumber[tmp] = variableCount;
            ifRight[line] = variableCount;
            variableCount++;
        } else {
            ifRight[line] = variableNumber[tmp];
        }

        ss >> tmp;
        ss >> tmp;
        tmp = toLower(tmp);
        gotos[line] = labelNumber[tmp];
    }
}

void equation(int index, int a, int b, int type) {
    if (type == 0)
        variables[index] = a + b;
    if (type == 1)
        variables[index] = a - b;
    if (type == 2)
        variables[index] = a * b;
    if (type == 3)
        variables[index] = a / b;
    if (type == 4) {
        variables[index] = a % b;
        if (variables[index] < 0)
            variables[index] += abs(b);
    }
    if (type == 5)
        variables[index] = (a | b);
    if (type == 6)
        variables[index] = (a & b);
    if (type == 7)
        variables[index] = (a ^ b);
    if (type == 8)
        variables[index] = (~a);
}

bool check(int a, int b, int type) {
    if (type == 0)
        return (a == b);
    if (type == 1)
        return (a != b);
    if (type == 2)
        return (a >= b);
    if (type == 3)
        return (a > b);
    if (type == 4)
        return (a <= b);
    if (type == 5)
        return (a < b);
}

void work(int &line) {
    if (type[line] == 0) {
        run = false;
        return;
    }

    if (type[line] == 1) {
        cout << variables[prints[line]] << "\n";
        line++;
        return;
    }

    if (type[line] == 2) {
        activated[equatResult[line]] = true;
        int a = variables[equatLeft[line]];
        int b = variables[equatRight[line]];
        equation(equatResult[line], a, b, equatType[line]);
        line++;
        return;
    }

    if (type[line] == 3) {
        line = gotos[line];
        return;
    }

    if (type[line] == 4) {
        int a = variables[ifLeft[line]];
        int b = variables[ifRight[line]];
        if (check(a, b, ifType[line]))
            line = gotos[line];
        else
            line++;
        return;
    }
}

int main() {
    //freopen("/home/izaron/ClionProjects/untitled/input.txt", "r", stdin);

    memset(activated, false, sizeof(activated));

    string s;
    while (getline(cin, s)) {
        if (s == "")
            continue;
        string kz = "";
        kz += s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1] && s[i] == ' ')
                continue;
            else
                kz += s[i];
        }
        if (kz.size() == 1 && kz[0] == ' ')
            continue;
        if (kz[0] == ' ')
            kz = kz.substr(1);
        if (kz[kz.size() - 1] == ' ')
            kz.erase(kz.begin() + kz.size() - 1);
        s = kz;

        stringstream ss(s);
        int cnt = 0;
        while (!ss.eof()) {
            ss >> s;
            if (s.back() == ':') {
                s = toLower(s);
                s.erase(s.begin() + s.size() - 1);
                labelNumber[s] = lineCount;
                labelCount++;
                if (ss.eof())
                    continue;
            } else {
                cnt++;
                lines[lineCount] += s;
                lines[lineCount] += " ";
            }
        }
        if (lines[lineCount].size() > 0 && lines[lineCount][lines[lineCount].size() - 1] == ' ')
            lines[lineCount].erase(lines[lineCount].begin() + lines[lineCount].size() - 1);
        if (cnt != 0)
            lineCount++;
    }

    for (int i = 0; i < lineCount; i++) {
        if (lines[i] == "")
            continue;
        parse(i);
    }

    for (auto it : variableNumber) {
        if (toNum(it.first) != -1000000001)
            variables[it.second] = toNum(it.first);
        else
            variables[it.second] = 0;
    }

    for (auto it : variableNumber) {
        variableNumberReversed[it.second] = it.first;
    }

    int line = 0;
    int ticks = 0;
    while (run) {
        if (line >= lineCount)
            break;
        work(line);
        ticks++;
        if (run && ticks >= 10000000) {
            cout << "Program terminated. Variables state:" << "\n";
            vector< pair<string, int> > vec;
            for (int i = 0; i < N; i++) {
                if (activated[i]) {
                    vec.pb(mkp(variableNumberReversed[i], variables[i]));
                    //cout << variableNumberReversed[i] << ": " << variables[i] << "\n";
                }
            }
            if (vec.size() == 0)
                return 0;
            sort(vec.begin(), vec.end());
            int kek = 0;
            for (auto it : vec) {
                cout << it.first << ": " << it.second << "\n";
                kek = it.second;
            }

            return 0;
        }
    }
}
