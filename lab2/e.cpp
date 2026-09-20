#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>> n;
    vector<long long> a(n);
    for(int i = 0; i<n; i++){
        cin>> a[i];
    }

    int mid = n/2;

    bool f = true;
    for(int i =0; i< n; i++){
        if (i == mid) continue;

        if (!f) cout<<" ";
        cout<< a[i];
        f = false;
    }
    cout<< endl;

    return 0;
}
