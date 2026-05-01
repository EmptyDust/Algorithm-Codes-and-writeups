#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;cin>>n;
    int i;
    for(i=1;n>0;++i){
        if(n<=i)
            break;
        else
            n-=i;
    }
    if(i&1)
        cout<<i+1-n<<'/'<<n;
    else
        cout<<n<<'/'<<i+1-n;
    return 0;
}