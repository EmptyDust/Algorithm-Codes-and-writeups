#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0, dp = 0, n = nums.size();
        for (int l = n - 1; l >= 0; l--) {
            if (nums[l] > threshold) {
                dp = 0;
            } else if (l == n - 1 || nums[l] % 2 != nums[l + 1] % 2) {
                dp++;
            } else {
                dp = 1;
            }
            if (nums[l] % 2 == 0) {
                res = max(res, dp);
            }
        }
        return res;
    }
};