#include <bits/stdc++.h>
#define int long long
using namespace std;
int nums[1000000];
int l,r;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;cin>>n;
    while(n--){
        int t;cin>>t;
        for(int i=0;i<t;++i)cin>>nums[i];
        l=0,r=t-1;
        while(l<t-1&&nums[l+1]>=nums[l])l++;
        if(l==t-1){
            cout<<0<<'\n';
            continue;
        }
        while(r>0&&nums[r-1]<=nums[r])r--;
        int ans=INT_MAX;
        if(l==r-1&&nums[0]>=nums[t-1])
            ans=min(t-r,2+r);

        l=0,r=t-1;
        while(l<t-1&&nums[l+1]<=nums[l])l++;
        if(l==t-1){
            cout<<1<<'\n';
            continue;
        }
        while(r>0&&nums[r-1]>=nums[r])r--;
        if(l==r-1&&nums[0]<=nums[t-1])
            ans=min({ans,1+t-r,1+r});
        if(ans!=INT_MAX)
            cout<<ans<<'\n';
        else
            cout<<-1<<'\n';
    }
    return 0;
}
