#include <bits/stdc++.h>
#define int long long
using namespace std;
bool isd(int a,int k){
    while(a){
        if(a%10!=k)return false;
        a/=10;
    }
    return true;
}
signed main(){
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;++i){
        int d;cin>>d;
        int k=i%10;
        if(isd(i,k)){
            while(d){
                if(isd(d,k))cnt++;
                d--;
            }
        }
    }
    cout<<cnt;
    return 0;
}