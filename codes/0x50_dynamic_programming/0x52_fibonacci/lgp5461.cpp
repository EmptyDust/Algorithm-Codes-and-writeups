#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    n=pow(2,n);
    vector<int> dp(n,0); 
    dp[n-1]=1;
    for(int num:dp)cout<<num<<' ';
    cout<<endl;
    for(int i=1;i<n;++i){
        for(int j=0;j<n-1;++j){
            dp[j]=(dp[j]+dp[j+1])%2;
            cout<<dp[j]<<' ';
        }
        cout<<1;
        cout<<endl;
    }
    return 0;
}