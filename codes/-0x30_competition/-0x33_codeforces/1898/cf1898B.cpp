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
constexpr int MAXN = 2e5 + 100;
int nums[MAXN];

void solve() {
    int n;n = read();
    for (int i = 0;i < n;++i)nums[i] = read();
    int cnt = 0;
    for (int i = n - 2;i >= 0;--i)if (nums[i] > nums[i + 1]) {
        int tmp = ceil((double)nums[i] / nums[i + 1]);
        cnt += tmp - 1;
        nums[i] = nums[i] / tmp;
        //cout << i << ' ' << nums[i] << endl;
    }
    printf("%lld", cnt);
}

signed main() {
    int t;t = read();
    while (t--) {
        solve();
        printf("\n");
    }
    return 0;
}