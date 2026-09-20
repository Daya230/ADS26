#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){

    deque<string> dq;
    string cmd;

    while(cin>>cmd){
        if (cmd == "add_front"){
            string title;
            cin>> title;
            dq.push_front(title);
            cout<< "ok"<< endl;
        }
        else if(cmd == "add_back"){
            string title;
            cin>> title;
            dq.push_back(title);
            cout<<"ok"<< endl;
        }
        else if(cmd == "erase_front"){
            if(dq.empty()){
                cout<< "error"<< endl;
            }
            else{
                cout<<dq.front()<< endl;
                dq.pop_front();
            }
        }
        else if(cmd == "erase_back"){
            if (dq.empty()){
                cout<<"error"<< endl;
            }
            else{
                cout<<dq.back()<< endl;
                dq.pop_back();
            }
        }
        else if(cmd == "front"){
            if(dq.empty()){
                cout<<"error"<< endl;
            }
            else{
                cout<< dq.front()<< endl;
            }
        }
        else if(cmd == "back"){
            if (dq.empty()){
                cout<< "error"<< endl;
            }
            else{
                cout<< dq.back()<< endl;
            }
        }
        else if (cmd == "clear"){
            dq.clear();
            cout<<"ok"<< endl;
        }
        else if(cmd == "exit"){
            cout<< "goodbye"<< endl;
            break;
        }
    }
    return 0;
}
