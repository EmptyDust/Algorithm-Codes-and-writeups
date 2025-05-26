#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

std::vector<int> z_function(std::vector<int>& s) {
    int n = (int)s.size();
    std::vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        }
        else {
            z[i] = std::max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    if (a.size() == 1) {
        std::cout << 1;
        return;
    }
    bool f = false;
    for (int i = 1;i < n;++i) {
        if (a[i] == a[i - 1]) {
            ranges::reverse(a.begin(), a.begin() + i);
            ranges::reverse(a.begin() + i, a.end());
            ranges::reverse(a);
            f = true;
            break;
        }
    }
    std::vector<int> cur, ans(n);ans.back() = 1;
    if (a.front() == a.back()) a.pop_back();
    else if (!f) {
        cur = a;
        int m = cur.size();
        cur.insert(cur.end(), cur.begin(), cur.end());
        auto z = z_function(cur);
        for (int i = 1;i < m;++i) {
            if (i + z[i] < m + i) {
                ans[n - (i + 1)] = 1;
            }
        }
        for (int x : ans)std::cout << x;
        return;
    }
    auto work = [&]() {
        if (cur.size() == 1)return;
        int m = cur.size();
        auto z = z_function(cur);
        for (int i = 1;i < m;++i) {
            if (i + z[i] < m) {
                ans[n - (i + 1)] = 1;
            }
        }
        };
    for (int i = 0;i < n;++i) {
        if (i && a[i] == a[i - 1]) {
            work();
            cur.clear();
        }
        cur.push_back(a[i]);
    }
    work();
    for (int x : ans)std::cout << x;
}

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

/*
1
3 30 共有三个程序，内存为30
15 1 1

28
4
IN 1
IN 2
OUT 1
IN 3

先将1(15)，2(1)调入内存，现在内存中前16位置占用，后14位置空闲
调出1(15)，现在内存中只有位置16占用
调入3(1)，现在内存中位置1, 16占用
现在只有1(15)没有调入内存，内存中有28个空闲位置。
*/