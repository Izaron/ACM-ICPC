#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

struct solver {
    int r, c;
    vector<string> grid;
    vector<pii> beams;
    vector< vector<int> > empty_diff;
    set<pii> st;

    void clear() {
        st.clear();
    }

    bool is_beam(int a, int b) {
        return (grid[a][b] == '|' || grid[a][b] == '-');
    }

    bool is_wall(int a, int b) {
        return grid[a][b] == '#';
    }

    // left mirror is '/'
    bool is_left_mirror(int a, int b) {
        return grid[a][b] == '/';
    }

    // right mirror is '\'
    bool is_right_mirror(int a, int b) {
        return grid[a][b] == '\\';
    }

    bool is_mirror(int a, int b) {
        return is_left_mirror(a, b) || is_right_mirror(a, b);
    }

    bool is_empty(int a, int b) {
        return grid[a][b] == '.' && empty_diff[a][b] != -1;
    }

    bool is_out_of_the_grid(int a, int b) {
        return (a < 0 || b < 0 || a >= r || b >= c);
    }

    /*
        beam states:
        0 - moves to LEFT
        1 - moves to RIGHT
        2 - moves to DOWN
        3 - moves to UP
    */

    int change_state(int state, char mirror) {
        if (mirror == '/') {
            switch (state) {
                case 0:
                    return 2;
                case 1:
                    return 3;
                case 2:
                    return 0;
                case 3:
                    return 1;
                default:
                    exit(0);
            }
        } else if (mirror == '\\') {
            switch (state) {
                case 0:
                    return 3;
                case 1:
                    return 2;
                case 2:
                    return 1;
                case 3:
                    return 0;
                default:
                    exit(0);
            }
        }
    }

    void state_move(int & a, int & b, int state) {
        if (state == 0)
            b--;
        else if (state == 1)
            b++;
        else if (state == 2)
            a++;
        else
            a--;
    }

    bool can_push_beam(int a, int b, int state) {
        int cnt = 0;

        while (true) {
            //cerr << "pos is (" << a << ", " << b << ") " << endl;
            if (is_out_of_the_grid(a, b))
                return true;
            if (is_wall(a, b))
                return true;
            if (is_beam(a, b) && cnt > 0)
                return false;

            if (is_mirror(a, b))
                state = change_state(state, grid[a][b]);

            state_move(a, b, state);
            cnt++;
        }
    }

    bool push_beam(int a, int b, int state, int add) {
        int cnt = 0;

        while (true) {
            //cerr << "push pos is (" << a << ", " << b << ") " << endl;
            if (is_out_of_the_grid(a, b))
                return true;
            if (is_wall(a, b))
                return true;
            if (is_beam(a, b) && cnt != 0)
                return false;

            if (is_mirror(a, b))
                state = change_state(state, grid[a][b]);

            if (is_empty(a, b) && !st.count({a, b})) {
                st.insert({a, b});
                if (add < 0)
                    empty_diff[a][b] = -1;
                else
                    empty_diff[a][b] += add;
            }

            state_move(a, b, state);
            cnt++;
        }
    }

    int get_min_cell(int a, int b, int state) {
        int cnt = 0;
        int res = INT_MAX / 2;

        while (true) {
            if (is_out_of_the_grid(a, b))
                break;
            if (is_wall(a, b))
                break;
            if (is_beam(a, b) && cnt != 0)
                break;

            if (is_mirror(a, b))
                state = change_state(state, grid[a][b]);

            if (is_empty(a, b))
                res = min(res, empty_diff[a][b]);

            state_move(a, b, state);
            cnt++;
        }

        return res;
    }

    int calc_state(int v) {
        int a = beams[v].first, b = beams[v].second;
        int res = 0;

        if (can_push_beam(a, b, 0) && can_push_beam(a, b, 1))
            res |= 1;
        if (can_push_beam(a, b, 2) && can_push_beam(a, b, 3))
            res |= 2;

        return res;
    }

    void input() {
        cin >> r >> c;
        grid.resize(r);
        for (int i = 0; i < r; i++)
            cin >> grid[i];
    }

    vector<string> solve(bool prior) {
        for (int i = 0; i < r; i++) {
            for (int z = 0; z < c; z++) {
                if (is_beam(i, z)) {
                    beams.push_back({i, z});
                }
            }
        }

        empty_diff.resize(r);
        for (int i = 0; i < r; i++)
            empty_diff[i].resize(c);

        for (int i = 0; i < (int) beams.size(); i++) {
            int state = calc_state(i);
            int a = beams[i].first, b = beams[i].second;

            //cerr << "beam at (" << a << ", " << b << ") state is " << state << endl;

            if (state & 1) {
                // left - right
                clear();
                push_beam(a, b, 0, 1);
                push_beam(a, b, 1, 1);
            }
            if (state & 2) {
                // down - up
                clear();
                push_beam(a, b, 2, 1);
                push_beam(a, b, 3, 1);
            }
        }

        while (!beams.empty()) {
            int index = 0;

            for (int i = 0; i < beams.size(); i++) {
                int a = beams[i].first, b = beams[i].second;
                int s = calc_state(i);
                int res = s;
                //cerr << "watching " << a << " " << b << endl;
                //cerr << "res is " << res << endl;
                if (s == 3 && (get_min_cell(a, b, 0) == 1 || get_min_cell(a, b, 1) == 1)) {
                    res -= 2;
                }
                if (s == 3 && (get_min_cell(a, b, 2) == 1 || get_min_cell(a, b, 3) == 1)) {
                    res -= 1;
                }
                //cerr << "upd res is " << res << endl;
                if (res == 0) {
                    return vector<string>(0);
                }
                if (res != 3) {
                    index = i;
                    //cerr << "index is " << index << endl;
                    break;
                }
            }

            int a = beams[index].first, b = beams[index].second;
            int s = calc_state(index);
            int res = s;
            if (s == 3 && (get_min_cell(a, b, 0) == 1 || get_min_cell(a, b, 1) == 1))
                res -= 2;
            if (s == 3 && (get_min_cell(a, b, 2) == 1 || get_min_cell(a, b, 3) == 1))
                res -= 1;

            if (prior) {
                if (res & 2) {
                    clear();
                    push_beam(a, b, 2, -1);
                    push_beam(a, b, 3, -1);
                    grid[a][b] = '|';
                } else if (res & 1) {
                    clear();
                    push_beam(a, b, 0, -1);
                    push_beam(a, b, 1, -1);
                    grid[a][b] = '-';
                }
            } else {
                if (res & 1) {
                    clear();
                    push_beam(a, b, 0, -1);
                    push_beam(a, b, 1, -1);
                    grid[a][b] = '-';
                } else if (res & 2) {
                    clear();
                    push_beam(a, b, 2, -1);
                    push_beam(a, b, 3, -1);
                    grid[a][b] = '|';
                }
            }

            beams.erase(beams.begin() + index);
        }

        for (int i = 0; i < r; i++) {
            for (int z = 0; z < c; z++) {
                if (is_empty(i, z))
                    return vector<string>(0);
            }
        }

        return grid;
    }
};

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cerr << "Case #" << i + 1 << " is being solved..." << endl;
        cout << "Case #" << i + 1 << ": ";
        solver s;
        s.input();
        vector<string> vec = s.solve(false);

        if (vec.empty()) {
            solver ss = s;
            vec = ss.solve(true);
        }

        if (vec.empty())
            cout << "IMPOSSIBLE" << endl;
        else {
            cout << "POSSIBLE" << endl;
            for (auto it : vec)
                cout << it << endl;
        }
    }
}
