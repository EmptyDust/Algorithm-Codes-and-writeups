#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int T;cin>>T;
    while(T--){
        ll n;cin>>n;
        cout<<(n&1?"Yes":"No")<<endl;
    }
}

/*
void solution(){
    ll n;
    cin>>n;
    if(n==2){
        cout<<"No"<<endl;
        return;
    }
    if(n==1){
        cout<<"Yes"<<endl;
        return;
    }
    for(ll i=2;i<=sqrt(n);++i){
        while(n%i==0){
            if(i&1) n/=i;
            else {
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solution();
    }
    return 0;
}
*/