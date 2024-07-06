#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m+n;
        --m,--n;
        while(n>=0){
            --i;
            if(m==-1){
                nums1[i]=nums2[n--];
                continue;
            }
            if(nums1[m]>nums2[n]){
                swap(nums1[m--],nums1[i]);
            }
            else{
                swap(nums2[n--],nums1[i]);
            }
        }
    }
};