#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> childCount(n, 0);
    set<pair<int, int>> s;

    int x;
    cin >> x;

    s.insert({x, 0});

    int leaves = 1;

    for (int i = 1; i < n; ++i) {
        cin >> x;

        auto it = s.lower_bound({x, -1});

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

        ++leaves;

        if (childCount[parent] == 0) {
            --leaves;
        }

        ++childCount[parent];

        s.insert({x, i});
    }

    cout << leaves << '\n';

    return 0;
}
