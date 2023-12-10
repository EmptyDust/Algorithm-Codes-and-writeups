#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        long long cnt = 0, ans = 0;
        queue<int> q;
        long long pre = 0;
        for (int i = 0;i < nums.size();++i) {
            if (nums[i] == mx) {
                q.push(i);
                if (q.size() >= k) {
                    ans += q.front() + 1;
                    pre = q.front() + 1;
                    q.pop();
                }
            }
            else {
                ans += pre;
            }
        }
        return ans;
    }
};