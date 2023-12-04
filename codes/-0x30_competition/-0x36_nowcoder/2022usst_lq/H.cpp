#include <bits/stdc++.h>
#define int long long
using namespace std;
struct edge
{
    int u;
    int v;
    int d;
};

signed main(){
    int n,s;
    cin>>n>>s;
    vector<int> value(n,0);
    for(int i=1;i<n;++i)cin>>value[i];
    vector<edge> edges(n-1);
    for(int i=0;i<n-1;++i){
        cin>>edges[i].u>>edges[i].v>>edges[i].d;
        edges[i].u--;
        edges[i].v--;
    }
    vector<int> ds(n);
    for(int i=0;i<n;++i)ds[i]=i;
    sort(edges.begin(),edges.end(),[](edge a,edge b)->bool{
        return a.d<b.d;
    });
    function<int(int)> get_root = [&](int a)->int{
        return ds[a]=(a==ds[a]?a:get_root(ds[a]));
    };
    for(int i=0;i<n-1;++i){
        int fa=get_root(edges[i].u),fb=get_root(edges[i].v);
        if(fa==fb)continue;
        //for(int num:ds)cout<<num<<" ";
        //cout<<endl;
        ds[fa]=fb;
        value[fb]+=value[fa];
        if(value[get_root(0)]>=s){
            //for(int num:ds)cout<<num<<" ";
            //cout<<endl;
            //for(int num:value)cout<<num<<" ";
            //cout<<endl;
            cout<<edges[i].d;
            return 0;
        }
    }
    return 0;
}
/*#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,s;
    cin>>n>>s;
    vector<int> value(n,0);
    vector<vector<int>> lj(n+1,vector<int>(n,-1));
    for(int i=1;i<n;++i)cin>>value[i];
    for(int i=1;i<n;++i){
        int u,v,d;
        cin>>u>>v>>d;
        lj[u-1][v-1]=d;
        lj[v-1][u-1]=d;
    }
    int ans=INT_MAX;
    function<int(int,int,int,int)> dp = [&](int root,int par,int v,int w)->int{
        if(v>=s)return w;
        if(w>=ans)return INT_MAX;
        int ret = INT_MAX;
        for(int i=1;i<n;++i) {
            if(i==par)continue;
            if(lj[root][i]!=-1){
                ret = min(ret,dp(i,root,v+value[i],max(w,lj[root][i])));
            }
        }
        return ans=ret;
    };
    cout<<dp(0,-1,0,0);
    return 0;
}*/