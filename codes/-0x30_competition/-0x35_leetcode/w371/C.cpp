#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int k1=nums1[n-1],k2=nums2[n-1];
        int op1=0,op2=0;
        for(int i=0;i<n;++i){
            if(min(k1,k2)<min(nums1[i],nums2[i])||max(k1,k2)<max(nums1[i],nums2[i]))return -1;
            if(!(k1>=nums1[i]&&k2>=nums2[i]))++op1;
            if(!(k2>=nums1[i]&&k1>=nums2[i]))++op2;
        }
        return min(op1,op2);
    }
};