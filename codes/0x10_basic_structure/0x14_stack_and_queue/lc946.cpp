#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int k[1000];int i=0,j=0;
        for(int num:pushed){
            k[i++]=num;
            while(i>0&&k[i-1]==popped[j]){
                ++j;
                --i;
            }
        }
        return j==popped.size();
    }
};