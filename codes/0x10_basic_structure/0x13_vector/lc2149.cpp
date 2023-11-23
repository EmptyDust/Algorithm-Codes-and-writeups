#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i=0,j=0,k=0;
        while(i<n||j<n){
            while(i<n&&nums[i]<0)++i;
            while(j<n&&nums[j]>0)++j;
            if(i<n)
                ans[k++]=nums[i];
            if(j<n)
                ans[k++]=nums[j];
            ++i;++j;
        }
        return ans;
    }
};