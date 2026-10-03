#include <iostream>
#include <vector>
#include <queue>
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

    if (value < root->value) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }

    queue<Node*> q;
    q.push(root);

    vector<long long> sums;

    while (!q.empty()) {
        int size = q.size();
        long long sum = 0;

        for (int i = 0; i < size; i++) {
            Node* cur = q.front();
            q.pop();

            sum += cur->value;

            if (cur->left != nullptr) {
                q.push(cur->left);
            }

            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }

        sums.push_back(sum);
    }

    cout << sums.size() << "\n";

    for (long long x : sums) {
        cout << x << " ";
    }

    return 0;
}
