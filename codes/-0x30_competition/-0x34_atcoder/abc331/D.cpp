#include <bits/stdc++.h>
#define int long long
using namespace std;
char tmp;
int mp[1111][1111];
int sum;
int n,q;

inline int calc(int x,int y){
    if(x<0||y<0)return 0;
    int ret=(x/n)*(y/n)*sum;
    ret+=(x/n)*mp[n-1][y%n];
    ret+=mp[x%n][n-1]*(y/n);
    ret+=mp[x%n][y%n];
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i = 0;i < n; ++i){
        for (int j = 0; j < n; ++j)
        {
            cin>>tmp;
            int ct;
            if(tmp=='B')
                ct=1;
            else
                ct=0;
            if(i>0)
                ct+=mp[i-1][j];
            if(j>0)
                ct+=mp[i][j-1];
            if(i>0&&j>0)
                ct-=mp[i-1][j-1];
            mp[i][j]=ct;
        }
    }
    sum=mp[n-1][n-1];
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<calc(c,d)-calc(c,b-1)-calc(a-1,d)+calc(a-1,b-1)<<'\n';
    }
    return 0;
}
