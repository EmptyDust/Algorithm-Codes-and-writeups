#include <bits/stdc++.h>
#define int long long 
using namespace std;
int nums[500007];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    int ans=0;
    while(t--){
        int n,l,r;
        cin>>n>>l>>r;
        l--,r--;
        for(int i=0;i<n;++i)
            cin>>nums[i];
        map<int,int> mp;
        int len=0;
        int sum=0;
        mp[0]=l-1;
        for(int i=l;i<=r;++i){
            if(nums[i]==1)
                sum++;
            else
                sum--;
            if(mp.count(sum)==0)
                mp[sum]=i;
            else
                len=max(len,i-mp[sum]);
        }
        ans^=len;
    }
    cout<<ans;
    return 0;
}
/*
0110 4
011101 2
0111010 4
*/