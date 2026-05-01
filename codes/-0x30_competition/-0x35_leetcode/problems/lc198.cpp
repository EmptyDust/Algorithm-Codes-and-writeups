#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size()+1;
        vector<int> gt(n);
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        gt[0]=0;
        gt[1]=nums[0];
        gt[2]=nums[1];
        for(int i=3;i<n;i++){
            gt[i]=max(gt[i-2],gt[i-3])+nums[i-1];
        }
        return max(gt[n-1],gt[n-2]);
    }
};