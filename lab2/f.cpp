#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin>> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i ++){
        cin>> a[i];
    }
    int m;
    cin>> m;
    vector<long long> b(m);
    for(int i =0;i< m; i++){
        cin>> b[i];
    }
    int i =0,j=0;
    bool first = true;
    while(i<n || j<m){
        long long val;
        if(i<n&& (j>=m || a[i] <= b[j])){
            val = a[i++];
        }
        else{
            val = b[j++];
        }
        if(!first)cout<< " ";
        cout<< val;
        first = false;

    }
    cout<< endl;
    return 0;
}
