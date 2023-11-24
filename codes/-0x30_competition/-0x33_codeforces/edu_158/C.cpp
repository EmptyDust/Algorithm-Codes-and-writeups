#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        int t;cin>>t;
        int tmp;cin>>tmp;
        int mx=tmp,mn=tmp;
        for(int i=1;i<t;++i){
            cin>>tmp;
            mx=max(mx,tmp);
            mn=min(mn,tmp);
        }
        int g=mx-mn,cnt=0;
        while(g){
            cnt++;
            g>>=1;
        }
        cout<<cnt<<'\n';

        if(cnt<=t){
            if(cnt==0)continue;
            for(int i=0;i<cnt;++i){
                if(mx%2==0&&mn%2==1){
                    cout<<1<<' ';
                    mx++;mn++;
                }
                else{
                    cout<<0<<' ';
                }
                mx>>=1,mn>>=1;
            }
            cout<<'\n';
        }
    }
    return 0;
}