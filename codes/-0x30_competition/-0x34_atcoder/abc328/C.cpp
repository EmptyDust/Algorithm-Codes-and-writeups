#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,q;
    cin>>n>>q;
    vector<int> dp(n);dp[0]=0;
    string str;cin>>str;

    for(int i=1;i<n;++i)
        dp[i]=dp[i-1]+(str[i]==str[i-1]);
    while(q--){
        int a,b;cin>>a>>b;
        cout<<dp[b-1]-dp[a-1]<<endl;
    }
    return 0;
}