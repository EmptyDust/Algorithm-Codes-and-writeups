#include <bits/stdc++.h>
#define int long long
#define MAXN 1000000
using namespace std;

int nums[MAXN];
int tree[4*MAXN];
int lazy[4*MAXN];

int setUp(int l,int r,int i = 1){
    lazy[i]=0;
    if(l==r)
        return tree[i]=nums[l];
    int mid = l+r>>1;
    return tree[i]=setUp(l,mid,i*2)+setUp(mid+1,r,i*2+1);
}

inline void push_down(int i,int l,int r){
    int mid = l+r>>1;
    lazy[i*2] += lazy[i];
    lazy[i*2+1] += lazy[i];
    tree[i*2] += lazy[i] * (mid-l+1);
    tree[i*2+1] += lazy[i] * (r-mid);
    lazy[i] = 0;
}

void update(int l,int r,int ql,int qr,int d,int i = 1){
    if(ql>r||qr<l)
        return;
    if(ql<=l&&r<=qr){
        tree[i]+=(r-l+1)*d;
        if(l<r)
            lazy[i]+=d;
    }
    else{
        int mid = l+r>>1;
        push_down(i,l,r);
        update(l,mid,ql,qr,d,i*2);
        update(mid+1,r,ql,qr,d,i*2+1);
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

int query(int l,int r,int ql,int qr,int i = 1){
    if(ql>r||qr<l)
        return 0;
    if(ql<=l&&r<=qr)
        return tree[i];
    else{
        int mid = l+r>>1;
        push_down(i,l,r);
        return query(l,mid,ql,qr,i*2)+query(mid+1,r,ql,qr,i*2+1);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>nums[i];
    setUp(1,n);
    while(m--){
        int t,x,y;
        cin>>t>>x>>y;
        if(x>y)swap(x,y);
        if(t==1){
            int k;cin>>k;
            update(1,n,x,y,k);
        }
        else{
            cout<<query(1,n,x,y)<<'\n';
            /*
            for(int i=1;i<4*n;++i)cout<<tree[i]<<' ';
            cout<<'\n';
            for(int i=1;i<4*n;++i)cout<<lazy[i]<<' ';
            cout<<'\n';
            */
        }
    }
    return 0;
}