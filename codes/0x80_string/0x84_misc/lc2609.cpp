#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans=0,cnt=0,l0=0;
        bool k = false;
        for(char ch:s){
            if(ch=='0'){
                if(k){
                    ans=max(ans,min(cnt,l0)*2);
                    cnt=0;
                    k=false;
                }
                cnt++;
            }
            if(ch=='1'){
                if(!k){
                    l0=cnt;
                    cnt=0;
                    k=true;
                }
                cnt++;
            }
        }
        cout<<l0;
        if(k)
            ans=max(ans,min(cnt,l0)*2);
        return ans;
    }
};