#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin>>n;
    int sum=0;
    while(n--){
      int w;
      cin>>w;
      int a1=w,a2=w,a3=w;
      if(w>=500)a1-=a1/10;
      if(w>=1000)a2-=150;
      if(w==1111)a3=0;
      else a3-=a3/20;
      sum+=min({a1,a2,a3});
    }
    cout<<sum;
    return 0;
}