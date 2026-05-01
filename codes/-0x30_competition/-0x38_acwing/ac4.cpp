#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,v;
    cin>>n>>v;
    vector<int> dp(v+1,0);
    while(n--){
        int w,value,s;
        cin>>w>>value>>s;
        for(int i=v;i>=w;--i){
            for(int j=1;j<=s&&j*w<=i;++j){
                dp[i]=max(dp[i],dp[i-j*w]+value*j);
            }
        }
    }
    cout<<dp[v];
    return 0;
}