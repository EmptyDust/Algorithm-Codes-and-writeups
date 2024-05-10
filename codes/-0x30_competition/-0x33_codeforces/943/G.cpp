#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], ans[MAXN], n;
using pt = std::pair<int, int>;

std::vector<int> z_function(std::string s) {
    int n = (int)s.length();
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

int count(auto x, std::vector<int>& zf) {
    if (x == 0)return true;
    int cnt = 0;
    for (int i = 0;i < n;++i)if (zf[i] >= x || i == 0) {
        i += x - 1;
        cnt++;
    }
    return cnt;
}

void solve(int ql, int qr, int l, int r, std::vector<int>& zf) {
    if (ql > qr)return;
    if (l > r)return;
    if (l == r) {
        for (int q = ql;q <= qr;++q)ans[q] = l;
        return;
    }
    int mid = l + r + 1 >> 1;
    int cnt = count(mid, zf);
    solve(std::max(ql, cnt + 1), qr, l, mid - 1, zf);
    solve(ql, std::min(qr, cnt), mid, r, zf);
}

void solve() {
    int ql, qr;
    std::cin >> n >> ql >> qr;
    std::string s;std::cin >> s;
    auto zf = z_function(s);
    solve(ql, qr, 0, n, zf);
    for (int q = ql;q <= qr;++q)std::cout << ans[q] << ' ';
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