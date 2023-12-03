#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m,s,l;
    cin>>n>>s>>m>>l;
    int ans=INT_MAX;
    for(int i=0;i<=100/6+1;++i){
        for(int j=0;j<=100/8+1;++j){
            for(int k=0;k<=100/12+1;++k){
                if(i*6+j*8+k*12>=n)
                    ans=min(ans,i*s+j*m+k*l);
            }
        }
    }
    cout<<ans;
    return 0;
}