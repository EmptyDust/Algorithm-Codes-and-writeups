#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n*2);
        for(int i=0;i<n*2;++i) 
            cin>>nums[i];
        sort(nums.begin(),nums.end());
        cout<<nums[2*n-1]+nums[n-1]-nums[0]-nums[n]<<endl;
        for(int i=0;i<n;++i)
            cout<<nums[i]<<" "<<nums[i+n]<<endl;
    }
    return 0;
}