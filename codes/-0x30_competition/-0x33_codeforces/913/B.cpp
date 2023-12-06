#include <bits/stdc++.h>
//#define int long long
using namespace std;
string s;
int Upper[1000005];
int Lower[1000005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;cin>>n;
    while(n--){
        int u=0,l=0;
        cin>>s;
        int len=s.length();
        for(int i=0;i<len;++i){
            if(s[i]=='b'){
                if(l>0)l--;
            }
            else if(s[i]=='B'){
                if(u>0)u--;
            }
            else{
                if(isupper(s[i]))
                    Upper[u++]=i;
                else
                    Lower[l++]=i;
            }
        }
        int i,j;
        string ans;
        i=j=0;
        while(i<l&&j<u){
            if(Lower[i]<Upper[j]){
                ans+=s[Lower[i]];
                ++i;
            }
            else{
                ans+=s[Upper[j]];
                ++j;
            }
        }
        while(i<l){
            ans+=s[Lower[i]];
            ++i;
        }
        while(j<u){
            ans+=s[Upper[j]];
            ++j;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
