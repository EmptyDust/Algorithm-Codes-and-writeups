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

void solve() {
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    std::vector<int> a(n);
    int l = 1, r = n;
    for (int i = n - 1;i > 0;--i) {
        if (s[i - 1] == '>')a[i] = r, r--;
        else a[i] = l, l++;
    }
    a[0] = l;
    for (auto x : a)std::cout << x << " ";
    // int c = 0;
    // for (char ch : s) {
    //     if (ch == '<')c--;
    //     else c++;
    //     a.push_back(c);
    // }
    // std::vector<int> idx(n);
    // std::iota(idx.begin(), idx.end(), 0);
    // ranges::sort(idx, [&](int x, int y) {return a[x] < a[y];});
    // std::vector<int> ans(n);
    // for (int i = 0;i < n;++i) {
    //     ans[idx[i]] = i;
    // }
    // for (auto x : ans)std::cout << x + 1 << ' ';
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