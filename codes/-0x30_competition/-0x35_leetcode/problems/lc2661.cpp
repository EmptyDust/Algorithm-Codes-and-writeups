#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>> mp;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                mp[mat[i][j]]={i,j};
        int ans;
        vector<int> l(m),h(n);
        for(ans=0;ans<arr.size();++ans){
            int f = mp[arr[ans]].first;
            int s = mp[arr[ans]].second;
            l[f]++;
            h[s]++;
            if(l[f]==n||h[s]==m)return ans;
        }
        return -1;
    }
};