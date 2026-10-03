#include <iostream>
#include <string>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

void insert(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }

    if (value <= root->value) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

bool checkPath(Node* root, string path) {
    Node* cur = root;

    for (char direction : path) {
        if (cur == nullptr) {
            return false;
        }

        if (direction == 'L') {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    return cur != nullptr;
}

int main() {
    int n, m;
    cin >> n >> m;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }

    for (int i = 0; i < m; i++) {
        string path;
        cin >> path;

        if (checkPath(root, path)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}