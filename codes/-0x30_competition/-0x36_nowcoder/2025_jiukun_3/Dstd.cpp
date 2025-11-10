#include<bits/stdc++.h>
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
    char ch = getchar(); int nega = 1; while (!isdigit(ch)) { if (ch == '-') nega = -1; ch = getchar(); }
    int ans = 0; while (isdigit(ch)) { ans = ans * 10 + ch - 48;ch = getchar(); }
    if (nega == -1) return -ans;
    return ans;
}
void print(vector<int> x) { for (int i = 0;i < (int)x.size();i++) printf("%d%c", x[i], " \n"[i == (int)x.size() - 1]); }
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int add(int x, int y, int z) { return add(add(x, y), z); }
inline int sub(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
inline int mul(int x, int y) { return 1LL * x * y % mod; }
inline int mul(int x, int y, int z) { return mul(mul(x, y), z); }
#define inc(x,y) x=add(x,y)
#define dec(x,y) x=sub(x,y)
#define N 10000005
int presum[N], f[N];
int fac[N], inv[N], ifac[N], preinv[N];
int n;
void init()
{
    fac[0] = 1; for (int i = 1;i < N;i++) fac[i] = mul(fac[i - 1], i);
    inv[0] = inv[1] = 1; for (int i = 2;i < N;i++) inv[i] = mul(mod - mod / i, inv[mod % i]);
    ifac[0] = 1; for (int i = 1;i < N;i++) ifac[i] = mul(ifac[i - 1], inv[i]);
    for (int i = 1;i <= n;i++) presum[i] = mul(2, sub(inv[1], inv[i + 1]));
    for (int i = 1;i <= n;i++) f[i] = add(f[i - 1], presum[i]);
    for (int i = 1;i <= n;i++) preinv[i] = add(preinv[i - 1], inv[i]);
}
int getrange(int l, int r)
{
    if (l > r) return 0;
    if (l == r) return 1;
    int ans = 0;
    if (l == 1 && r == n) return 2 * n - 1;
    if (l == 1)
    {
        l++;
        ans = add(ans, preinv[r]);
    }
    if (r == n)
    {
        r--;
        ans = add(ans, preinv[n - l + 1]);
    }
    return add(ans, f[r - l + 1]);
}
signed main()
{
    cin >> n;
    init();
    // for(int i=1;i<=n;i++) printf("%d%c",f[i]," \n"[i==n]);
    // printf("%d\n",getrange(2,3));
    // return 0;
    int Q = read();
    while (Q--)
    {
        int l = read(), r = read();
        if (n == 1) printf("1\n");
        else
        {
            int tot = sub(getrange(1, n), add(getrange(1, l - 1), getrange(r + 1, n)));
            int bad = sub(getrange(l, r), r - l + 1);
            // printf("%d %d\n",tot,bad);
            printf("%d\n", sub(tot, mul(bad, 2)));
        }
    }
    return 0;
}


