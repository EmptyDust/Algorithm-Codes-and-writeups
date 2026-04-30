#include <bits/stdc++.h>
#define int long long
using namespace std;
int nums[200006] = {0};

int o(int x,int y){
    if(x%y==0)return y;
    return o(y,x%y);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;cin>>n;
    while(n--){
        int t;
        cin>>t;
        for(int i=0;i<t;++i)
            cin>>nums[i];
        if(t==1){
            cout<<1<<'\n';
            continue;
        }
        sort(nums,nums+t);
        int ts=nums[1]-nums[0];
        int ad=nums[0]-ts;
        for(int i=2;i<t;++i){
            if((nums[i]-nums[i-1])%ts==0){
                if(nums[i]-nums[i-1]!=ts)
                    ad=nums[i]-ts;
                continue;
            }
            ts=o(max(ts,nums[i]-nums[i-1]),min(ts,nums[i]-nums[i-1]));
            if(nums[i]-nums[i-1]!=ts)
                ad=nums[i]-ts;
            else
                ad=nums[i-1]-ts;
        }
        int maxn=nums[t-1];
        int sum=(maxn-ad)/ts;
        for(int i=0;i<t;++i)
            sum+=(maxn-nums[i])/ts;
        cout<<sum<<'\n';
    }
    return 0;
}
