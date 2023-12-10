#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp1, mp2;
        for (int num : nums1)mp1[num]++;
        for (int num : nums2)mp2[num]++;
        int a = 0, b = 0;
        for (int i = 0;i < nums1.size();++i) {
            if (mp2[nums1[i]] != 0)
                a++;
        }
        for (int i = 0;i < nums2.size();++i) {
            if (mp1[nums2[i]] != 0)
                b++;
        }
        return { a,b };
    }
};