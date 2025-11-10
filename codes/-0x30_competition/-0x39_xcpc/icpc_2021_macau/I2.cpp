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

struct SuffixArray {
    int n;
    std::vector<int> sa, rk, lc;
    SuffixArray(const std::string& s) {
        n = s.length();
        sa.resize(n);
        lc.resize(n - 1);
        rk.resize(n);
        std::iota(sa.begin(), sa.end(), 0);
        std::sort(sa.begin(), sa.end(), [&](int a, int b) { return s[a] < s[b]; });
        rk[sa[0]] = 0;
        for (int i = 1; i < n; ++i) {
            rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
        }
        int k = 1;
        std::vector<int> tmp, cnt(n);
        tmp.reserve(n);
        while (rk[sa[n - 1]] < n - 1) {
            tmp.clear();
            for (int i = 0; i < k; ++i) {
                tmp.push_back(n - k + i);
            }
            for (auto i : sa) {
                if (i >= k) {
                    tmp.push_back(i - k);
                }
            }
            std::fill(cnt.begin(), cnt.end(), 0);
            for (int i = 0; i < n; ++i) {
                ++cnt[rk[i]];
            }
            for (int i = 1; i < n; ++i) {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; --i) {
                sa[--cnt[rk[tmp[i]]]] = tmp[i];
            }
            std::swap(rk, tmp);
            rk[sa[0]] = 0;
            for (int i = 1; i < n; ++i) {
                rk[sa[i]] = rk[sa[i - 1]] + (tmp[sa[i - 1]] < tmp[sa[i]] || sa[i - 1] + k == n ||
                    tmp[sa[i - 1] + k] < tmp[sa[i] + k]);
            }
            k *= 2;
        }
        for (int i = 0, j = 0; i < n; ++i) {
            if (rk[i] == 0) {
                j = 0;
                continue;
            }
            for (j -= j > 0;
                i + j < n && sa[rk[i] - 1] + j < n && s[i + j] == s[sa[rk[i] - 1] + j] && s[i + j] != '#';) {
                ++j;
            }
            lc[rk[i] - 1] = j;
        }
    }
};

struct dsu {
    std::vector<int> d;
    dsu(int n) { d.resize(n); iota(d.begin(), d.end(), 0); }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            return true;
        }
        else return false;
    }
};

void solve() {
    int n;std::cin >> n;
    std::vector<std::string> a(n);
    std::string s;
    for (auto& str : a) {
        std::cin >> str;
        s += str + '#';
    }
    SuffixArray SA(s);
    int len = s.length();
    dsu d(len);
    for (int i = 1;i < len;++i) if (s[i] != '#') {
        d.merge(i, i - 1);
    }
    std::vector<a3> info;
    for (int i = 0;i < len - 1;++i) {
        info.push_back({ SA.lc[i], SA.sa[i], SA.sa[i + 1] });
    }
    ranges::sort(info, std::greater<a3>());
    i64 ans = 0;
    // for (auto x : d.d)std::cout << d.get_root(x) << " ";std::cout << '\n';
    for (auto& [x, u, v] : info) {
        if (s[u] != '#' && s[v] != '#' && d.merge(u, v)) {
            ans += x;
            // std::cout << s[u] << ' ' << s[v] << ' ' << u << ' ' << v << '\n';
        }
    }
    std::cout << ans;
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