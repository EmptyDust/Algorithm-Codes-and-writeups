#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int num;cin>>num;
    int cnt=1;
    for(int i=2;i<=num;++i){
        while(num%i==0){
            cnt++;
            num/=i;
            cout<<i<<' '<<num<<endl;
        }
    }
    cout<<cnt;
    return 0;
}
2 1010520910105209
3 336840303368403
3 112280101122801
3 37426700374267
17 2201570610251
131 16805882521
2857 5882353
5882353 1
8
*/
int jc(int x,int y){
    if(x>y)
        return x*jc(x-1,y);
    return x;
}
int c(int x,int y){
    if(y==0)return 1;
    return jc(x,x-y+1)/jc(y,1);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int ans=0;
    for(int i=0;i<=5;++i){
        int s=c(5,i);
        for(int j=0;j<=5-i;++j){
            ans+=c(5-i,j)*s;
        }
    }
    cout<<ans*10;
    return 0;
}
/*
3+6+1
*/