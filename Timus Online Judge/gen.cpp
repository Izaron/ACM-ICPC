#include <bits/stdc++.h>
using namespace std;

const string AUTHOR_NICKNAME = "Izaron";
const string AUTHOR = "180914JU";
const string PASSWORD = "XXXXXXXXXX";
const int PROBLEMS_COUNT = 1108;
const int VOLUMES_COUNT[] = {
    100,
    100,
    100,
    100,
    100,
    100,
    100,
    100,
    97,
    100,
    100,
    11,
};
const string VOLUMES_COLORS[] = {
    "9400D3",
    "4B0082",
    "0000FF",
    "brightgreen",
    "yellow",
    "FF7F00",
    "FF0000",
};

map<string, double> task_time;
map<string, string> task_date;
map<string, string> task_link;

void load_html() {
    // load the entire page
    string command = "(curl \"http://acm.timus.ru/status.aspx?author=" +
        AUTHOR.substr(0, AUTHOR.length() - 2) + "&status=accepted&count=1000\") >list.html 2>/dev/null";
    system(command.c_str());
}

void sfind(string& s, string f, int& pos) {
    pos = s.find(f, pos);
    if (pos == string::npos)
        return;
    pos += f.size();
}

string remove_trash(string s) {
    int cnt = 0;
    string res = "";
    for (int i = 0; i < s.length(); i++) {
        char it = s[i];
        if (i + 2 < s.length() && s.substr(i, 3) == "<BR")
            res += "   ";
        if (it == '<')
            cnt++;
        if (cnt == 0)
            res += it;
        if (it == '>')
            cnt--;
    }
    return res;
}

string get_extension(string link) {
    int pos = link.find_last_of(".");
    if (pos == string::npos)
        return "";
    return link.substr(pos);
}

string remove_spaces(string name) {
    name.erase(name.begin() + name.find(' '));
    for (auto& it : name)
        if (it == ' ')
            it = '-';
    return name;
}

int get_volume(string name) {
    return (name[0] - '0') * 10 + (name[1] - '0') - 9;
}

void gen_markdown() {
    // make statistics
    map<string, int> ext;
    for (auto it : task_link) {
        string name = it.first;
        string link = it.second;
        ext[get_extension(link)]++;
    }

    for (auto it : ext)
        cout << it.first << " " << it.second << endl;

    freopen("README.md", "w", stdout);

    cout << "# Timus Online Judge ";
    int solved = task_link.size(), outof = PROBLEMS_COUNT;
    cout << "![Progress](" << "https://img.shields.io/badge/Progress-" <<
        solved << "%2F" << outof << "-brightgreen.svg" << ")" << endl;

    cout << endl << endl;
    cout << "## Languages" << endl;

    cout << "![C++](" << "https://img.shields.io/badge/C%2B%2B-" << ext[".cpp"] << "-blue.svg" << ")" << endl;
    cout << "![Java](" << "https://img.shields.io/badge/Java-" << ext[".java"] << "-red.svg" << ")" << endl;
    cout << "![C#](" << "https://img.shields.io/badge/C%23-" << ext[".cs"] << "-87CEFA.svg" << ")" << endl;
    cout << "![Python](" << "https://img.shields.io/badge/Python-" << ext[".py"] << "-DEB887.svg" << ")" << endl;
    cout << "![Pascal](" << "https://img.shields.io/badge/Pascal-" << ext[".pas"] << "-FFB6C1.svg" << ")" << endl;

    cout << endl << endl;
    cout << "## Volumes :rainbow: " << endl;

    map<int, int> volumes;
    for (auto it : task_link)
        volumes[get_volume(it.first)]++;

    for (int i = 1; i <= 12; i++) {
        cout << "* ";
        cout << "![Problems solved](" << "https://img.shields.io/badge/Volume%20" << i << "-" <<
            volumes[i] << "%2F" << VOLUMES_COUNT[i - 1] << "-" << VOLUMES_COLORS[(i - 1) % 7] << ".svg"
            << "?style=flat-square" << ")" << endl;
    }

    cout << " :rainbow: Taste the rainbow! :rainbow: " << endl;
}

void read_html() {
    freopen("list.html", "r", stdin);

    string s, tmp;
    while (cin >> tmp)
        s += tmp + " ";
    //cout << s << endl;

    int pos = 0;
    cout << "tak" << endl;
    int cnt = 0;
    while (true) {
        // find link
        sfind(s, "<TD class=\"id\">", pos);
        if (pos == string::npos)
            break;

        sfind(s, "<A HREF=\"", pos);
        string link = s.substr(pos, s.find("\"", pos) - pos);
        cout << link << endl;

        // find date
        sfind(s, "<TD class=\"date\">", pos);
        string date = s.substr(pos, s.find("</TD>", pos) - pos);
        date = remove_trash(date);
        cout << date << endl;

        // find a problem's name
        sfind(s, "<TD class=\"problem\">", pos);
        sfind(s, "<A HREF=\"", pos);
        string name = "<" + s.substr(pos, s.find("</A>", pos) - pos);
        name = remove_trash(name);
        cout << name << endl;

        // find runtime
        sfind(s, "<TD class=\"runtime\">", pos);
        string runtime = s.substr(pos, s.find("<", pos) - pos);
        cout << runtime << endl;

        cout << endl;

        double rt = stod(runtime);
        if (!task_time.count(name) || task_time[name] > rt) {
            task_time[name] = rt;
            task_link[name] = link;
            task_date[name] = date;
        }
    }

    fclose(stdin);

    int cur = 1, all = task_link.size();
    for (auto it : task_link) {
        string name = it.first;
        string link = it.second;

        string command = "curl -X POST -F \"JudgeID=" + AUTHOR +
             "\" -F \"Password=" + PASSWORD + "\" -F \"action=getsubmit\" " +
             "http://acm.timus.ru/" + link + " >\"" + name + get_extension(link) +
             "\" 2>/dev/null";

        system(command.c_str());
        cout << cur++ << "/" << all << " tasks are downloaded..." << endl;
        //cout << command << endl;
    }

    for (auto it : task_link) {
        string name = it.first;
        string link = it.second;
        string filename = name + get_extension(link);

        ofstream outputFile("tmp");
        ifstream inputFile(filename);
        string tempString;

        outputFile << "// The solution of the problem was written by " << AUTHOR_NICKNAME << endl;
        outputFile << "// Date: " << task_date[name] << endl;
        outputFile << "// Execution time: " << task_time[name] << endl;
        outputFile << endl;
        outputFile << "// Please do not copy-paste the solution." << endl;
        outputFile << "// Try to understand what is happening here and write your own." << endl << endl;

        outputFile << inputFile.rdbuf();

        inputFile.close();
        outputFile.close();

        remove(filename.c_str());
        rename("tmp", filename.c_str());
    }

    gen_markdown();
}

void erase_html() {
    remove("list.html");
}

int main() {
    load_html();
    read_html();
    erase_html();
}
