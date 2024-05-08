#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t,tmp;cin>>t;

    while(t--){
        cin>>tmp;
        if(tmp==1) 
            cout<<1<<'\n';
        else 
            cout<<tmp-1<<'\n';
    }
    return 0;
}