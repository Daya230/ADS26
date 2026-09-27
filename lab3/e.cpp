#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int cnt1 = upper_bound(a.begin(), a.end(), r1)
                 - lower_bound(a.begin(), a.end(), l1);

        int cnt2 = upper_bound(a.begin(), a.end(), r2)
                 - lower_bound(a.begin(), a.end(), l2);

        int L = max(l1, l2);
        int R = min(r1, r2);

        int inter = 0;

        if (L <= R) {
            inter = upper_bound(a.begin(), a.end(), R)
                  - lower_bound(a.begin(), a.end(), L);
        }

        cout << cnt1 + cnt2 - inter << '\n';
    }

    return 0;
}
