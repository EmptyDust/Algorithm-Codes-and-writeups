#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN=2e5+10;

int ls[MAXN<<6], rs[MAXN<<6], sum[MAXN<<6], nodetot;
void insert(int pos, int v, int l, int r, int &p) {
    if (!p) p=++nodetot;
    sum[p]+=v;
    if (l==r) return;
    int mid=(l+r)>>1;
    if (pos<=mid) insert(pos,v,l,mid,ls[p]);
    else insert(pos,v,mid+1,r,rs[p]);
}

#define lowbit(x) (x&(-(x)))
int root[MAXN], n, m;
void update(int p, int x, int v) {
    while (p<=n) insert(x,v,1,n,root[p]), p+=lowbit(p);
}
int lt[MAXN], ltot, rt[MAXN], rtot;
int a[MAXN], b[MAXN], tot;
void get_root(int p, int a[], int &tot) {
    tot=0;
    while (p)
        a[++tot]=root[p], p-=lowbit(p);
}
int query_kth(int l, int r, int k) {
    if (l==r) return l;
    int siz=0;
    for (int i=1; i<=rtot; ++i)
        siz+=sum[ls[rt[i]]];
    for (int i=1; i<=ltot; ++i)
        siz-=sum[ls[lt[i]]];
    int mid=(l+r)>>1;
    if (siz>=k) {
        for (int i=1; i<=ltot; ++i)
            lt[i]=ls[lt[i]];
        for (int i=1; i<=rtot; ++i)
            rt[i]=ls[rt[i]];
        return query_kth(l,mid,k);
    }
    for (int i=1; i<=ltot; ++i)
        lt[i]=rs[lt[i]];
    for (int i=1; i<=rtot; ++i)
        rt[i]=rs[rt[i]];
    return query_kth(mid+1,r,k-siz);
}

int get_kth(int l, int r, int k) {
    get_root(l-1,lt,ltot);
    get_root(r,rt,rtot);
    return query_kth(1,n,k);
}

int query_rank(int l, int r, int k) {
    if (l==r) return 0;
    int mid=(l+r)>>1, siz=0;
    if (k<=mid) {
        for (int i=1; i<=ltot; ++i)
            lt[i]=ls[lt[i]];
        for (int i=1; i<=rtot; ++i)
            rt[i]=ls[rt[i]];
        return query_rank(l,mid,k);
    }
    
    for (int i=1; i<=ltot; ++i)
        siz-=sum[ls[lt[i]]], lt[i]=rs[lt[i]];
    for (int i=1; i<=rtot; ++i)
        siz+=sum[ls[rt[i]]], rt[i]=rs[rt[i]];
    return siz+query_rank(mid+1,r,k);
}

int get_rank(int l, int r, int k) {
    get_root(l-1,lt,ltot);
    get_root(r,rt,rtot);
    return query_rank(1,n,k)+1;
}

void change(int pos, int x) {
    update(pos,a[pos],-1);
    update(pos,a[pos]=x,1);
}

int get_pre(int l, int r, int k) {
    int rank=get_rank(l,r,k)-1;
    if (rank==0) return 0;
    return get_kth(l,r,rank);
}

int get_suc(int l, int r, int k) {
    if (k==r-l+1) return tot+1;
    int rank=get_rank(l,r,k+1);
    if (rank>r-l+1) return tot+1;
    return get_kth(l,r,rank);
}

struct node {
    int op, l, r, k;
} q[MAXN];

int query(int x) {
    return lower_bound(b+1,b+1+tot,x)-b;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1; i<=n; ++i) cin>>a[i], b[++tot]=a[i];
    for (int i=1; i<=m; ++i) {
        cin>>q[i].op>>q[i].l;
        if (q[i].op==3) cin>>q[i].k;
        else cin>>q[i].r>>q[i].k;
        if (q[i].op!=2) b[++tot]=q[i].k;
    }
    sort(b+1,b+1+tot); tot=unique(b+1,b+1+tot)-(b+1);
    b[0]=-INT_MAX; b[tot+1]=INT_MAX;
    for (int i=1; i<=n; ++i) 
        a[i]=query(a[i]);
    for (int i=1; i<=m; ++i)
        if (q[i].op!=2) q[i].k=query(q[i].k);
    n+=m;
    for (int i=1; i<=n; ++i)
        update(i,a[i],1);
    for (int i=1; i<=m; ++i) {
        auto [op,l,r,k]=q[i];
        if (op==1) 
            cout<<get_rank(l,r,k)<<'\n';
        else if (op==2) 
            cout<<b[get_kth(l,r,k)]<<'\n';
        else if (op==3) 
            change(l,k);
        else if (op==4) 
            cout<<b[get_pre(l,r,k)]<<'\n';
        else 
            cout<<b[get_suc(l,r,k)]<<'\n';
    }
    return 0;
}