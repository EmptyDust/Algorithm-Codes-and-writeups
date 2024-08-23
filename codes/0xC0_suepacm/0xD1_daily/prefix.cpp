#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

int a[MAXN], pre[MAXN], first_meet[MAXN];
const int MID = 5e5 + 100;
int res = 0;
void solve() {
    int n, l, r;std::cin >> n >> l >> r;
    //初始化 -1代表是初始状态
    for (int i = 0;i <= n;++i) {
        first_meet[MID + i] = -1;
        first_meet[MID - i] = -1;
    }
    //读入
    for (int i = 1;i <= n;++i) {
        std::cin >> a[i];
        if (a[i] == 0)a[i] = -1;
    }
    //计算前缀和
    for (int i = 1;i <= n;++i)pre[i] = pre[i - 1] + a[i];
    //计算答案
    int ans = 0;
    for (int i = l - 1;i <= r;++i) {
        //映射
        int x = MID + pre[i];
        //记录第一次
        if (first_meet[x] == -1)first_meet[x] = i;
        else ans = std::max(ans, i - first_meet[x]);
    }
    res ^= ans;
}

// 0 0 0 0 0 
// -1 -1 
//   1 -1 1 -1
// 0 1 0  1 0
// 0   2

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    std::cout << res;
    return 0;
}