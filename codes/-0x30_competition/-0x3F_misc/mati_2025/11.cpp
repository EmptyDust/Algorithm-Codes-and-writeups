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

struct Trie {
    struct node {
        std::array<int, 26> next;
        int cnt = 0;
    };
    std::vector<node> nodes;
    Trie() {
        nodes.assign(1, node());
    }
    i64 insert(std::string s) {
        i64 res = 0;
        int cur = 0;
        for (auto ch : s) {
            int c = ch - 'a';
            if (!nodes[cur].next[c]) {
                nodes[cur].next[c] = nodes.size();
                nodes.push_back(node());
            }
            cur = nodes[cur].next[c];
            res += nodes[cur].cnt;
            res %= mod;
            nodes[cur].cnt++;
        }
        return res;
    }
};

void solve() {
    int n;std::cin >> n;
    Trie trie;
    i64 ans = 0;
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        ans += trie.insert(s) * 2;
        ans %= mod;
        ans += s.length();
        ans %= mod;
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