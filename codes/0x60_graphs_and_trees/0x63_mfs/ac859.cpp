#include <bits/stdc++.h>
#define int long long
using namespace std;

#define edge struct EDGE 
struct EDGE
{
    int u;
    int v;
    long long w;
};

signed main(){
    int n,m;
    cin>>n>>m;
    vector<edge> mp(m);
    for(int i=0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        mp[i]=(edge){u,v,w};
    }
    sort(mp.begin(),mp.end(),[](edge a,edge b)->bool{
        return a.w<b.w;
    });
    vector<bool> ds(n);
    for(int i=0;i<n;++i)ds[i]=i;
    function<int(int)> get_root = [&](int a)->int{
        return ds[a]=(a==ds[a]?a:get_root(ds[a]));
    };
    int sum=0;
    for(int i=0;i<m;++i){
        edge k = mp[i];
        if(get_root(k.u)==get_root(k.v))continue;
        sum+=k.w;
        ds[k.u]=k.v;
    }
    for(int i=0;i<n;++i)
        if(ds[i]!=ds[0]){
            cout<<"impossible";
            return 0;
        }
    cout<<sum;
    return 0;
}