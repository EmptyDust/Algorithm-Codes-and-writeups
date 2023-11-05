#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> mp(n);
        vector<bool> ans(n,false);
        int a=-1;
        for(auto k:edges){
            mp[k[1]].push_back(k[0]);
        }
        for(int i=0;i<n;++i){
            vector<int> temp;
            if(ans[i])continue;
            ans[i]=true;
            if(!mp[i].empty()){
                for(int j=0;j<mp[i].size();++j){
                    temp.push_back(mp[i][j]);
                }
                while(!temp.empty()){
                    int f = temp.back();
                    temp.pop_back();
                    //cout<<f;
                    if(ans[f])continue;
                    ans[f]=true;
                    if(mp[f].empty()){
                        //cout<<f<<1<<endl;
                        if(a==-1)a=f;
                        else return -1;
                    }
                    for(int j=0;j<mp[f].size();++j){
                        temp.push_back(mp[f][j]);
                    }
                }
            }
            else{
                //cout<<i<<2<<endl;
                if(a==-1)a=i;
                else return -1;
            }
        }
        return a;
    }
};