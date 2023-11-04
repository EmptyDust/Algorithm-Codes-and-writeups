#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int x,y,k;
        cin>>x>>y>>k;
        if(y<=x) 
            cout<<x<<endl;//钥匙在左
        else 
            cout<<y+(y-x)-min(y-x,k)<<endl;//先取钥匙折返
    }
    return 0;
}