#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int s1 = nums1.size();
      int s2 = nums2.size();
      if(nums1.empty()){
        if(s2%2){
          return nums2[s2/2];
        }else{
          return (nums2[s2/2]+nums2[s2/2-1])/2.0;
        }
      }
      if(nums2.empty()){
        if(s1%2){
          return nums1[s1/2];
        }else{
          return (nums1[s1/2]+nums1[s1/2-1])/2.0;
        }
      }

      int sum = s1+s2;
      int count=0;
      double temp,temp2;
      auto a = nums1.begin();
      auto b = nums2.begin();
      while(a!=nums1.end()||b!=nums2.end()){
        if(a==nums1.end()){
          temp=*b;
          b++;
        }
        else if(b==nums2.end()){
          temp=*a;
          a++;
        }
        else if(*a<=*b){
          temp=*a;
          a++;
        }
        else{
          temp=*b;
          b++;
        }
        count++;
        if(sum&1){
            if(count==sum/2+1)
                return temp;
        }
        else{
            if(count==sum/2)
                temp2=temp;
            if(count==sum/2+1)
                return (temp+temp2)/2.0;
        }
      }
      return (temp+temp2)/2.0;
    }
};