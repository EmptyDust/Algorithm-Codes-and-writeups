#include<bits/stdc++.h>
using namespace std;
char buf[1 << 20], * p1, * p2;
#define GC (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
#define int long long
inline int read() {
    int x = 0, f = 1;char ch = GC;
    while (ch < '0' || ch > '9') { if (ch == '-')f = -1;ch = GC; }
    while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48);ch = GC; }
    return x * f;
}
#define lowbit(x) x&-x
using pt = pair<int, int>;
#define l first
#define r second
constexpr int MAXN = 200 + 10;
int q[MAXN][MAXN], f[MAXN][MAXN], nums[MAXN], n, k, x;
pt pos[MAXN];

int query(int q[MAXN], int f[MAXN], int& l, int& r, int pos) {
    while (l < r && pos - q[l] > k)l++;
    //cout << q[l] << ' ' << (~f[q[l]] ? f[q[l]] + nums[pos] : -1) << ' ';
    return ~f[q[l]] ? f[q[l]] + nums[pos] : -1;
}

void update(int q[MAXN], int f[MAXN], int& l, int& r, int pos) {
    while (l < r && f[q[r - 1]] < f[pos])r--;
    q[r++] = pos;
}

signed main() {
    memset(f, -1, sizeof f);
    n = read();
    k = read();
    x = read();
    for (int i = 0;i < n;++i)nums[i] = read();

    f[x][0] = 0;
    for (int i = 0;i < n;++i)for (int j = 1;j <= x - i / k;++j) {//for (int j = min(x, n - i);j * k >= n - i;--j) 
        f[j - 1][i] = query(q[j], f[j], pos[j].l, pos[j].r, i);
        //cout << i << ' ' << j - 1 << endl;
        if (~f[j - 1][i])update(q[j - 1], f[j - 1], pos[j - 1].l, pos[j - 1].r, i);
    }
    int ans = -1;
    for (int i = n - k;i < n;++i)ans = max(ans, f[0][i]);
    printf("%lld", ans);
    return 0;
}