#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    int left = -1;
    int right = -1;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Node> tree;
    tree.reserve(n);

    int x;
    cin >> x;

    // Первый элемент — корень
    tree.push_back({x, -1, -1});

    for (int i = 1; i < n; ++i) {
        cin >> x;

        int current = 0;

        while (true) {
            if (x < tree[current].value) {
                if (tree[current].left == -1) {
                    tree[current].left = tree.size();
                    tree.push_back({x, -1, -1});
                    break;
                }

                current = tree[current].left;
            } else {
                if (tree[current].right == -1) {
                    tree[current].right = tree.size();
                    tree.push_back({x, -1, -1});
                    break;
                }

                current = tree[current].right;
            }
        }
    }

    int answer = 0;

    for (const Node& node : tree) {
        if (node.left != -1 && node.right != -1) {
            ++answer;
        }
    }

    cout << answer << '\n';

    return 0;
}
