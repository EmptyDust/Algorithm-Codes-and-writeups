#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;cin>>n;
    int ab[26];
    while(n--){
        int len;cin>>len;
        string s;cin>>s;
        for(int i=0;i<26;++i)ab[i]=0;
        for(char ch:s){
            ab[ch-'a']++;
        }
        int mx = *max_element(ab,ab+26);
        int ans;
        if(mx<=len-mx)
            ans=0;
        else
            ans=2*mx-len;
        if(len&1){
            cout<<max((int)1,ans)<<'\n';
        }
        else
            cout<<ans<<'\n';
    }
    return 0;
}
