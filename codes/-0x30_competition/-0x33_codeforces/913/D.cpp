#include <bits/stdc++.h>
#define int long long
using namespace std;
int mp[222222][2];
int t;

bool test(int ty){
    int l=0,r=0;
    for(int i=0;i<t;++i){
        l=max(l-ty,mp[i][0]);
        r=min(r+ty,mp[i][1]);
        if(r<l)
            return false;
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;cin>>n;
    while(n--){
        cin>>t;
        int r=INT_MIN,l=INT_MAX;
        for(int i=0;i<t;++i){
            cin>>mp[i][0]>>mp[i][1];
            l=min(l,mp[i][0]);
            r=max(r,mp[i][1]);
        }
        while(l<r){
            int mid = l+r>>1;
            if(test(mid)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        cout<<l<<endl;
    }
    return 0;
}