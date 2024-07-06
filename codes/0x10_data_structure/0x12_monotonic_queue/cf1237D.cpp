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
constexpr int MAXN = 1e5 + 100;
int nums[MAXN * 3], ans[MAXN], q[MAXN * 3];
int n, l, r, ql, qr;

signed main() {
    memset(ans, -1, sizeof ans);
    n = read();
    for (int i = 0;i < n;++i)nums[i] = read();
    for (int i = n;i < 3 * n;++i)nums[i] = nums[i - n];
    for (l = r = ql = qr = 0;l < n && r < 3 * n;++r) {
        while (ql < qr && nums[q[qr - 1]] < nums[r])qr--;
        q[qr++] = r;
        while (ql < qr && nums[q[ql]] > nums[r] * 2) {
            while (l < n && l <= q[ql]) {
                ans[l] = r - l;
                l++;
            }
            ql++;
        }
    }
    for (int i = 0;i < n;++i)printf("%lld ", ans[i]);
    return 0;
}