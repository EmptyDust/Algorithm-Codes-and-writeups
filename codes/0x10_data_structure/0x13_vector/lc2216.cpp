#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size()-1;i+=2){
            if(nums[i]==nums[i+1])
                {++sum;--i;}
        }
        if((nums.size()-sum)&1)
            ++sum;
        return sum;
    }
};