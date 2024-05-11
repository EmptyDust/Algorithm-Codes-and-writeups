#include <bits/stdc++.h>
#define int long long
using namespace std;
int nums[5000005];
int find_element(int l,int r,int f){
    if(l>=r)return nums[l];
    int i=l-1;
    int j=r+1;
    int mid=l+rand()%(r-l+1);
    while(i<j){
        do i++; while(nums[i]<nums[mid]);
        if(i<j) swap(nums[i],nums[mid]);
        mid=i;
        do j--; while(nums[j]>nums[mid]);
        if(i<j) swap(nums[j],nums[mid]);
        mid=j;
    }
    if(mid==f)return nums[mid];
    return (mid>f?find_element(l,mid,f):find_element(mid+1,r,f));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    srand((unsigned)time(NULL));
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;++i)cin>>nums[i];
    cout<< find_element(0,m-1,n)<<'\n';
    //for(int num:nums)cout<<num<<' ';
    return 0;
}