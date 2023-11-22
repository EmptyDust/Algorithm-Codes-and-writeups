//ac787
#include <bits/stdc++.h>
using namespace std;
int nums[100007];

void sort(int l,int r){
    if(l>=r)return;
    int mid=l+r>>1;
    sort(l,mid);sort(mid+1,r);
    int k=0,i=l,j=mid+1,tmp[r-l+1];
    while(i<=mid&&j<=r){
        if(nums[i]<nums[j])
            tmp[k++]=nums[i++];
        else
            tmp[k++]=nums[j++];
    }
    while(i<=mid)
        tmp[k++]=nums[i++];
    while(j<=r)
        tmp[k++]=nums[j++];
    for(int t=0;t<r-l+1;++t)
        nums[t+l]=tmp[t];
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>nums[i];
    sort(0,n-1);
    for(int i=0;i<n;++i)cout<<nums[i]<<" ";
    return 0;
}