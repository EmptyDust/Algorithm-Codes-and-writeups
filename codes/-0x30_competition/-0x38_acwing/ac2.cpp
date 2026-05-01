#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,v;
    cin>>n>>v;
    vector<int> dp(v+1,0);
    while(n--){
        int w,value;
        cin>>w>>value;
        for(int i=v;i>=w;--i){
            dp[i]=max(dp[i],dp[i-w]+value);
        }
    }
    cout<<dp[v];
    return 0;
}