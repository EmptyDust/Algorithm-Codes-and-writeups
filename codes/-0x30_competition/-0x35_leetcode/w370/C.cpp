#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n=values.size();
        vector<vector<long long>> mp(n);
        for(auto k:edges){
            mp[k[0]].push_back(k[1]);
            mp[k[1]].push_back(k[0]);
        }
            
        
        //for(int num:mp[4])cout<<num<<" ";
        //cout<<endl;
        
        function<long long(int,int)> dp = [&](int i,int par) -> long long{
            //cout<<i<<"value:"<<values[i]<<endl;
            if(mp[i].size()==1&&mp[i][0]==par) return values[i];
            long long sum=0;
            for(int j=0;j<mp[i].size();++j){
                if(mp[i][j]==par)continue;
                sum+=dp(mp[i][j],i);
            }
            //cout<<i<<":"<<sum<<endl;
            //cout<<i<<":"<<(sum<values[i]?sum:values[i])<<endl;
            return sum<values[i]?sum:values[i];
        };
        long long ans = -dp(0,-1);
        for(long long num:values)
            ans+=num;
        return ans;
    }
};