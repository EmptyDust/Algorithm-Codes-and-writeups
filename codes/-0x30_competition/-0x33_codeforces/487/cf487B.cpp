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
int nums[MAXN], f[MAXN], mxq[MAXN], mnq[MAXN];
int mxl, mxr, mnl, mnr, n, s, l;

signed main() {
    memset(f, -1, sizeof f);
    mxl = mxr = mnl = mnr = 1;

    n = read();
    s = read();
    l = read();l--;
    for (int i = 1;i <= n;++i)nums[i] = read();

    f[0] = 0;
    for (int i = 1, lb = 1;i <= n;++i) {
        while (mxl < mxr && nums[mxq[mxr - 1]] < nums[i])mxr--;
        mxq[mxr++] = i;
        while (mnl < mnr && nums[mnq[mnr - 1]] > nums[i])mnr--;
        mnq[mnr++] = i;
        while (mxl < mxr && mnl < mnr && nums[mxq[mxl]] - nums[mnq[mnl]] > s) {
            lb = min(mxq[mxl], mnq[mnl]) + 1;
            mxq[mxl] < mnq[mnl] ? mxl++ : mnl++;
        }
        while (mxl < mxr && mnl < mnr && f[lb - 1] == -1) {
            lb++;
            if (mxq[mxl] < lb)mxl++;
            if (mnq[mnl] < lb)mnl++;
        }
        if (lb + l <= i)
            f[i] = f[lb - 1] + 1;
        //cout << f[i] << ':' << lb << endl;
    }
    cout << f[n];
    return 0;
}