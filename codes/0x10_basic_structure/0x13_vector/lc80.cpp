#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=0;
        int i,j;
        for(i=0,j=0;i<nums.size()-1;++i,++j){
            if(nums[i]==nums[i+1]){
                cnt++;
            }
            else
                cnt=0;
            swap(nums[i],nums[j]);
            if(cnt>=2)--j;
        }
        swap(nums[i],nums[j]);
        return j+1;
    }
};