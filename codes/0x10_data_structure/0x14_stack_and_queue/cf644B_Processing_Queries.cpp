#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, b;std::cin >> n >> b;
    std::vector<pii> p(n);
    std::deque<pii> q;
    std::vector<i64> ans(n);
    i64 now = 0;
    for (int i = 0;i < n;++i) {
        auto& [t, d] = p[i];
        std::cin >> t >> d;
        i64 c = t - now;
        while (q.size() && q.front().first <= c) {
            c -= q.front().first;
            ans[q.front().second] = t - c;
            q.pop_front();
        }
        if (q.size())q.front().first -= c;
        now = t;
        if (q.size() <= b)q.push_back({ d,i });
        else ans[i] = -1;
    }
    while (q.size()) {
        now += q.front().first;
        ans[q.front().second] = now;
        q.pop_front();
    }
    for (auto x : ans)std::cout << x << " ";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}