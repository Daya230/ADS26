#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Node {
    long long key;
    int left = -1;
    int right = -1;
};

int main() {
    int n;
    cin >> n;

    vector<Node> tree(n);
    set<pair<long long, int>> s;

    long long x;
    cin >> x;

    tree[0].key = x;
    s.insert({x, 0});

    for (int i = 1; i < n; ++i) {
        cin >> x;

        auto it = s.lower_bound({x, -1});

        int parent = -1;

        if (it != s.end()) {
            parent = it->second;
        }

        if (it != s.begin()) {
            auto p = it;
            --p;

            int candidate = p->second;

            if (parent == -1 || candidate > parent) {
                parent = candidate;
            }
        }

        tree[i].key = x;

        if (x < tree[parent].key)
            tree[parent].left = i;
        else
            tree[parent].right = i;

        s.insert({x, i});
    }

    vector<int> stack;
    int current = 0;

    long long sum = 0;
    bool first = true;

    while (current != -1 || !stack.empty()) {

        while (current != -1) {
            stack.push_back(current);
            current = tree[current].right;
        }

        current = stack.back();
        stack.pop_back();

        sum += tree[current].key;

        if (!first)
            cout << ' ';
        first = false;

        cout << sum;

        current = tree[current].left;
    }

    cout << '\n';

    return 0;
}
