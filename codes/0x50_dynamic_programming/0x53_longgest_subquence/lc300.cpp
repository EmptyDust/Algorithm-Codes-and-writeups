#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;++i){
            for(int j=i-1;j>=0;--j){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        for(int k:dp)cout<<k<<" ";
        cout<<endl;
        return *max_element(dp.begin(), dp.end());
    }
};
/*优化算法，
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),len=1;
        if(nums.empty())return 0;
        vector<int> d(n+1,0);
        d[len]=nums[0];
        for(int i=1;i<n;++i){
            if(d[len]<nums[i]){
                d[++len]=nums[i];
            }
            else{
                int l=1,r=len,pos=0;
                while(l<=r){
                    int m=(l+r)>>1;
                    if(d[m]<nums[i]){
                        l=m+1;
                        pos=m;
                    }
                    else r=m-1;
                }
                d[pos+1]=nums[i];
            }
        }
        return len;
    }
};
*/