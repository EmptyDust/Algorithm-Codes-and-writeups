#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN = 100010;
int a[MAXN];
int b[MAXN];
int zba[MAXN];
int zbb[MAXN];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    vector<int> ls[MAXN];
    int n,m,l;
    cin>>n>>m>>l;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<m;++i)cin>>b[i];
    for(int i=0;i<l;++i){
        vector<int> tmp(2);
        cin>>tmp[0]>>tmp[1];
        if(tmp[0]>tmp[1])swap(tmp[0],tmp[1]);
        ls[i]=tmp;
    }
    sort(ls,ls+l,[](vector<int> x,vector<int> y){
        if(a[x[0]]==a[y[0]])
            b[x[1]]>b[y[1]];
        return a[x[0]]>a[y[0]];
    });
    iota(zba,zba+n,0);
    iota(zbb,zbb+m,0);
    sort(zba,zba+n,[](int x,int y){return a[x]>a[y];});
    sort(zbb,zbb+m,[](int x,int y){return b[x]>b[y];});
    

    return 0;
}
