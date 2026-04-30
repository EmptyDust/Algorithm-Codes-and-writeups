#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    char chs[8] = {'a','b','c','d','e','f','g','h'};
    int n;cin>>n;
    while(n--){
        string s;
        cin>>s;
        char ch1 = s[0];
        char ch2 = s[1];
        for(int i=1;i<=8;++i)if(i!=s[1]-'0'){
            cout<<ch1<<i<<'\n';
        }
        for(int i=0;i<8;++i)if(ch1!=chs[i]){
            cout<<chs[i]<<s[1]<<'\n';
        }
    }
    return 0;
}
