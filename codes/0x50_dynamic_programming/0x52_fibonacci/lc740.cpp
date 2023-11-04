#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
    map<int, int> rate;
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(1,vector<int>(2));
        int temp=nums[0];
        dp[0]={0,temp};
        int sum=0;
        for(int num:nums){
            if(num-1==temp){
                temp++;
                dp.push_back({0,temp});
            }
            if(num==temp){
                dp[dp.size()-1][0]++;
            }
            else{
                int k=dp.size();
                vector<int> p(k);
                p[0]=dp[0][0]*dp[0][1];
                if(k>1) p[1]=dp[1][0]*dp[1][1];
                if(k>2) p[2]=dp[2][0]*dp[2][1]+p[0];
                for(int i=3;i<dp.size();++i)
                    p[i]=max(p[i-3],p[i-2])+dp[i][0]*dp[i][1];
                if(k>1)
                    sum+=max(p[k-2],p[k-1]);
                else
                    sum+=p[k-1];
                temp=num;
                dp={{1,num}};
            }
        }
        for(auto k:dp)cout<<k[0]<<" "<<k[1]<<endl;
        int k=dp.size();
        vector<int> p(k);
        p[0]=dp[0][0]*dp[0][1];
        if(k>1) p[1]=dp[1][0]*dp[1][1];
        if(k>2) p[2]=dp[2][0]*dp[2][1]+p[0];
        for(int i=3;i<dp.size();++i)
            p[i]=max(p[i-3],p[i-2])+dp[i][0]*dp[i][1];
        if(k>1)
            sum+=max(p[k-2],p[k-1]);
        else
            sum+=p[k-1];
        return sum;
    }
};