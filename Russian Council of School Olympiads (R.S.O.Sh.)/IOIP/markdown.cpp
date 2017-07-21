#include <bits/stdc++.h>
using namespace std;

string read_line() {
    string s;
    while (getline(cin, s)) {
        if (!s.empty())
            break;
    }
    return s;
}

string name_to_file(string s) {
    string res = "";
    for (auto it : s) {
        char ch = tolower(it);
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            res += ch;
        else if (ch == ' ')
            res += '_';
    }
    return res;
}

bool file_exists_cpp(string name) {
    ifstream f((name + ".cpp").c_str());
    return f.good();
}

bool file_exists_java(string name) {
    ifstream f((name + ".java").c_str());
    return f.good();
}

string string_to_html(string s) {
    string res = "";
    for (auto it : s) {
        if (it == ' ')
            res += "%20";
        else
            res += it;
    }
    return res;
}

vector<string> cut(string s) {
    vector<string> res;
    string cur = "";
    for (auto it : s) {
        if (it == ' ') {
            if (!cur.empty())
                res.push_back(cur);
            cur = "";
        } else {
            cur += it;
        }
    }
    if (!cur.empty())
        res.push_back(cur);
    return res;
}

struct task {
    string name;
    int earned;
    int cost;
    bool solved;

    task() {}
    task(string name, int earned, int cost) {
        this->name = name;
        this->earned = earned;
        this->cost = cost;
        solved = (earned == cost);
    }
};

struct contest {
    string name;
    string link;
    string analysis;
    vector<int> diplomas;
    vector<task> tasks;
    int task_count;
    int solved_tasks;
    int point_count;
    int earned_points;

    contest() {
        task_count = 0;
        solved_tasks = 0;
        point_count = 0;
        earned_points = 0;
    }

    void add_task(task t) {
        tasks.push_back(t);

        if (t.solved)
            solved_tasks++;
        task_count++;
    
        earned_points += t.earned;
        point_count += t.cost;
    }
};

struct progress {
    string title;
    string title_link;
    vector<string> badges;
    string description;

    int task_count;
    int solved_tasks;
    vector<contest> contests;

    progress() {
        task_count = solved_tasks = 0;
    }

    void add_contest(contest c) {
        contests.push_back(c);
        task_count += c.task_count;
        solved_tasks += c.solved_tasks;
    }
};

progress p;

void read() {
    p.title = read_line();
    p.title_link = read_line();
    p.badges = cut(read_line());
    p.description = read_line();

    int contests;
    cin >> contests;

    for (int i = 0; i < contests; i++) {
        contest c;
        int tasks;

        c.name = read_line();
        c.link = read_line();
        c.analysis = read_line();
        c.diplomas.resize(3);
        for (int i = 0; i < 3; i++)
            cin >> c.diplomas[i];

        cin >> tasks;
        
        for (int z = 0; z < tasks; z++) {
            string name = read_line();
            int er, co;
            cin >> er >> co;

            c.add_task(task(name, er, co));
        }

        p.add_contest(c);
    }
}

void print_badge(string s) {
    if (s == "C++")
        cout << "![C++](https://img.shields.io/badge/language-C++-orange.svg) ";
    if (s == "Java")
        cout << "![Java](https://img.shields.io/badge/language-Java-orange.svg) ";
    if (s == "License")
        cout << "[![License](https://img.shields.io/badge/license-MIT-blue.svg)](./LICENSE.md) ";
    if (s == "ProgressTasks") {
        cout << "![Problems](https://img.shields.io/badge/progress-";
        cout << p.solved_tasks;
        cout << "%2F";
        cout << p.task_count;
        cout << "-ff69b4.svg)"; // color
        cout << " ";
    }
}

void print() {
    cout << "# ";
    cout << "[" << p.title << "](" << p.title_link << ") ";

    for (auto it : p.badges)
        print_badge(it);
    cout << endl;

    cout << endl << p.description << endl << endl;

    for (auto c : p.contests)
        cout << "* " << c.name << endl;
    cout << endl;

    for (auto c : p.contests) {
        cout << "## ";
        cout << "![" << c.name << "](" << c.link << ") ";
        cout << "![Points](https://img.shields.io/badge/points-"
            << c.earned_points << "%2F" << c.point_count << "-blue.svg)" << endl << endl;

        cout << "[Analysis in Russian](" << c.analysis << ")" << endl << endl;

        if (c.diplomas[0] != 0) {
            cout << "![3rd degree](https://img.shields.io/badge/3rd%20degree-"
                << c.diplomas[0] << "%2F" << c.point_count << "-C3834C.svg)" << endl;
            cout << "![2nd degree](https://img.shields.io/badge/2nd%20degree-"
                << c.diplomas[1] << "%2F" << c.point_count << "-C0C0C0.svg)" << endl;
            cout << "![1st degree](https://img.shields.io/badge/1st%20degree-"
                << c.diplomas[2] << "%2F" << c.point_count << "-FFD700.svg)" << endl << endl;
        } else {
            cout << "![Prize Winner](https://img.shields.io/badge/Prize%20Winner-"
                << c.diplomas[1] << "%2F" << c.point_count << "-C0C0C0.svg)" << endl;
            cout << "![Winner](https://img.shields.io/badge/Winner-"
                << c.diplomas[2] << "%2F" << c.point_count << "-FFD700.svg)" << endl << endl;
        }

        cout << "| # | Task | Solution | Points |" << endl;
        cout << "|---| ---- | ------ | -------- |" << endl;

        int cnt = 0;
        char ch = 'A';
        for (auto t : c.tasks) {
            cout << "| " << ch << " | ";    // #

            cout << t.name << " | ";     // task

            string file_name = "./" + c.name + "/" + name_to_file(t.name);
            string html_file_name = "./" + string_to_html(c.name) + "/" + name_to_file(t.name);
            if (file_exists_cpp(file_name)) {
                cout << "[C++](" << html_file_name << ".cpp) ";
            }
            if (file_exists_java(file_name)) {
                cout << "[Java](" << html_file_name << ".java) ";
            }
            cout << " | ";      // solution

            if (t.solved)
                cout << "✓";
            else
                cout << "✗";
            cout << t.earned << " | ";       // points

            cout << endl;
            ch++;
            cnt++;
        }

        cout << endl;
    }

/*
    cout << "## Build and run\n\
```\n\
g++ -std=c++11 %source%.cpp -o %source%\n\
./%source% <input_file >output_file\n\
```" << endl;
*/
}

int main() {
    read();
    print();
}