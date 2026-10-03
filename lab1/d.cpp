#include <iostream>

using namespace std;

bool IsPrime(int a){
    if(a<2) return false;
    for (int i = 2; i*i<=a;i++){
        if (a%i == 0 )return false;
    }
    return true;
}

int main(){
    int a;
    cin>> a;
    int count = 0;
    int n = 2;
    while (count < a){
        if (IsPrime(n)){
            count ++;
            if (count == a){
                cout<< n<< endl;
                break;
            }
        }
        n++;
    }

}