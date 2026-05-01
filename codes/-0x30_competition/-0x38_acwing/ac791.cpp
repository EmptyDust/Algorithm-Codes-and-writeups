#include <bits/stdc++.h>
using namespace std;
//高精度加法
int main(){
    string s1,s2;
    cin>>s1>>s2;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int pre=0;
    vector<int> ans;
    for(int i=0;i<s1.length()||i<s2.length();++i){
        int a=pre;
        if(i<s1.length())
            a+=s1[i]-'0';
        if(i<s2.length())
            a+=s2[i]-'0';
        ans.push_back(a%10);
        pre=a/10;
    }
    if(pre>0)ans.push_back(pre);
    for(int i=ans.size()-1;i>=0;--i)
        cout<<ans[i];
    return 0;
}