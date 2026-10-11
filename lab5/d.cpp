#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int main() {
    int n;
    ll k;
    cin>> n>> k;

    priority_queue< ll, vector<ll>, greater<ll>> pq;

    for(int i =0; i< n ; i++){
        ll x;
        cin>> x;
        pq.push(x);
    }
    int ans =0;
    while (pq.size()>1 && pq.top()< k){
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();

        ll nVal = a+2*b;
        pq.push(nVal);

        ans++;
    }
    if (pq.top()< k){
        cout<< -1;
    }else cout<< ans;


    return 0;
}
