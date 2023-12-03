#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        
        vector<int> ans;
        for(int i=1;i<mountain.size()-1;++i){
            if(mountain[i]>mountain[i-1]&&mountain[i]>mountain[i+1])
                ans.push_back(i);
        }
        return ans;
    }
};