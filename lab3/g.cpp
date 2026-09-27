#include <iostream>
#include <vector>
#include <iomanip>
#define ll long long 
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    int mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    double left = 0.0;
    double right = mx;

    for (int it = 0; it < 100; it++) {
        double mid = (left + right) / 2.0;

        ll pieces = 0;
        for (int i = 0; i < n; i++) {
            pieces += (ll)(a[i] / mid);
        }
        if (pieces >= k) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << fixed << setprecision(9) << left;

    return 0;
}
