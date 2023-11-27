#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n);
        for(int i=n-1;i>=0;--i){
            int t=INT_MAX;
            for(int j=i+1;j<=i*2+2;++j){
                if(j>=n){
                    t=0;
                    break;
                }
                t=min(t,dp[j]);
            }
            dp[i]=prices[i]+t;
        }
        return dp[0];
    }
};