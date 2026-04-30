#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;
using a3 = std::array<int, 3>;// priority eattime addtime

void solve() {
    int n, d;
    std::cin >> n >> d;
    std::set<a3> que, ate;
    std::set<int> all;
    std::vector<int> k(n), s(n);
    for (int i = 0;i < n;++i)
        std::cin >> k[i] >> s[i];
    std::vector<int> suf(n);
    suf[n - 1] = k[n - 1];
    for (int i = n - 2;~i;--i) {
        suf[i] = std::max(suf[i + 1], k[i]);
    }
    int ti = 0;
    for (int i = 0;i < n;++i) {
        que.insert({ -suf[i], ti++, i });
        all.insert(i);
    }
    for (int i = 1;i <= d;++i) {
        if (que.size()) {
            int x = (*que.begin())[2];
            if (all.count(x))all.erase(x);
            if (all.empty()) {
                std::cout << i;
                return;
            }
            que.erase(que.begin());
            ate.insert({ i + s[x] ,s[x],x });
        }
        while (!ate.empty() && (*ate.begin())[0] == i) {
            int x = (*ate.begin())[2];
            que.insert({ -k[x], ti++ ,x });
            ate.erase(ate.begin());
        }
    }
    std::cout << -1;
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