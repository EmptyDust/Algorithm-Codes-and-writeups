#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, k, d;std::cin >> n >> k >> d;
    std::vector<int> h(n);
    for (int& x : h)std::cin >> x;
    auto l = 0, r = n + 1;
    auto cal = [&](int x) {
        int min = h[0], max = h[0];
        int cnt = 0;
        for (int i = 1;i < n;++i) {
            min = std::min(h[i], min);
            max = std::max(h[i], max);
            if (max - min > x) {
                min = h[i];
                max = h[i];
                cnt++;
            }
        }
        return cnt;
        };
    auto check = [&](int x) {
        return cal(x) <= k;
        };
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        }
        else l = mid + 1;
    }
    std::cout << l + 1 << '\n';
    std::cout << cal(d) << '\n';
    std::vector<int> dp(n);
    std::deque<pii> min, max;
    min.push_back({ h[0],0 });
    max.push_back({ h[0],0 });
    for (int l = 0, r = 0;l < n;++l) {
        while (max.size() && l > max.front().second)max.pop_front();
        while (min.size() && l > min.front().second)min.pop_front();
        if (r < l)r = l;
        while (r < n - 1) {
            // if (l == 0)std::cout << max.front().first << ' ';
            // if (l == 0)std::cout << max.front().first - h[r + 1] << '\n';
            if (max.front().first - h[r + 1] <= d && h[r + 1] - min.front().first <= d) {
                while (max.size() && max.back().first < h[r + 1])max.pop_back();
                while (min.size() && min.back().first > h[r + 1])min.pop_back();
                max.push_back({ h[r + 1],r + 1 });
                min.push_back({ h[r + 1],r + 1 });
                r++;
            }
            else break;
        }
        dp[l] = r;
    }
    std::vector st(30, std::vector<int>(n));
    for (int i = 0;i < n;++i)st[0][i] = dp[i];
    // for (int x : dp)std::cout << x << " ";
    for (int s = 1;s < 30;++s) {
        for (int i = 0;i < n;++i) {
            i64 r = st[s - 1][i] + 1;
            if (r >= n)st[s][i] = st[s - 1][i];
            else {
                st[s][i] = st[s - 1][r];
            }
        }
    }
    auto query = [&](int p) {
        int _k = k;
        int cur = p;
        int s = 0;
        while (_k) {
            if (_k & 1) {
                // std::cout << s << ' ' << cur << '\n';
                cur = st[s][cur] + 1;
                // std::cout << st[s][cur] << ' ';
                if (cur >= n)break;
            }
            _k >>= 1;
            s++;
        }
        return cur - p;
        };
    // std::cout << query(0);
    int ans = 0;
    for (int i = 0;i < n;++i) {
        ans = std::max(ans, query(i));
    }
    std::cout << ans;
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