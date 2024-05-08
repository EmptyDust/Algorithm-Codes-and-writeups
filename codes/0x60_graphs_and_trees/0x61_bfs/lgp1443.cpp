#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef struct point
{
    int x;
    int y;
}point;

signed main(){
    int n,m,x,y;
    cin>>m>>n>>x>>y;
    vector<vector<int>> mp(m,vector<int>(n,-1));//mp[m][n]

    queue<point> q;
    point t[8] = {{2,1},{2,-1},{1,2},{1,-2},{-2,1},{-2,-1},{-1,2},{-1,-2}};
    mp[x-1][y-1]=0;
    
    q.push({x-1,y-1});
    while(!q.empty()){
    	point f = q.front();
        for (int i = 0; i < 8; i++)
        {
        	int xt=f.x+t[i].x;
        	int yt=f.y+t[i].y;
            if(xt>=0&&yt>=0&&xt<m&&yt<n&&mp[xt][yt]==-1){
                mp[xt][yt]=mp[f.x][f.y]+1;
                q.push({xt,yt});
            }
        }
        q.pop();
    }
    
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cout<<mp[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}