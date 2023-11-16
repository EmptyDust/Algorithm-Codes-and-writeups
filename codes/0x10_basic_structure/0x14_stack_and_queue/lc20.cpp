#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        char t[10000];
        int i=0;
        for(char ch:s){
            if(ch==')'&&!(i>0&&t[i-1]=='('))return false;
            if(ch=='}'&&!(i>0&&t[i-1]=='{'))return false;
            if(ch==']'&&!(i>0&&t[i-1]=='['))return false;
            if(ch=='('||ch=='{'||ch=='[') t[i++]=ch;
            else --i;
        }
        
        return (i==0?true:false);
    }
};