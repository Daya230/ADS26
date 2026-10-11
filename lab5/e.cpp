#include <iostream>
#include<queue>
#include <string>
#define ll long long
using namespace std;

int main() {
    int n,k;
    cin>> n>>k;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    ll sum =0;

    for(int i =0; i< n; i++){
        string comm;
        cin>> comm;
        if(comm == "insert"){
            ll x;
            cin>> x;


            if(pq.size()< k){
                pq.push(x);
                sum +=x;
            } 
            else if( x> pq.top()){
                sum -=pq.top();
                pq.pop();

                pq.push(x);
                sum +=x;
            }
        } else cout << sum << endl;
    }

    return 0;
}
