#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){
    int n,k;
    cin>> n>> k;

    vector<string> words(n);

    for(int i = 0; i < n;i++){
        cin>> words[i];
    }
    bool first = true;
    for(int i =k;i< n; i++){
        if (!first) cout<< ' ';
        cout<< words[i];
        first = false;
    }
    for (int i = 0; i< k; i++){
        if(!first) cout<< " ";
        cout<< words[i];
        first= false;
    }
    cout<< endl;

    return 0;
}
