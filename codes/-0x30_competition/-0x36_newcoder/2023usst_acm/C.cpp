#include <bits/stdc++.h>
#define int long long 
using namespace std;

const string lenovo="lenovo";

int lastlenovo(string str){
    if(str.length()<6)return -1;
    int i=0,j=0,ans=-1;
    while(i<str.length()){
        if(j==-1||lenovo[j]==str[i]){
            ++i;++j;
            if(j==6){
                ans=i-j;
                j=0;
            }
        }
        else 
            j=-1;
    }
    return ans;
}

class Trie{
    private:
    int fcnt = 0;
    Trie* next[26];
    public:
    void insert(string str,int flag){
        Trie* temp = this;
        for(char ch:str){
            if(flag--==0)temp->fcnt++;
            if(temp->next[ch-'a'])
                temp=temp->next[ch-'a'];
            else
                temp=temp->next[ch-'a']=new Trie();
        }
    }
    int qus(string str){
        int ans=0;
        
        return ans;
    }
};

signed main(){
    
    string str;
    cin>>str;
    Trie* root=new Trie();
    root->insert(str,lastlenovo(str));
    return 0;
}