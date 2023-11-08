#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> choosed;
        function<void(vector<int>)> f = [&](vector<int>)-> void{
            if(choosed.size()==nums.size()){
                ans.push_back(choosed);
                return;
            }
            for(int i=0;i<n;++i){
                if(!count(choosed.begin(),choosed.end(),nums[i])){
                    choosed.push_back(nums[i]);
                    f(choosed);
                    choosed.pop_back();
                }
            }
            return;
        };
        f(choosed);
        return ans;
    }
};