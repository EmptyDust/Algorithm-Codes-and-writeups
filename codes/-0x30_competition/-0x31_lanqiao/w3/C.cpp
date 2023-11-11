#include <bits/stdc++.h>
using namespace std;
signed main(){
    int T;cin>>T;
    map<char,int> mp;
    char ch[15]={'3','4','5','6','7','8','9','X','J','Q','K','A','2','M','F'};
    for(int i=0;i<15;++i){
      mp[ch[i]]=i;
    }
    while(T--){
      string a,b;
      cin>>a>>b;
      int x1=mp[a[0]],x2=mp[a[1]],y1=mp[b[0]],y2=mp[b[1]];
      if(x1<x2)swap(x1,x2);
      if(y1<y2)swap(y1,y2);
      if(x1==x2||x1==14&&x2==13){
        cout<<"ShallowDream"<<endl;
        continue;
      }
      if(y1==14&&y2==13){
        cout<<"Joker"<<endl;
        continue;;
      }
      if(x1<y1)cout<<"Joker"<<endl;
      else cout<<"ShallowDream"<<endl;
    }
    return 0;
}