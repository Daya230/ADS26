#include <iostream>

using namespace std;

long long power(long long a, long long b, long long c){
    if (c==1) return 0;
    if (b==0) return 1;
    a%=c;

    if (b%2 == 0 ){
        long long half = power(a,b/2,c);
        return (half*half)%c;

    }
    else {
        return(a*power(a,b-1,c))%c;
    }
}

int main(){
    long long a,b,c;
    cin>> a>> b>> c;
    cout << power(a,b,c)<< endl;
    return 0;
}