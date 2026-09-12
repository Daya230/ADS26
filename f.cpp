#include <iostream>
#include <string>
using namespace std;

string check(string a){
    string b;
    for (int i =0; i< a.length(); i++){
        if (a[i]=='#'){
            if (!b.empty()){
                b.pop_back();
            }
        }
        else{
            b.push_back(a[i]);
        }
    }
    return b;
}


int main(){
    string a,b;
    cin>> a>>b;
    if (check(a)== check(b)) {
        cout<< "Yes";
    }

    else{
        cout<< "No";
    }
    return 0;
}