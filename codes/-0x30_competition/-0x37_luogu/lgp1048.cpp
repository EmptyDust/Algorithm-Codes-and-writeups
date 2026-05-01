#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t,m;
    cin>>t>>m;
    vector<int> dp(t+1);
    while(m--){
        int w,v;
        cin>>w>>v;
        for(int i=t;i>=w;--i)
            dp[i]=max(dp[i],dp[i-w]+v);
    }
    cout<<dp[t];
    return 0;
}