#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    for(int i=1;i<16;++i){
        long long temp=1;
        for(int j=0;j<i;++j)
            temp*=i;
        if(n==temp){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}