#include <bits/stdc++.h>
//#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int m=36;
    while(m--){
        int tmp;cin>>tmp;
        int cnt=0;
        for(int i=1;i<=sqrt(tmp);++i){
            if(tmp%i==0){
                cnt++;
            }
        }
        cnt*=2;
        if(tmp%(int)sqrt(tmp)==0)
            cnt--;
        cout<<tmp<<' '<<cnt;
    }

    return 0;
}