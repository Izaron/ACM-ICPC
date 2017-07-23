#include <bits/stdc++.h>
using namespace std;

const string AUTHOR = "000000JU";
const string PASSWORD = "xxxxxxxxxxx";

map<string, double> task_time;
map<string, string> task_link;

void load_html() {
    // load the entire page
    string command = "(curl \"http://acm.timus.ru/status.aspx?author=" +
        AUTHOR + "&status=accepted&count=1000\") >list.html 2>/dev/null";
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
    for (auto it : s) {
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
        }
    }

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
}

int main() {
    //load_html();
    read_html();
}
