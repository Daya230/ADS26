#include <iostream>
#include <deque>

using namespace std;

int main(){
    int a;
    cin>> a;
    while (a--){
        int n;
        cin>>n;
        deque <int> d;

        for (int i = n; i >= 1; i--){
            d.push_front(i);

            int m = d.size();
            int k = i%m;

            while (k--){
                d.push_front(d.back());
                d.pop_back();

            }
        }
        for (int x: d){
            cout << x<<" ";
        }
        cout << '\n';


    }
    return 0;
}