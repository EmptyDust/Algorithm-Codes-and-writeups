#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        int t,x;
        cin>>t>>x;
        int ans,tmp,tmp1;
        t--;
        cin>>ans;
        tmp=ans;
        while(t--){
            tmp1=tmp;
            cin>>tmp;
            ans=max(ans,tmp-tmp1);
        }
        ans=max(ans,(x-tmp)*2);
        cout<<ans<<'\n';
    }
    return 0;
}