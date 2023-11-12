#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        sort(access_times.begin(),access_times.end());
        string k;int cnt;int n=access_times.size();
        for(int i=0;i<n;++i){
            if(k!=access_times[i][0]){
                cnt=1;
                k=access_times[i][0];
            }
            else{
                cnt++;
                if(cnt>=3){
                    int a = access_times[i][1][0]*1000+access_times[i][1][1]*100+access_times[i][1][2]*10+access_times[i][1][3];
                    int b = access_times[i-2][1][0]*1000+access_times[i-2][1][1]*100+access_times[i-2][1][2]*10+access_times[i-2][1][3];
                    if(a-b<100){
                        ans.push_back(access_times[i][0]);
                        while(i<n&&access_times[i][0]==k)++i;
                        --i;
                    }
                }
            }
        }
        return ans;
    }
};