#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        int k;cin>>k;
        vector<int> mp(10,0);
        while(k--){
            int temp;cin>>temp;
            mp[temp]++;
        }
        //for(int num:mp)cout<<num<<endl;
        int a=mp[8]+mp[5]+mp[2];
        int b=mp[7]+mp[4]+mp[1];
        
        bool flag=false;
        int t=min(a%3,b%3),p=max(a%3,b%3);
        int at=t+a/3*3,bt=t+b/3*3;
        if(a%3==2&&b%3==0&&b>=3){
            bt--;
            at+=2;
        }
        if(b%3==2&&a%3==0&&a>=3){
            at--;
            bt+=2;
        }
        
        
        bool f=false;
        for(int i=9;i>0;--i){
            if(i%3==0)
                while(mp[i]--){cout<<i;f=true;}
            if(i%3==1)
                while(bt>0&&mp[i]-->0){cout<<i;bt--;f=true;}
            if(i%3==2)
                while(at>0&&mp[i]-->0){cout<<i;at--;f=true;}
        }
        if(!f){
            if(mp[0]==0)cout<<-1;
            else cout<<0;
        }
        else while(mp[0]--)cout<<0;
        cout<<'\n';
    }
    return 0;
}