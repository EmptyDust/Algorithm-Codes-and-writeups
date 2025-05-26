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
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    bool f = true;
    for (int i = 1;i < n;++i) f &= a[i] >= a[i - 1];
    if (f) {
        std::cout << 0 << '\n';
        return;
    }
    std::set<int> exs;
    a2 m{ -1,-1 };
    for (int i = 0;i < n;++i) {
        if (exs.count(k - a[i])) {
            for (int j = 0;j < i;++j) {
                if (a[j] == k - a[i]) {
                    m[0] = j;
                    m[1] = i;
                    break;
                }
            }
            break;
        }
        exs.insert(a[i]);
    }
    if (m == a2{ -1, -1 }) {
        std::cout << -1 << '\n';
        return;
    }
    std::vector<a3> ans;
    auto act = [&](int x, int y, int z) {
        int k = a[x] - a[z];
        ans.push_back({ x + 1, y + 1, k });
        a[x] -= k;
        a[y] += k;
        // for (auto x : a)std::cout << x << " ";std::cout << '\n';
        };
    if (a[m[0]] != a[0])act(m[0], m[1], 0);
    if (a[m[1]] != a[n - 1])act(m[1], 0, n - 1);
    m[0] = 0, m[1] = n - 1;
    std::vector<int> idx(n), rank(n);
    auto work = [&](int a, int b) {
        // swap(a, b)
        act(0, n - 1, a);
        act(a, n - 1, b);
        act(b, n - 1, 0);
        std::swap(rank[a], rank[b]);
        std::swap(idx[rank[a]], idx[rank[b]]);
        };
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin() + 1, idx.begin() + n - 1, [&](int x, int y) {return a[x] < a[y];});
    for (int i = 1;i < n - 1;++i)rank[idx[i]] = i;
    // for (int x : idx)std::cout << x << ' ';std::cout << '\n';
    // for (int x : rank)std::cout << x << ' ';std::cout << '\n';
    for (int i = 1;i < n - 1;++i) {
        if (i != idx[i])work(i, idx[i]);
    }
    ans.push_back({ 1, n, a[0] });
    std::cout << ans.size() << '\n';
    for (auto [a, b, c] : ans)std::cout << a << " " << b << ' ' << c << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}