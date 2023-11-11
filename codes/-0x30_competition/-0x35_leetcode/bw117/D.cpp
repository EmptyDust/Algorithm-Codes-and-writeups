#include <bits/stdc++.h>
#define int long long
using namespace std;

#define wp struct WP
struct WP{
    int i;
    int j;
    int value;
    bool operator() (wp a, wp b) 
    {
        return a.value > b.value;
    }
};

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<wp, vector<wp>, WP> pq;
        int m=values.size(),n=values[0].size();
        for(int i=0;i<m;++i)
            pq.push({i,n-1,values[i][n-1]});
        long long sum=0;
        long long d=1;
        while(!pq.empty()){
            wp u = pq.top();
            pq.pop();
            sum+=u.value*d;
            d++;
            if(u.j!=0)
                pq.push((wp){u.i,u.j-1,values[u.i][u.j-1]});
        }
        return sum;
    }
};