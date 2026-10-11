#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int main() {
    int n,m;
    cin>> n>> m;

    priority_queue<ll> pq;

    for(int i =0; i < n; i++){
        ll x;
        cin>> x;
        pq.push(x);
    }

    ll ans =0;
    for(int i =0; i< m ; i++){
        ll x = pq.top();
        pq.pop();
        ans +=x;
        pq.push(x-1);
    }
    cout<< ans;

    return 0;
}
