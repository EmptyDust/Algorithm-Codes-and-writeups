#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::string s, t;std::cin >> s >> t;
    std::string ns = s, nt = t;
    for (int i = 0;i < n - 2;++i) {
        if (ns[i] == '0' && ns[i + 2] == '0') {
            nt[i + 1] = '1';
        }
    }
    for (int i = 0;i < n - 2;++i) {
        if (nt[i] == '1' && nt[i + 2] == '1') {
            ns[i + 1] = '1';
        }
    }
    std::vector<int> pre(n);
    int sum = 0;
    for (int i = 0;i < n;++i) {
        pre[i] = sum += ns[i] == '1';
    }

    int q;std::cin >> q;
    while (q--) {
        int l, r;std::cin >> l >> r;l--, r--;
        if (r - l + 1 <= 4) {
            std::string si, ti;si = s.substr(l, r - l + 1), ti = t.substr(l, r - l + 1);
            std::string ns = si, nt = ti;
            int n = ns.length();
            for (int i = 0;i < n - 2;++i) {
                if (ns[i] == '0' && ns[i + 2] == '0') {
                    nt[i + 1] = '1';
                }
            }
            for (int i = 0;i < n - 2;++i) {
                if (nt[i] == '1' && nt[i + 2] == '1') {
                    ns[i + 1] = '1';
                }
            }
            std::cout << std::count(ns.begin(), ns.end(), '1') << '\n';
            continue;
        }
        char tp = t[l], ts = t[r];
        char sp1 = s[l], sp2, ss1 = s[r], ss2;
        if (s[l + 1] == '1' || tp == '1' && nt[l + 2] == '1')sp2 = '1';
        else sp2 = '0';
        if (s[r - 1] == '1' || ts == '1' && nt[r - 2] == '1')ss2 = '1';
        else ss2 = '0';
        int ans = pre[r - 2] - pre[l + 1] + (sp1 == '1') + (sp2 == '1') + (ss1 == '1') + (ss2 == '1');
        std::cout << ans << '\n';
    }
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