#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxn=1,maxm=1,cnt=1;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        for(int i=1;i<hBars.size();++i){
            if(hBars[i]==hBars[i-1]+1){
                cnt++;
                maxn=max(maxn,cnt);
            }
            else
                cnt=1;
        }
        cnt=1;
        for(int i=1;i<vBars.size();++i){
            if(vBars[i]==vBars[i-1]+1){
                cnt++;
                maxm=max(maxm,cnt);
            }
            else
                cnt=1;
        }
        int f=min(maxn,maxm)+1;
        return f*f;
    }
};