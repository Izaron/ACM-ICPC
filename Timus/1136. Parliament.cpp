
#include <iostream>
#include <vector>
using namespace std;

struct node {
    long val;
    node * left, * right;

    node(long n) : val(n), left(NULL), right(NULL) {}
};

class tree {
    private:
        node * root;
    public:
        tree(long val) : root(new node(val)) {}

        void add(node * curr, long val) {
            if (curr->val > val) {
                if (curr->left)
                    add(curr->left, val);
                else
                    curr->left = new node(val);
            }
            else {
                if (curr->right)
                    add(curr->right, val);
                else
                    curr->right = new node(val);
            }
        }

        void push(long val) {
            add(root, val);
        }

        void show() {
            visit(root);
        }

        void visit(node * curr) {
            if (curr->right)
                visit(curr->right);
            if (curr->left)
                visit(curr->left);

            cout << curr->val << ' ';
        }
};

int main() {
    vector<long> id; long temp;
    int n; cin >> n;

    while (n--) {
        cin >> temp;
        id.push_back(temp);
    }

    tree parl(id[id.size()-1]);

    for (int i = id.size()-2; i >= 0; --i)
        parl.push(id[i]);
    parl.show();
    cout << endl;

    return 0;
}