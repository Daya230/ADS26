#include <iostream>
#include <vector>
using namespace std;

int main() {
    int v;
    cin >> v;

    vector<int> x(v);

    for (int i = 0; i < v; i++) {
        cin >> x[i];
    }
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int k = 0; k < v; k++) {
        int value = x[k];
        bool found = false;

        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = m - 1;

            while (left <= right) {
                int mid = (left + right) / 2;

                if (a[i][mid] == value) {
                    cout << i << " " << mid << endl;
                    found = true;
                    break;
                }

                if (i % 2 == 0) {
                    if (a[i][mid] > value)
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
                else {
                    if (a[i][mid] < value)
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
            }
            if (found)
                break;
        }
        if (!found)
            cout << -1 << endl;
    }



    return 0;
}
