#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st1, st2, st3;
        for (int i = 0;i < n;++i) {
            while (!st1.empty() && nums[st1.top()] < nums[i]) {
                ans[st1.top()] = nums[i];
                st1.pop();
            }
            while (!st2.empty() && nums[st2.top()] < nums[i]) {
                st3.push(st2.top());
                st2.pop();
            }
            while (!st3.empty()) {
                st1.push(st3.top());
                st3.pop();
            }
            st2.push(i);
        }
        return ans;
    }
};