#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnts(26, 0);
        for (char ch : word)cnts[ch - 'a']++;
        sort(cnts.begin(), cnts.end(), [&](int a, int b) {return a > b;});
        int ret = 0;
        for (int i = 0;i < 26;++i) {
            if (cnts[i] == 0)continue;
            else ret += (i / 8 + 1) * cnts[i];
        }
        return ret;
    }
};