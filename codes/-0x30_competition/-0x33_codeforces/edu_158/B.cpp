#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        int t;cin>>t;
        vector<int> nums(t);
        cin>>nums[0];
        int ans=nums[0];
        for(int i=1;i<t;++i){
            cin>>nums[i];
            if(nums[i]>nums[i-1])
                ans+=nums[i]-nums[i-1];
        }
        cout<<ans-1<<'\n';
    }
    return 0;
}