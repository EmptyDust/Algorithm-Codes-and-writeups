#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<i64> a(n), b(m);
    for (auto& x : a)std::cin >> x;
    for (auto& x : b)std::cin >> x;
    ranges::sort(a);
    ranges::sort(b);
    int kmax = std::min({ n,m,(n + m) / 3 });
    std::vector<i64> A(1), B(1);
    for (int i = 0, j = n - 1;i < j;++i, --j) {
        A.push_back(a[j] - a[i]);
    }
    for (int i = 0, j = m - 1;i < j;++i, --j) {
        B.push_back(b[j] - b[i]);
    }
    std::vector<i64> preA(A), preB(B);
    for (int i = 1;i < preA.size();++i) {
        preA[i] += preA[i - 1];
        // std::cout << preA[i] << ' ';
    }
    // std::cout << '\n';
    for (int i = 1;i < preB.size();++i) {
        preB[i] += preB[i - 1];
        // std::cout << preB[i] << ' ';
    }
    // std::cout << '\n';
    auto check = [&](int i, int j) {
        return i >= 0 && j >= 0 && 2 * i + j <= n && 2 * j + i <= m && i <= A.size() && j <= B.size();
        };
    std::vector<i64> ans(kmax + 1, -1);
    std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq;
    for (int i = 0, j = (int)B.size() - 1;i < A.size();++i) {
        while (j >= 0 && !check(i, j))j--;
        if (j < 0)break;
        pq.push({ preA[i] + preB[j], i, j });
        // std::cout << i << ' ' << j << '\n';
    }
    while (pq.size()) {
        auto [res, i, j] = pq.top();
        pq.pop();
        // std::cout << i << ' ' << j << '\n';
        if (ans[i + j] >= res)continue;
        ans[i + j] = res;
        if (check(i, j - 1)) {
            pq.push({ preA[i] + preB[j - 1],i,j - 1 });
        }
        if (check(i - 1, j)) {
            pq.push({ preA[i - 1] + preB[j],i - 1,j });
        }
    }
    std::cout << kmax << '\n';
    for (int i = 1;i <= kmax;++i)
        std::cout << ans[i] << ' ';
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