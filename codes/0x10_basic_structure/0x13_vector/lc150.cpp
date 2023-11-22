#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int k[100000],i=0;
        for(auto str:tokens){
            if(str=="+"){
                k[i-2]=k[i-1]+k[i-2];
                --i;
                continue;
            }
            else if(str=="-"){
                k[i-2]=k[i-2]-k[i-1];
                --i;
                continue;
            }
            else if(str=="*"){
                k[i-2]=k[i-2]*k[i-1];
                --i;
                continue;
            }
            else if(str=="/"){
                k[i-2]=k[i-2]/k[i-1];
                --i;
                continue;
            }
            k[i++]=toInt(str);
        }
        return k[0];
    }
    int toInt(string str){
        int ans=0;
        bool f=true;
        for(char ch:str){
            if(ch=='-'){
                f=false;
                continue;
            }
            ans*=10;
            ans+=ch-'0';
        }
        if(!f)ans*=-1;
        return ans;
    }
};