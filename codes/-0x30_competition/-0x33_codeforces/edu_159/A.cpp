#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;cin>>n;
    while(n--){
        int t;cin>>t;
        string s;
        cin>>s;
        int cnt0=0,cnt1=0;
        for(char ch:s){
            if(ch=='0'){
                cnt0++;
            }
            else
                cnt1++;
        }
        if(cnt0==0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
