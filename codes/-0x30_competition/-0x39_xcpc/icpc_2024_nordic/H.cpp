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

struct SAM {
    struct node {
        int len, link, endpos, size;
        std::map<char, int> next;
        node() {
            len = link = endpos = -1;
            size = 0;
            next = std::map<char, int>();
        }
    };
    std::vector<node> nodes;
    int last;
    int n;

    SAM(std::string s) {
        n = s.length();
        nodes.reserve(2 * n);
        nodes.assign(1, node());
        nodes[0].len = 0;
        nodes[0].link = -1;
        last = 0;
        for (int i = 0;i < n;++i) {
            extend(s[i], i + 1);
        }
    }

    void extend(char c, int pos) {
        int cur = nodes.size();
        nodes.emplace_back();
        nodes[cur].len = nodes[last].len + 1;
        int p = last;
        while (p != -1 && !nodes[p].next.count(c)) {
            nodes[p].next[c] = cur;
            p = nodes[p].link;
        }
        if (p == -1) {
            nodes[cur].link = 0;
        }
        else {
            int q = nodes[p].next[c];
            if (nodes[p].len + 1 == nodes[q].len) {
                nodes[cur].link = q;
            }
            else {
                int clone = nodes.size();
                nodes.emplace_back();
                nodes[clone].len = nodes[p].len + 1;
                nodes[clone].link = nodes[q].link;
                nodes[clone].next = nodes[q].next;
                while (p != -1 && nodes[p].next[c] == q) {
                    nodes[p].next[c] = clone;
                    p = nodes[p].link;
                }
                nodes[q].link = nodes[cur].link = clone;
            }
        }
        nodes[cur].endpos = pos;
        nodes[cur].size = 1;
        last = cur;
    }

    std::map<char, i64> work(std::string s) {
        int m = nodes.size();
        std::vector g(m, std::vector<int>());
        for (int i = 1;i < m;++i) {
            g[nodes[i].link].push_back(i);
        }
        std::vector<i64> dp1(n + 1), dp2(n + 2);
        std::map<char, i64> ans;
        auto dfs = [&](auto&& dfs, int u)->void {
            // std::cout << u << ' ';
            for (auto v : g[u]) {
                dfs(dfs, v);
                nodes[u].size += nodes[v].size;
                int ne = nodes[v].endpos;
                dp1[ne - nodes[v].len]++;
                dp1[ne - nodes[u].len]--;
                dp2[ne] -= nodes[v].len - nodes[u].len;
                nodes[u].endpos = ne;
                // std::cout << ne - nodes[v].len << ' ' << ne - nodes[u].len << '\n';
                int x = nodes[v].size;
                // std::cout << v << ' ' << x << '\n';
                while (x) {
                    ans['0' + x % 10] += nodes[v].len - nodes[u].len;
                    x /= 10;
                }
            }
            };
        dfs(dfs, 0);
        // for (auto x : size)std::cout << x << " ";
        for (int i = 1;i <= n;++i) dp1[i] += dp1[i - 1];
        // for (auto x : dp1)std::cout << x << ' ';std::cout << '\n';
        // for (auto x : dp2)std::cout << x << ' ';std::cout << '\n';
        dp2[0] += dp1[0];
        for (int i = 1;i <= n;++i) dp2[i] += dp2[i - 1] + dp1[i];
        // for (auto x : dp2)std::cout << x << ' ';std::cout << '\n';
        for (int i = 0;i < n;++i) {
            ans[s[i]] += dp2[i];
        }
        return ans;
    }

    void debug() {
        for (auto x : nodes) {
            std::cerr << x.len << ' ';
            std::cerr << x.link << ' ';
            std::cerr << x.endpos << ' ';
            std::cerr << x.size << ' ';
            std::cerr << '\n';
        }
    }
};

void solve() {
    std::string s;std::cin >> s;
    SAM sam(s);
    auto ans = sam.work(s);
    for (auto [ch, cnt] : ans) {
        std::cout << ch << ' ' << cnt << '\n';
    }
    // sam.debug();
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