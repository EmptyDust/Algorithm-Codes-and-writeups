#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int temp=target[0]-1;
        while(temp--){ans.push_back("Push");ans.push_back("Pop");}
        for(int i=0;i<target.size()-1;++i){
            ans.push_back("Push");
            int temp=target[i+1]-target[i]-1;
            while(temp--){ans.push_back("Push");ans.push_back("Pop");}
        }
        if(target.size())
        ans.push_back("Push");
        return ans;
    }
};