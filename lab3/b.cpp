#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>a(n);

    for(int i =0; i< n; i++){
        cin>> a[i];
    }

    sort(a.begin(),a.end());

    while (q--){
        int l1,l2,r1,r2;
        cin>> l1>> r1>> l2>> r2;

        if(l1>l2){
            swap(l1,l2);
            swap(r1,r2);
        }

        int left1 = lower_bound(a.begin(), a.end(),l1) - a.begin();
        int right1 = upper_bound(a.begin(), a.end(), r1)- a.begin();
        int left2 = lower_bound(a.begin(), a.end(), l2) - a.begin();
        int right2 = upper_bound(a.begin(),a.end(), r2) - a.begin();

        int ans;

        if(r1<l2){
            ans = (right1 - left1)+(right2-left2);
        }

        else{
            int left = min(left1,left2);
            int right = max(right1, right2);
            ans = right -left;
        }

        cout<< ans<<endl;
    }
    return 0;
}
