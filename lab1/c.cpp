#include <iostream>
#include <string>

using namespace std;

string prime(long long a){
    if (a<=1) return "NO";
    for (long long i = 2; i*i <= a; i ++){
        if (a%i ==0){
            return "NO";
        }
    }
    return "YES";
}


int main(){
    long long a;
    cin>> a;
    cout<< prime(a)<< endl;
    return 0;
}