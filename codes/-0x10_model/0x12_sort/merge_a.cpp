#include <bits/stdc++.h>
using namespace std;
#define int long long
int nums[100007];

int cntx(int l,int r){
    if(l>=r)return 0;
    int mid=l+r>>1;
    int ans = cntx(l,mid)+cntx(mid+1,r);
    //cout<<ans<<" ";
    int k=0,i=l,j=mid+1,tmp[r-l+1];
    while(i<=mid&&j<=r){
        if(nums[i]<=nums[j])
            tmp[k++]=nums[i++];
        else{
            tmp[k++]=nums[j++];
            ans+=mid-i+1;
        }
    }
    while(i<=mid)
        tmp[k++]=nums[i++];
    while(j<=r)
        tmp[k++]=nums[j++];
    for(int t=0;t<r-l+1;++t)
        nums[t+l]=tmp[t];
    return ans;
}
signed main(){
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>nums[i];
    cout<<cntx(0,n-1)<<endl;
    return 0;
}