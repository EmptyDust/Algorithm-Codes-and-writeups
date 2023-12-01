#include <bits/stdc++.h>
using namespace std;

typedef struct point
{
    int x;
    int y;
}point;

typedef struct edge
{
    point a;
    point b;
    int weight;
    bool operator <(const edge &a){
        return weight<a.weight;
    }
}edge;


    vector<int> vt;

    void init(int n){
        vt.resize(n);
        for(int i=0;i<n;++i){
            vt[i]=i;
        }
    }
    int get_root(int x){
        return vt[x]=(vt[x]==x?x:get_root(vt[x]));
    }

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int m,n;
    cin>>m>>n;
    //输入边
    vector<vector<int>> mp(m,vector<int>(n));
    vector<edge> edges;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin>>mp[i][j];
            if(j>0){
                point a = {j,i};
                point b = {j-1,i};
                edges.push_back({a,b,abs(mp[i][j]-mp[i][j-1])});
            }
            if(i>0){
                point a = {j,i};
                point b = {j,i-1};
                edges.push_back({a,b,abs(mp[i][j]-mp[i-1][j])});
            }
        }
    }
    //
    vector<point> sign;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            int tmp;
            cin>>tmp;
            if(tmp==1)
                sign.push_back({j,i});
        }
    }
    
    sort(edges.begin(),edges.end());

    int s = sign.size();
    //kruskal
    init(m*n);
    for(int i=0;i<edges.size();++i){
        vt[get_root(edges[i].a.x*m+edges[i].a.y)]=vt[get_root(edges[i].b.x*m+edges[i].b.y)];
        //探测下一个或没有下一个时做
        if(i!=edges.size()-1&&edges[i+1].weight==edges[i].weight)
            continue;
        int k = get_root(sign[0].x*m+sign[0].y);
        bool flag=true;
        for(int j=1;j<s;++j){
            if(k != get_root(sign[j].x*m+sign[j].y)){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<edges[i].weight;
            break;
        }
    }

    return 0;
}