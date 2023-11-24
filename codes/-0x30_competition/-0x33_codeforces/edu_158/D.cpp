#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> lm(n,-1);
    for(int i=0;i<n;++i){
        cin>>nums[i];
        if(i==0)
            lm[0]=nums[0];
        else
            lm[i]=max(lm[i-1]+1,nums[i]);
    }
    int rm=-1;
    int ans=INT_MAX;
    for(int i=n-1;i>=1;--i){
        ans=min(ans,max({rm+i+1,lm[i-1]+n-i,nums[i]}));
        rm++;
        rm=max(rm,nums[i]);
    }
    ans=min(ans,max(rm+1,nums[0]));
    cout<<ans;
    return 0;
}