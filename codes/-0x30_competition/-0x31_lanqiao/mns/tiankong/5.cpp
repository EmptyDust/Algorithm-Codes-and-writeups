#include <bits/stdc++.h>
//#define int long long
using namespace std;

int mp[30][40];
int cnt=0;
void t(int x,int y){
    if(mp[x][y]!=0)return;
    mp[x][y]=2;
    cnt++;
    if(x>0)
        t(x-1,y);
    if(y>0)
        t(x,y-1);
    if(x<30)
        t(x+1,y);
    if(y<40)
        t(x,y+1);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    for(int i=0;i<30;++i){
        for(int j=0;j<40;++j){
            cin>>mp[i][j];
        }
    }
    t(0,0);
    cout<<cnt;
    return 0;
}


