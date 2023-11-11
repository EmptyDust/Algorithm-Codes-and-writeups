#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2000005;
signed main(){
    string s;cin>>s;
    int st=0;
    char ans[MAXN];
    int i=0;
    for(char ch:s){
        ans[i]=ch;
        if(i>=2&&ans[i-2]=='A'&&ans[i-1]=='B'&&ans[i]=='C')
            i-=3;
        ++i;
    }
    if(i>=3&&ans[i-3]=='A'&&ans[i-2]=='B'&&ans[i-1]=='C')
        i-=3;
    string ret;
    for(int j=0;j<i;++j)ret+=ans[j];
    cout<<ret;
    return 0;
}