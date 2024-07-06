#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        if(n==0)return ans;
        if(n==1)return nums;
        sort(nums.begin(),nums.end());
        if(nums[1]-nums[0]>1)
            ans.push_back(nums[0]);
        for(int i=1;i<nums.size()-1;++i){
            if(nums[i]-nums[i-1]>1&&nums[i+1]-nums[i]>1){
                ans.push_back(nums[i]);
            }
        }
        if(nums[n-1]-nums[n-2]>1)
            ans.push_back(nums[n-1]);
        return ans;
    }
};