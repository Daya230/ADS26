#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Node {
    long long value;
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

    set<pair<long long, int>> s;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;

        auto it = s.lower_bound({x, -1});

        if (it != s.end() && it->first == x) {
            continue;
        }

        int id = tree.size();

        if (s.empty()) {
            tree.push_back({x, -1, -1});
            s.insert({x, id});
            continue;
        }

        int parent = -1;

        if (it != s.end()) {
            parent = it->second;
        }

        if (it != s.begin()) {
            auto p = prev(it);

            if (parent == -1 || p->second > parent) {
                parent = p->second;
            }
        }

        tree.push_back({x, -1, -1});

        if (x < tree[parent].value) {
            tree[parent].left = id;
        } else {
            tree[parent].right = id;
        }

        s.insert({x, id});
    }

    int m = tree.size();

    vector<int> height(m, 1);

    int answer = 1;

    for (int v = m - 1; v >= 0; --v) {
        int leftHeight = 0;
        int rightHeight = 0;

        if (tree[v].left != -1) {
            leftHeight = height[tree[v].left];
        }

        if (tree[v].right != -1) {
            rightHeight = height[tree[v].right];
        }

        answer = max(answer, leftHeight + rightHeight + 1);

        height[v] = max(leftHeight, rightHeight) + 1;
    }

    cout << answer << '\n';

    return 0;
}