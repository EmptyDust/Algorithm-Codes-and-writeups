#include <bits/stdc++.h>
using namespace std;
int pos[5008];

signed main(){
    int L;cin>>L;
    int n;cin>>n;
    int temp;
    int ansmin1=-1,ansmin2=-1,ansmax=0;
    if(n==0){cout<<0<<' '<<0;return 0;}
    while(n--){
        cin>>temp;
        ansmax=max({ansmax,L+1-temp,temp});
        if(L+1-temp>temp){
            if(ansmin1==-1)ansmin1=temp;
            ansmin1=max(ansmin1,temp);
        }
        else{
            if(ansmin2==-1)ansmin2=L+1-temp;
            ansmin2=max(ansmin2,L+1-temp);
        }
    }
    int ansmin=max(ansmin1,ansmin2);
    if(ansmin1==-1)ansmin=ansmin2;
    if(ansmin2==-1)ansmin=ansmin1;

    cout<<ansmin<<' '<<ansmax;
    return 0;
}