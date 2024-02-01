#include<bits/stdc++.h>
using namespace std;
char buf[1 << 20], * p1, * p2;
#define GC (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
#define int long long
inline int read() {
    int x = 0, f = 1;char ch = GC;
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1;ch = GC; }
    while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48);ch = GC; }
    return x * f;
}
#define lowbit(x) x&-x
constexpr int MAXN = 5e5 + 100;
int n, tnums[MAXN], nums[MAXN], i_tree[MAXN];

signed main() {
    n = read();
    for (int i = 1;i <= n;++i)
        tnums[i] = read();
    iota(nums + 1, nums + n + 1, 1);
    sort(nums + 1, nums + n + 1, [&](int a, int b) {return tnums[a] < tnums[b];});
    unordered_map<int, int> mp;
    for (int i = 1;i <= n;++i)mp[tnums[nums[i]]] = i;
    int ans = 0;
    for (int i = 1;i <= n;++i) {
        ans += i - 1;
        for (int f = mp[tnums[i]];f;f -= lowbit(f))ans -= i_tree[f];
        for (int f = mp[tnums[i]];f <= n;f += lowbit(f))i_tree[f]++;
    }
    printf("%lld", ans);
    return 0;
}