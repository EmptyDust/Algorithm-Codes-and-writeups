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

int work(std::vector<int>& a, std::vector<int>& b) {
    // for (int x : a)std::cout << x << ' ';std::cout << std::endl;
    // for (int x : b)std::cout << x << ' ';std::cout << std::endl;
    int n = a.size(), m = b.size();
    int x = 0;
    int cnt = 0, res = 0;
    for (int i = m, j = 0;j < i;++j, x--) {//[j,i)
        while (j < i && x == b[i - 1]) --i, cnt++;
        // std::cout << j << ' ' << i << '\n';
        auto l = 0, r = n;
        while (l < r) {
            auto mid = l + r >> 1;
            if (a[mid] - x > n - mid - 1)r = mid;
            else l = mid + 1;
        }
        // std::cout << x << ' ' << n - 1 << '\n';
        res = std::max(res, l + cnt);
    }
    return res;
}

void solve() {
    int n;std::cin >> n;
    std::vector<int> z, f;
    int cnt = 0;
    for (int i = 0;i < n;++i) {
        int x;std::cin >> x;
        if (x > 0)z.push_back(x);
        else if (x < 0)f.push_back(x);
        else cnt++;
    }
    if (z.empty() && f.empty()) {
        std::cout << cnt;
        return;
    }
    if (z.empty()) {
        for (int& x : f)x = -x, z.push_back(x);
        f.clear();
    }
    std::sort(z.begin(), z.end());
    std::sort(f.begin(), f.end());
    if (f.empty()) {
        int n = z.size();
        int l = 0, r = n;
        while (l < r) {
            auto mid = l + r >> 1;
            if (z[mid] > n - mid - 1)r = mid;
            else l = mid + 1;
        }
        // for (int x : f)std::cout << x << ' ';
        // std::cout << l << ' ';
        std::cout << l + cnt;
        return;
    }
    // std::cout << z.size() << ' ' << f.size() << '\n';
    int ans = work(z, f);
    // std::cout << ans << ' ';
    for (int& x : z)x = -x;
    for (int& x : f)x = -x;
    std::swap(z, f);
    std::sort(z.begin(), z.end());
    std::sort(f.begin(), f.end());
    ans = std::max(ans, work(z, f));
    ans += cnt;
    std::cout << ans;
}

// void solve() {
//     int n;std::cin >> n;
//     std::vector<int> a(n + 1);
//     for (int i = 1;i <= n;++i)std::cin >> a[i];
//     std::sort(a.begin() + 1, a.end());
//     std::vector<int> pre(n + 1);pre[0] = inf;
//     for (int i = 1;i <= n;++i) {
//         if (a[i] > 0)break;
//         pre[i] = std::min(pre[i - 1] - 1, -1 - a[i]);
//         if (pre[i] > 0) {

//         }
//     }
//     std::vector<int> suf(n + 2);suf[n + 1] = inf;
//     for (int i = n;i >= 1;--i) {
//         if (a[i] >= 0)break;
//         suf[i] = std::min(suf[i + 1] + 1, 1 + a[i]);
//         if (suf[i] < 0) {

//         }
//     }
// }

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}