#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> e(n);
    int sum =0;

    for(int i =0; i < n; i++){
        int x;
        cin>>x;
        sum+=x;
        e[i]=sum;

    }

    for(int i =0; i<m; i++){
        int mis;
        cin>> mis;
        int left = 0;
        int right = n-1;

        while (left<right){
            int mid = (left+right)/2;
            if(e[mid]>=mis){
                right = mid;
            }
            else{
                left = mid +1;
            }
        }
        cout<< left+1<< endl;
    }
    return 0;
}
