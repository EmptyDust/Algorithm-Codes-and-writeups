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



const int TL = 10;
const char BC = '0';
struct PAM {
    struct node
    {
        int len, link, cnt;
        std::array<int, TL> next;
    };
    std::vector<node> nodes;
    int last;
    std::string s;
    int n;
    PAM(std::string& s) {
        n = s.length();
        nodes.reserve(n);
        this->s = s;
        nodes.assign(2, node());
        last = 0;
        nodes[0].len = 0;
        nodes[0].link = 1;
        nodes[1].len = -1;
        nodes[1].link = 0;
        for (int i = 0;i < n;++i) {
            extend(s[i], i);
        }
    }
    void extend(char ch, int p) {
        int u = get_fail(last, p);
        int c = ch - BC;
        if (!nodes[u].next[c]) {
            int v = nodes.size();
            nodes.emplace_back();
            nodes[v].link = nodes[get_fail(nodes[u].link, p)].next[c];
            nodes[u].next[c] = v;
            nodes[v].len = nodes[u].len + 2;
        }
        last = nodes[u].next[c];
        if (p >= n / 2)nodes[last].cnt++;
    }
    int get_fail(int u, int i) {
        while (i - nodes[u].len - 1 < 0 || s[i - nodes[u].len - 1] != s[i]) {
            u = nodes[u].link;
        }
        return u;
    }
    i64 work() {
        int m = nodes.size();
        for (int i = m - 1;i >= 0;--i) {
            nodes[nodes[i].link].cnt += nodes[i].cnt;
        }
        i64 ans = 0;
        for (int i = 0;i < m;++i)
            if (1 <= nodes[i].len && nodes[i].len <= n / 2)
                ans = (ans + 1ll * nodes[i].cnt * nodes[i].cnt % mod * nodes[i].len % mod) % mod;
        return ans;
    }
    void debug() {
        for (auto node : nodes) {
            std::cerr << node.cnt << ' ';
            std::cerr << node.len << ' ';
            std::cerr << node.link << '\n';
        }
    }
};

void solve() {
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    s = s + s;
    PAM pam(s);
    std::cout << pam.work();
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