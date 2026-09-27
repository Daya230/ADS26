#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);

    ll left = 0;
    ll right = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        right += a[i];
        left = max(left, a[i]);
    }

    ll answer = right;

    while (left <= right) {
        ll mid = (left + right) / 2;

        int blocks = 1;
        ll sum = 0;

        for (int i = 0; i < n; i++) {
            if (sum + a[i] > mid) {
                blocks++;
                sum = a[i];
            }
            else {
                sum += a[i];
            }
        }

        if (blocks <= k) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}
