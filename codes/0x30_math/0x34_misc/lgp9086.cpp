#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;n*=2;
        int sum=0,num;
        while(n--){
            cin>>num;
            sum+=num%2;
        }
        cout<<abs(sum%2)<<endl;
    }
    return 0;
}