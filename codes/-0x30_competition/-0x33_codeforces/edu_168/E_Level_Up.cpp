#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;

const int N = 450 + 20, M = 2e5 + 10;
int cnt[N][M];
void solve() {
    int n, q;std::cin >> n >> q;
    int sq = std::sqrt(n);
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    for (int s = 1;s <= sq + 5;++s) {
        for (int i = 1;i <= n;++i)
            cnt[s][i] = cnt[s][i - 1] + (a[i] >= s);
    }
    std::vector<a3> querys(q);
    std::vector<int> output(q);
    int idx = 0;
    for (auto& [k, p, id] : querys) {
        std::cin >> p >> k;
        id = idx++;
    }
    std::ranges::sort(querys);
    std::vector<a3> cur;
    auto work = [&]() {
        int k = cur.back()[1];
        if (k <= sq) {
            std::vector<int> ans(n + 1);
            int st = 1, cnt = 0;
            for (int i = 1;i <= n;++i) {
                ans[i] = st;
                if (a[i] >= st) {
                    cnt++;
                    if (cnt == k) {
                        cnt = 0;
                        st++;
                    }
                }
            }
            for (auto [p, _, id] : cur) {
                output[id] = ans[p] <= a[p];
            }
        }
        else {
            std::vector<int> ans;ans.push_back(1);
            int now = 0, st = 1;
            while (now < n && cnt[st][n] - cnt[st][now] >= k) {
                auto l = now + 1, r = n;
                int res = 0;
                while (l <= r) {
                    auto mid = l + r >> 1;
                    if (cnt[st][mid] - cnt[st][now] >= k) {
                        r = mid - 1;
                        res = mid;
                    }
                    else l = mid + 1;
                }
                now = res;
                st++;
                ans.push_back(res + 1);
            }

            for (auto [p, _, id] : cur) {
                for (int i = 0;i < ans.size();++i) {
                    if (i == ans.size() - 1 || p < ans[i + 1]) {
                        output[id] = i + 1 <= a[p];
                        break;
                    }
                }
            }
        }
        };
    for (auto [k, p, id] : querys) {
        if (cur.empty()) {
            cur.push_back({ p,k,id });
        }
        else {
            if (k == cur.back()[1])cur.push_back({ p,k,id });
            else {
                work();
                cur.clear();
                cur.push_back({ p,k,id });
            }
        }
    }
    work();
    for (int x : output)std::cout << (x ? "YES" : "NO") << '\n';
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