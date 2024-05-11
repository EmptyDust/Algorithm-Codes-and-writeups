#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        int a=*max_element(nums.begin(), nums.end());
        int b=*min_element(nums.begin(), nums.end());
        if(a==b)return 0;
        int k1=count(nums.begin(), nums.end(),a);
        int k2=count(nums.begin(), nums.end(),b);
        return n-k1-k2;
    }
};