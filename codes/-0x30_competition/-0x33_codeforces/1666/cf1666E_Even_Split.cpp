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

int cal1(std::vector<int>& a) {
    int n = a.size() - 1;
    int l = 0, r = 1e9 + 1;
    auto check = [&](auto x)->bool {
        int C = 0;
        for (int i = 0;i < n;++i) {
            if (a[i] - C > x)return false;
            if (i != n - 1)
                C = std::min(C + x, a[i + 1]);
        }
        if (a.back() - C > x)return false;
        return true;
        };
    // std::cout << check(17);
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    return l;
}

int cal2(std::vector<int>& a) {
    int n = a.size();
    int l = 0, r = 1e9 + 1;
    auto check = [&](auto x)->bool {
        int C = 0;
        for (int i = 0;i < n;++i) {
            if (C > a[i])return false;
            C = std::max(C + x, a[i]);
        }
        return true;
        };
    while (l < r) {
        auto mid = l + r + 1 >> 1;
        if (check(mid))l = mid;
        else r = mid - 1;
    }
    return l;
}

void solve() {
    int l, n;std::cin >> l >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    a.push_back(l);
    int MAX = cal1(a);
    int MIN = cal2(a);
    // std::cout << MAX << " " << MIN << '\n';
    std::vector<int> c(n + 1), d(n + 1);
    c[n] = l;
    for (int i = n - 1;i >= 0;--i) {
        c[i] = std::max(i == 0 ? 0 : a[i - 1], c[i + 1] - MAX);
    }
    d[n] = l;
    for (int i = n - 1;i >= 0;--i) {
        d[i] = std::min(a[i], d[i + 1] - MIN);
    }
    // std::cout << d[0] << ' ' << d[1] << '\n';
    int C = 0;
    for (int i = 0;i < n;++i) {
        int nC = C + MIN;
        nC = std::max(nC, c[i + 1]);
        nC = std::min(nC, d[i + 1]);
        std::cout << C << ' ' << nC << '\n';
        C = nC;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}