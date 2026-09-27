#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll n, h;
    cin >> n >> h;

    vector<ll> a(n);

    ll mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    ll left = 1;
    ll right = mx;
    ll ans = mx;

    while (left <= right) {
        ll mid = (left + right) / 2;

        ll hours = 0;

        for (int i = 0; i < n; i++) {
            hours += (a[i] + mid - 1) / mid;
        }

        if (hours <= h) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
