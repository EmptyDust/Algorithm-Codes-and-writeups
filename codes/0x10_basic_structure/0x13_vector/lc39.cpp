#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=candidates.size();
        function<void(int,int)> f = [&](int t,int sum)->void{
            if(sum>target)return;
            if(sum==target)ans.push_back(temp);
            for(int i=t;i<n;++i){
                temp.push_back(candidates[i]);
                f(i,sum+candidates[i]);
                temp.pop_back();
            }
        };
        f(0,0);
        return ans;
    }
};