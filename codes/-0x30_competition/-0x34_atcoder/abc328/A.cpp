#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,x;
    cin>>n>>x;
    int sum=0;
    while(n--){
        int num;
        cin>>num;
        if(num<=x){
            sum+=num;
        }
    }
    cout<<sum;
    return 0;
}