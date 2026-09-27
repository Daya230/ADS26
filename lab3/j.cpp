#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        a[i] = max(x2, y2);
    }

    sort(a.begin(), a.end());

    cout << a[m - 1];

    return 0;
}
