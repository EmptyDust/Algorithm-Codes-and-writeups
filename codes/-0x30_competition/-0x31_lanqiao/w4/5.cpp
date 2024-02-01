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
int n, nums[MAXN], cnt_tree[MAXN], ans_tree[MAXN], tmp;

signed main() {
    n = read();
    for (int i = 1;i <= n;++i)
        nums[i] = read();
    map<int, int> mp;
    for (int i = 1;i <= n;++i)
        tmp = read(), mp[tmp] = i;
    int ans = 0;
    for (int i = 1;i <= n;++i) {
        int x = mp[nums[i]];
        for (int f = x;f;f -= lowbit(f))ans += cnt_tree[f] * (x - f) + ans_tree[f];
        for (int f = x;f <= n;f += lowbit(f))cnt_tree[f]++;
        for (int f = x;f <= n;f += lowbit(f))ans_tree[f] += f - x;
    }
    cout << ans;
    return 0;
}