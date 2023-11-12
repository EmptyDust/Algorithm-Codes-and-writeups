#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;++i){
            for(int j=i;j<n&&nums[j]<=2*nums[i];++j){
                ans=max(ans,nums[j]^nums[i]);
            }
        }
        return ans;
    }
};