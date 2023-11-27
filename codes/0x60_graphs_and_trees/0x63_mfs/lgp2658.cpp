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

class MS//并查集
{
private:
    vector<int> vt;
public:
    MS(int n){
        vt.resize(n);
        for(int i=0;i<n;++i){
            vt[i]=i;
        }
    }
    int get_root(int x){
        return vt[x]=(vt[x]==x?x:get_root(vt[x]));
    }
    void merge(edge t,int n){
        vt[get_root(t.a.x*n+t.a.y)]=vt[get_root(t.b.x*n+t.b.y)];
    }
};

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
    MS* ms = new MS(m*n);
    for(edge tmp:edges){
        ms->merge(tmp,m);
        int k = ms->get_root(sign[0].x*m+sign[0].y);
        bool flag=true;
        for(int i=1;i<s;++i){
            if(k != ms->get_root(sign[i].x*m+sign[i].y)){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<tmp.weight;
            break;
        }
    }

    return 0;
}