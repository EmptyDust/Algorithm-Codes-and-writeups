#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    int ans,sum,t,nums[100007];
    ans=sum=t=0;
    for(int i=0;i<n;++i){
        if(t==k)
            sum-=nums[i-k];
        else
            t++;
        cin>>nums[i];
        sum+=nums[i];
        ans=max(ans,sum);
    }
    cout<<ans;

    return 0;
}


