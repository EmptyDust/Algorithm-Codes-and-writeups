#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int j,t;
        j=0;
        t=cardPoints.size()-1;
        int ans=0,sum=0;
        for(int i=0;i<k;++i)
            sum+=cardPoints[i];
        ans=sum;
        for(int i=0;i<k;++i,--t){
            sum+=cardPoints[t];
            sum-=cardPoints[k-i-1];
            ans=max(ans,sum);
        }
        return ans;
    }
};