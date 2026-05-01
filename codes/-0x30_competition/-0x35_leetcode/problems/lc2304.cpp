#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ans=0,n=grid[0].size();
        vector<int> temp(grid[0]);
        vector<int> dp(n);
        for(int i=1;i<grid.size();++i){
            for(int j=0;j<n;++j){
                int t = grid[i][j];
                int m = INT_MAX;
                for(int k=0;k<n;++k){
                    m=min(m,moveCost[grid[i-1][k]][j]+temp[k]);
                }
                dp[j]=m+t;
            }
            temp=dp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};