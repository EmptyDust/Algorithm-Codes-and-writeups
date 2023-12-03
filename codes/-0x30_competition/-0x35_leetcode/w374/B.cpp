#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        int ans=0;
        long long t=1,sum=0;
        for(int i=0;i<coins.size();++i){
            while(coins[i]>t){
                ans++;
                sum+=t;
                //cout<<'t'<<t<<' '<<coins[i]<<endl;
                t*=2;
            }
            sum+=coins[i];
            t=sum+1;
        }
        //cout<<sum;
        while(target>=t){
            ans++;
            t*=2;
        }
        return ans;
    }
};