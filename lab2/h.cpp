#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>> n;
    vector <long long> a(n);
    for(int i =0;i< n; i++){
        cin>> a[i];
    }

    long long m_s = a[0];
    long long cur_sum= a[0];

    for(int i =1; i< n; i++){
        cur_sum= max(a[i],cur_sum + a[i]);
        m_s = max(m_s, cur_sum);
    }
    cout<< m_s<< endl;
    return 0;
}
