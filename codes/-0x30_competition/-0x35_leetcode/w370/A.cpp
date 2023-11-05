#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int i=0;
        for(int j=0;j<grid[0].size();++j){
            if(i==j)continue;
            if(!grid[i][j]){
                i=j;
                j=0;
            }
        }
        return i;
    }
};