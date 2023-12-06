#include <bits/stdc++.h>
#define int long long 
using namespace std;
int x,y;
char mp[505][505];

struct point{
    int x;
    int y;
    bool operator <(point t){
        if(x==t.x)
            return y<t.y;
        return x<t.x;
    }
    bool operator ==(point t){
        return (x==t.x&&y==t.y);
    }
};

struct query
{
    int mode;
    char par;//U上D下L左R右
    point a;
    point b;
    bool operator <(query x){
        if(a==x.a)
            return b<x.b;
        return a<x.a;
    }
};

inline bool check2(query t){
    return mp[t.a.x][t.a.y]!='#'&&mp[t.b.x][t.b.y]!='#';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>x>>y;
    while(x!=0||y!=0){
        query start;
        for(int i=0;i<x;++i)
            for(int j=0;j<y;++j){
                cin>>mp[i][j];
                if(mp[i][j]=='X'){
                    start.mode++;
                    if(start.mode==1)
                        start.a={i,j};
                    if(start.mode==2)
                        start.b={i,j};
                }
            }
        queue<query> q;
        q.push(start);
        while(!q.empty()){
            auto cut = q.front();
            if(cut.mode==1){
                point cutp = cut.a;
                query ty;
                ty.a={cutp.x+1,cutp.y};
                ty.b={cutp.x+2,cutp.y};
                if(cut.par!='U'&&check2(ty)){
                    ty.mode=2;
                    ty.par='D';
                    q.push(ty);
                }
                ty.a={cutp.x-1,cutp.y};
                ty.b={cutp.x-2,cutp.y};
                if(cut.par!='D'&&check2(ty)){
                    ty.mode=2;
                    ty.par='U';
                    q.push(ty);
                }
                ty.a={cutp.x,cutp.y+1};
                ty.b={cutp.x,cutp.y+2};
                if(cut.par!='R'&&check2(ty)){
                    ty.mode=2;
                    ty.par='L';
                    q.push(ty);
                }
                ty.a={cutp.x,cutp.y-1};
                ty.b={cutp.x,cutp.y-2};
                if(cut.par!='L'&&check2(ty)){
                    ty.mode=2;
                    ty.par='R';
                    q.push(ty);
                }
            }
            else{
                
            }
            q.pop();
        }
        cin>>x>>y;
    }
    return 0;
}