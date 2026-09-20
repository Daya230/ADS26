#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve(){
    int n;
    cin>> n;

    queue<char> q;
    vector<int> cnt(26,0);

    for(int i = 0 ; i< n ; i++){
        char ch;
        cin>> ch;

        cnt[ch - 'a']++;
        q.push(ch);

        while(!q.empty()&& cnt[q.front()-'a']>1){
            q.pop();
        }

        if (!q.empty()){
            cout<< q.front();
        }
        else{
            cout << -1;
        }
        if (i< n -1){
            cout<< " ";
        }
    }
    cout<< endl;
}

int main(){
    int a;
    cin>> a;
    while(a--){
        solve();
    }
    return 0;
}
