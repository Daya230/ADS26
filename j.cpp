#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> b;
    queue<int> n;
    
    for(int i =0; i< 5; i++){
        int x;
        cin>> x;
        b.push(x);
    }

    for (int i =0; i< 5; i ++){
        int x;
        cin>> x;
        n.push(x);
    }
    int m =0;

    while (!b.empty()&& !n.empty()){
        int r = b.front();
        int  t= n.front();

        b.pop();
        n.pop();
        m++;

        bool bWins;

        if (r==0 && t== 9){
            bWins=true;
        }
        else if(r == 9 && t == 0){
            bWins =  false;
        }
        else{
            bWins = r> t;
        }

        if (bWins){
            b.push(r);
            b.push(t);
        }
        else{
            n.push(r);
            n.push(t);
        }
    }
    if (b.empty()){
        cout<< "Nursik "<< m<< endl;
    }
    else{
        cout<< "Boris "<< m<< endl;
    }
}