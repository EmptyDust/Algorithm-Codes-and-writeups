#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 10005;
int mp[MAXN][4];

signed main(){
    int n;cin>>n;
    for(int i=0;i<n;++i)
        cin>>mp[i][0]>>mp[i][1]>>mp[i][2]>>mp[i][3];
    int x,y;cin>>x>>y;
    int ans=-1;
    for(int i=0;i<n;++i){
        if(x>=mp[i][0]&&x<=mp[i][0]+mp[i][2]&&y>=mp[i][1]&&y<=mp[i][1]+mp[i][3])
            ans=i+1;
    }
    cout<<ans;
    return 0;
}