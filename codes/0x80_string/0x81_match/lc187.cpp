#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int L=10;
        vector<string> ans;
        unordered_map<string, int> cnt;
        int n = s.length();
        for(int i=0;i<=n-L;++i){
            string sub = s.substr(i,L);
            if(++cnt[sub]==2)
                ans.push_back(sub);
        }
        return ans;
    }
};