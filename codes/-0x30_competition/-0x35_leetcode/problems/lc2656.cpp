#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max=*max_element(nums.begin(),nums.end());
        return (max*2+k-1)*k/2;
    }
};