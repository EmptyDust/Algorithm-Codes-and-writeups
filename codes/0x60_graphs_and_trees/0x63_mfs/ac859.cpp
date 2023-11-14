#include <bits/stdc++.h>
#define int long long
using namespace std;

struct edge
{
    int u;
    int v;
    int w;
};

signed main(){
    int n,m;
    cin>>n>>m;
    vector<edge> mp(m);
    for(int i=0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        mp[i]={u,v,w};
    }
    sort(mp.begin(),mp.end(),[](edge a,edge b)->bool{
        return a.w<b.w;
    });
    vector<int> ds(n,0);
    for(int i=0;i<n;++i)
        ds[i]=i;
    function<int(int)> get_root = [&](int a)->int{
        return ds[a]=(a==ds[a]?a:get_root(ds[a]));
    };
    int sum=0;
    for(int i=0;i<m;++i){
        edge k = mp[i];
        if(get_root(k.u-1)==get_root(k.v-1))
            continue;
        sum+=k.w;
        ds[get_root(k.u-1)]=get_root(k.v-1);
    }
    int k = get_root(0);
    for(int i=1;i<n;++i){
        if(get_root(i)!=k){
            cout<<"impossible";
            return 0;
        }
    }
    cout<<sum;
    return 0;
}