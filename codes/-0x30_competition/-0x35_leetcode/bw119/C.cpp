#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i, j;
        i = j = 0;
        int n = nums.size();
        map<int, int> mp;
        int ans = 0;
        for (int i = 0;i < n;++i) {
            mp[nums[i]]++;
            while (mp[nums[i]] > k) {
                mp[nums[j]]--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};