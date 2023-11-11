#include <bits/stdc++.h>
using namespace std;

int main(){
    #define int long long
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    vector<int> dp(b+1,0);
    function<bool(int,int)> in = [&](int c,int d)-> bool{
        if(c==x&&d==y)return true;
        int d1=abs(x-c)+abs(y-d);
        int d2=(x-c)*(x-c)+(y-d)*(y-d);
        return d1==3&&d2==5;
    };
    dp[0]=1;
    for(int i=0;i<=a;++i){
        if(in(i,0))
            dp[0]=0;
        for(int j=1;j<=b;++j){
            if(in(i,j))
                dp[j]=0;
            else
                dp[j]+=dp[j-1];
        }
    }
    cout<<dp[b]<<endl;
    return 0;
}