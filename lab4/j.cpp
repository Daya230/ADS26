#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    long long value;
    int left = -1;
    int right = -1;
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<Node> tree(n);

    long long x;
    cin >> x;

    tree[0].value = x;

    for (int i = 1; i < n; ++i) {
        cin >> x;

        tree[i].value = x;

        int cur = 0;

        while (true) {
            if (x < tree[cur].value) {
                if (tree[cur].left == -1) {
                    tree[cur].left = i;
                    break;
                }
                cur = tree[cur].left;
            } else {
                if (tree[cur].right == -1) {
                    tree[cur].right = i;
                    break;
                }
                cur = tree[cur].right;
            }
        }
    }

    stack<int> st;
    int cur = 0;
    int count = 0;

    while (cur != -1 || !st.empty()) {
        while (cur != -1) {
            st.push(cur);
            cur = tree[cur].left;
        }

        cur = st.top();
        st.pop();

        ++count;

        if (count == k) {
            cout << tree[cur].value << '\n';
            return 0;
        }

        cur = tree[cur].right;
    }

    cout << -1 << '\n';

    return 0;
}