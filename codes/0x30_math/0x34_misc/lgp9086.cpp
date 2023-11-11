#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;n<<=1;
        int sum=0,num;
        while(n--){
            cin>>num;
            sum+=num&1;
        }
        cout<<abs(sum&1)<<endl;
    }
    return 0;
}