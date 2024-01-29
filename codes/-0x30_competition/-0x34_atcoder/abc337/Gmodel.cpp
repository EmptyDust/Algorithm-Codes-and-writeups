#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x; }
ll powmod(ll a, ll b) { ll res = 1;a %= mod; assert(b >= 0); for (;b;b >>= 1) { if (b & 1)res = res * a % mod;a = a * a % mod; }return res; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// head

const int N = 201000;
struct node {
    node* l, * r;
    ll s;
}pool[N * 30], * cur = pool, * rt[N];

node* newnode() {
    return cur++;
}

node* build(int l, int r) {
    node* p = newnode();
    if (l == r) {
    }
    else {
        int md = (l + r) >> 1;
        p->l = build(l, md);
        p->r = build(md + 1, r);
    }
    return p;
}
ll query(node* p, int l, int r, int tl, int tr) {
    if (tl > tr) return 0;
    if (tl == l && tr == r) return p->s;
    else {
        int md = (l + r) >> 1;
        if (tr <= md) return query(p->l, l, md, tl, tr);
        else if (tl > md) return query(p->r, md + 1, r, tl, tr);
        else return query(p->l, l, md, tl, md) + query(p->r, md + 1, r, md + 1, tr);
    }
}
node* modify(node* p, int l, int r, int x, int v) {
    node* q = cur++; *q = *p; q->s += v;
    if (l != r) {
        int md = (l + r) >> 1;
        if (x <= md) q->l = modify(p->l, l, md, x, v);
        else q->r = modify(p->r, md + 1, r, x, v);
    }
    return q;
}

int l[N], r[N], id[N];
int tot;
int n;
VI e[N];
ll ret[N];
void dfs(int u, int f) {
    l[u] = ++tot;
    id[tot] = u;
    for (auto v : e[u]) if (v != f) {
        dfs(v, u);
    }
    r[u] = tot;
}
int query(int x, int p, int q) {
    return query(rt[r[x]], 1, n, p, q) - query(rt[l[x] - 1], 1, n, p, q);
}
void dfs2(int u, int f) {
    for (auto v : e[u]) if (v != f) {
        ret[v] = ret[u] - query(v, 1, u - 1) + v - 1 - query(v, 1, v - 1);
        dfs2(v, u);
    }
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(1, 0);
    rt[0] = build(1, n);
    rep(i, 1, n + 1) {
        rt[i] = modify(rt[i - 1], 1, n, id[i], 1);
    }
    rep(i, 1, n + 1) {
        ret[1] += query(i, 1, i - 1);
    }
    //printf("??? %lld\n",ret[1]);
    dfs2(1, 0);
    rep(i, 1, n + 1) printf("%lld ", ret[i]);
    puts("");
}
