#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
        int j;
        for(j=i;j>=1;--j){
            if(nums[j-1]>=nums[j])
                swap(nums[j-1],nums[j]);
            else
                break;
        }
        cout<<j<<' ';
    }
    return 0;
}