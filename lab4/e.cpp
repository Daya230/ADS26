#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 2>> child(n + 1, {-1, -1});

    for (int i = 0; i < n - 1; ++i) {
        int parent, son, side;
        cin >> parent >> son >> side;

        child[parent][side] = son;
    }

    queue<int> q;
    q.push(1);

    int answer = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        answer = max(answer, levelSize);

        for (int i = 0; i < levelSize; ++i) {
            int v = q.front();
            q.pop();

            if (child[v][0] != -1)
                q.push(child[v][0]);

            if (child[v][1] != -1)
                q.push(child[v][1]);
        }
    }

    cout << answer << '\n';

    return 0;
}
