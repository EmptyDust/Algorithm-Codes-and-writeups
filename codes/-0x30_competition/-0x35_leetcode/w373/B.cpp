#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n=s.length(),cnt=0;
        for(int i=0;i<n;++i){
            int t=0;
            for(int j=i;j<n;++j){
                t+=isy(s[j]);
                int l=j-i+1;
                if(l%2==0&&t*2==l&&t*t%k==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    bool isy(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
    }
};