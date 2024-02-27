#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN], f[MAXN * 4], lazy[MAXN * 4];
using pt = pair<int, int>;
#define lowbit(x) x&-x
#define rn(x) i*2
#define ln(x) i*2+1

void push_down(int i) {
    lazy[i] = false;
    lazy[rn(x)] = true;
    lazy[ln(x)] = true;
    f[rn(x)] = f[i];
    f[ln(x)] = f[i];
}

int update(int x, int ql, int qr, int l = 1, int r = MAXN, int i = 1) {
    if (l > r)return 0;
    if (ql > r || qr < l)return 0;
    if (ql <= l && r <= qr && (lazy[i] || !~f[i])) {
        lazy[i] = 1;
        f[i] = max(f[i], x);
        return x >= f[i];
    }
    if (lazy[i])push_down(i);
    int mid = l + r >> 1;
    bool f_a = update(x, ql, qr, l, mid, rn(x));
    bool f_b = update(x, ql, qr, mid + 1, r, ln(x));
    bool flag = f_a && f_b;
    if (flag) {
        f[i] = x;
        lazy[i] = 1;
    }
    return flag;
}

int qry(int q, int l = 1, int r = MAXN, int i = 1) {
    if (l > r)return -1;
    if (q > r || q < l)return -1;
    if (lazy[i] || l == r)return f[i];
    int mid = l + r >> 1;
    return max(qry(q, l, mid, rn(x)), qry(q, mid + 1, r, ln(x)));
}

signed main() {
    memset(f, -1, sizeof f);
    lazy[1] = 1, f[1] = 0;
    int n, d;
    cin >> n >> d;
    int ans = 0;
    for (int i = 0;i < n;++i) {
        cin >> nums[i];
        int x = qry(nums[i]) + 1;
        ans = max(ans, x);
        update(x, nums[i] - d, nums[i] + d);
    }
    cout << ans;
    return 0;
}