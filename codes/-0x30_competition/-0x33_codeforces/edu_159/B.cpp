#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;cin>>n;
    while(n--){
        int a,p,l,t;
        cin>>a>>p>>l>>t;
        if(a==1){
            cout<<0<<'\n';
            continue;
        }
        int sum=0,cnt=0;
        bool f=false;
        int pt=(a-1)/7+1;
        if(pt*t+(pt+1)/2*l<p){
            sum+=pt*t+(pt+1)/2*l;
            cnt+=(pt+1)/2;
        }
        else{
            cout<<a-(p-1)/(2*t+l)-1<<endl;
            continue;
        }
        if(sum<p)
            cnt+=(p-sum-1)/l+1;
        cout<<a-cnt<<'\n';
    }
    return 0;
}
