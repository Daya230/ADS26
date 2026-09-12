#include <iostream>
#include <string> 
#include <stack>

using namespace std;

bool check(string a){
    stack<char> st;
    for (char c:a){
        if(!st.empty() && st.top() == c){
            st.pop();
        }
        else{
            st.push(c);
        }
    }
    return st.empty();
}


int main(){
    string a;
    cin>>a;
    if (check(a)){
        cout<< "YES";
    }
    else{
        cout<<"NO";
    }
    return 0;

}