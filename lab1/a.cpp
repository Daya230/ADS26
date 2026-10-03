#include <iostream>
using namespace std;

long long int ev(long long int a,long long int b){
    long long int temp;
    while( b!= 0){
        temp = a%b;
        a = b;
        b = temp;
    }
    return a;


}


int main() {
    long long int a,b;
    cin>> a>> b;
    cout<<ev(a,b);
    return 0;
}