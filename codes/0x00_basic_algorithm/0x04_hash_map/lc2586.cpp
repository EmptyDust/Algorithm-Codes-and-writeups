#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        set<char> v = {'a','e','i','o','u'};
        int cnt=0;
        for(int i=left;i<=right;++i)
            if(v.count(words[i][0])&&v.count(words[i][words[i].size()-1]))
                cnt++;
        return cnt;
    }
};