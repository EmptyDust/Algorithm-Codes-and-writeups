#include <bits/stdc++.h>
#define int long long 
using namespace std;

const string lenovo="lenovo";
/*
int lastlenovo(string str){
    if(str.length()<6)return 0;
    int i=-1,j=-1,ans=-1;
    while(i<(int)str.length()){
        if(j==-1||lenovo[j]==str[i]){
            ++i;++j;
            if(j==6){
                ans=i-j;
                j=0;
            }
        }
        else 
            j=-1;
        cout<<j<<" ";
    }
    cout<<endl;
    return ans+1;
}
*/

/*
int lastlenovo(string str){
    if(str.length()<6)return 0;
    int ans=0;
    int n=str.size();
    for(int i=0, j=0; i<n; ++i) {
        if (str[i]!=lenovo[j]) j=0;
        if (str[i]==lenovo[j]) j++;
        if (j==6) {
            ans=i-j+2;
            j=0;
        }
    }
    return ans;
}
*/

int lastlenovo(string str){
    auto ans=str.rfind("lenovo")+1;
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
            flag--;
            if(temp->next[ch-'a'])
                temp=temp->next[ch-'a'];
            else
                temp=temp->next[ch-'a']=new Trie();
            if(flag<=0){temp->fcnt++;}//cout<<ch;
        }
        //cout<<endl;
    }
    int qus(string str){
        Trie* temp = this;
        for(char ch:str){
            if(temp->next[ch-'a']){
                temp=temp->next[ch-'a'];
                //cout<<temp->fcnt;
            }
            else
                return 0;
        }
        //cout<<endl;
        return temp->fcnt;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Trie* root=new Trie();
    int n;cin>>n;
    int sum=0;
    while(n--){
        int u;string t;
        cin>>u>>t;
        if(u==1){
            int lst = lastlenovo(t);
            //cout<<lst<<endl;
            if(lst==0)continue;
            root->insert(t,lst);
            ++sum;
        }
        else{
            //cout<<root->qus(t)<<endl;
            cout<<sum-root->qus(t)<<'\n';
        }
    }
    return 0;
}