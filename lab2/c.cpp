#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>> n;
    if(n<=0) return 0;

    vector<string> res;
    res.reserve(n);

    for(int i =0;i<n; i++){
        string s;
        cin>> s;
        if(res.empty() || res.back()!= s){
            res.push_back(s);
        }
    }
    cout<< res.size()<< endl;
    for(string name: res){
        cout<< name<< endl;
    }
    return 0;
}
