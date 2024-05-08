#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 500000;
int n,m;
string str;

struct node
{
    char l;//左侧颜色
    char r;//右侧颜色
    int num;//颜色段数量
    char lazy='x';
    node operator +(node x){
        if(num==0)return x;
        if(x.num==0)return *this;
        int cut=num+x.num;
        if(r==x.l)
            cut--;
        return {l,x.r,cut};
    }
};
node tree[MAXN*4];

node set_up(int l=1,int r=n,int i=1){
    if(l==r){
        node* cut = &tree[i];
        cut->l=str[l-1];
        cut->r=str[l-1];
        cut->num=1;
        return tree[i];
    }
    int mid = l+r>>1;
    return tree[i] = set_up(l,mid,i*2)+set_up(mid+1,r,i*2+1);
}

inline void paint(int i,char x){
    tree[i].l=x;
    tree[i].r=x;
    tree[i].num=1;
    tree[i].lazy=x;
}

inline void push_down(int l,int r,int i){
    char ly = tree[i].lazy;
    if(ly=='x')
        return;
    paint(i*2,ly);
    paint(i*2+1,ly);
    tree[i].lazy='x';
}

node update(int ul,int ur,char x,int l=1,int r=n,int i=1){
    if(r<ul||ur<l)
        return tree[i];
    if(ul<=l&&r<=ur){
        paint(i,x);
        return tree[i];
    }
    int mid = l+r>>1;
    push_down(l,r,i);
    return tree[i] = update(ul,ur,x,l,mid,i*2)+update(ul,ur,x,mid+1,r,i*2+1);
}

node query(int ql,int qr,int l=1,int r=n,int i=1){
    if(r<ql||qr<l){
        node ret;
        ret.num=0;
        return ret;
    }
    int mid = l+r>>1;
    if(tree[i].lazy!='x'||ql<=l&&r<=qr)
        return tree[i];
    return query(ql,qr,l,mid,i*2)+query(ql,qr,mid+1,r,i*2+1);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cin>>str;
    set_up();
    while(m--){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)
            cout<<query(x,y).num<<'\n';
        else{
            char ch;
            cin>>ch;
            update(x,y,ch);
        }
    }
    return 0;
}
