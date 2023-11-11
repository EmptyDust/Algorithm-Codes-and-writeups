#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        
        long long cnt=0;
        for(int i=(0<n-limit*2?n-limit*2:0);i<=(n<limit?n:limit);++i){
            cnt+=(n-i<limit?n-i:limit)-(0<n-i-limit?n-i-limit:0)+1;
        }
        return cnt;
    }
};