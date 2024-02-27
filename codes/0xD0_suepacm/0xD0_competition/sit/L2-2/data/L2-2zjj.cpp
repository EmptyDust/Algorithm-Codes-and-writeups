#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef pair<int, int> PII;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
int lowbit(int x) { return x & -x; }
int rnd(int x) { return mrand() % x; }
ll powmod(ll a, ll b) { ll res = 1;a %= mod; assert(b >= 0); for (;b;b >>= 1) { if (b & 1)res = res * a % mod;a = a * a % mod; }return res; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll rd() { ll x = 0;char ch;bool f = true;for (ch = getchar();!isdigit(ch);ch = getchar())if (ch == '-')f ^= f;for (;isdigit(ch);ch = getchar())x = (x << 3) + (x << 1) + (ch ^ 48);return f ? x : -x; }
inline void wr(ll x) { if (x < 0)putchar('-'), x = -x;if (x > 9)wr(x / 10);putchar(x % 10 + 48); }
inline void wr(char* s) { printf("%s", s); }
// head

const int N = 100010;

void solve() {
    int n = rd(), m = rd(), k = rd();
    vector<ll>a(n), b(m);
    rep(i, 0, n - 1)a[i] = rd();sort(all(a));
    rep(i, 0, m - 1)b[i] = rd();sort(all(b));
    typedef pair<ll, pair<int, int>> plii;
    priority_queue<plii, vector<plii>, greater<plii>> q;
    map<PII, int>mp;
    q.push({ a[0] + b[0],{0,0} }), mp[{0, 0}]++;

    ll res = 0;
    while (k--) {
        auto [val, p] = q.top();
        q.pop();
        auto [x, y] = p;
        res = (res + val) % mod;

        if (x + 1 < n && !mp[{x + 1, y}])q.push({ a[x + 1] + b[y],{x + 1,y} }), mp[{x + 1, y}]++;
        if (y + 1 < m && !mp[{x, y + 1}])q.push({ a[x] + b[y + 1],{x,y + 1} }), mp[{x, y + 1}]++;
    }
    cout << res << '\n';
}

int main() {
    int T = 1;
    T = rd();
    while (T--) {
        solve();
    }
    return 0;
}