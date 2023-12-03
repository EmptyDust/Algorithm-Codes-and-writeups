#include <bits/stdc++.h>
//#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int cnt=0;
    for(int i=0;i<1000;++i){
        int tmp=i,sum2=0,sum8=0;
        while(tmp){
            sum2+=tmp%2;
            tmp/=2;
        }
        tmp=i;
        while(tmp){
            sum8+=tmp%8;
            tmp/=8;
        }
        if(sum2==sum8)
            cout<<cnt<<':'<<i<<endl;
    }

    return 0;
}