#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int na = a.length();
        int nb = b.length();
        vector<int> ans;
        na--,nb--;
        bool in = false;
        while(na>=0||nb>=0){
            if(na<0){
                int t = b[nb]-'0'+in;
                ans.push_back(t%2);
                if(t==2)in=true;
                else in=false;
                nb--;
                continue;
            }
            if(nb<0){
                int t = a[na]-'0'+in;
                ans.push_back(t%2);
                if(t==2)in=true;
                else in=false;
                na--;
                continue;
            }
            int t = a[na]-'0'+b[nb]-'0'+in;
            ans.push_back(t%2);
            if(t>=2)in=true;
            else in=false;
            nb--;na--;
        }
        string ret;
        for(int num:ans) ret+=num?'1':'0';
        if(in)ret+='1';
        reverse(ret.begin(), ret.end());
        return ret;
    }
};