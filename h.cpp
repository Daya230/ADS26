#include <iostream>
#include <stack>

using namespace std;

int main(){
    int a;
    cin>> a;
    stack<int> st;

    for(int i =0; i< a; i++){
        int x;
        cin>> x;
        while (!st.empty() && st.top() >= x){
            st.pop();
        }
        if (st.empty()){
            cout<< -1<< " ";
        }
        else{
            cout<< st.top()<< " ";
        }
        st.push(x);
    }
    return 0 ;
}
