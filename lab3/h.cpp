#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int n;
    ll k;

    cin >> n >> k;

    vector<ll> pref(n + 1, 0);

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        pref[i + 1] = pref[i] + x;
    }

    int answer = n;

    for (int l = 0; l < n; l++) {
        ll need = pref[l] + k;

        auto it = lower_bound(
            pref.begin() + l + 1,
            pref.end(),
            need
        );

        if (it != pref.end()) {
            int pos = it - pref.begin();
            answer = min(answer, pos - l);
        }
    }

    cout << answer;

    return 0;
}
