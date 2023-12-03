#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int a,b;
    cin>>a>>b;
    int x,y,z;
    cin>>x>>y>>z;
    z++;
    if(z>b){
        z=1;
        y++;
        if(y>a){
            y=1;
            x++;
        }
    }
    cout<<x<<' '<<y<<' '<<z;
    return 0;
}