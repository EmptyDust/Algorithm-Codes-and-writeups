#include <bits/stdc++.h>
//#define int long long
using namespace std;
int mp[1007][1007];

int o(int a,int b){
    if(a%b==0)return b;
    return o(b,a%b);
}
int cnt;
int n,m;
void f(int x,int y){
    int tmp=mp[x][y];
    mp[x][y]=-1;
    cnt++;
    //cout<<x<<y<<' '<<tmp<<endl;
    if(x>0&&mp[x-1][y]!=-1){
        if((mp[x-1][y]>tmp?o(mp[x-1][y],tmp):o(tmp,mp[x-1][y]))!=1){
            f(x-1,y);
        }
    }
    if(y>0&&mp[x][y-1]!=-1){
        if((mp[x][y-1]>tmp?o(mp[x][y-1],tmp):o(tmp,mp[x][y-1]))!=1){
            f(x,y-1);
        }
    }
    if(x<n-1&&mp[x+1][y]!=-1){
        if((mp[x+1][y]>tmp?o(mp[x+1][y],tmp):o(tmp,mp[x+1][y]))!=1){
            f(x+1,y);
        }
    }
    if(y<m-1&&mp[x][y+1]!=-1){
        if((mp[x][y+1]>tmp?o(mp[x][y+1],tmp):o(tmp,mp[x][y+1]))!=1){
            f(x,y+1);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>mp[i][j];

    int r,c;
    cin>>r>>c;
    cnt=0;
    f(r-1,c-1);
    cout<<cnt;
    return 0;
}


