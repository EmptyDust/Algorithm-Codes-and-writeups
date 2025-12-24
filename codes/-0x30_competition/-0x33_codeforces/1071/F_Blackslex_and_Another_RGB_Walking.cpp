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

void encode() {
    int n, m;std::cin >> n >> m;
    std::vector g(n, std::vector<int>());
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> col(n);
    std::queue<int> q;
    q.push(0);
    col[0] = 1;
    while (q.size()) {
        auto u = q.front();
        q.pop();
        for (auto v : g[u]) if (!col[v]) {
            col[v] = col[u] % 3 + 1;
            q.push(v);
        }
    }
    for (auto x : col) std::cout << "rgb"[x - 1]; std::cout << '\n';
}

void decode() {
    int q;std::cin >> q;//std::cout << q << ' ';
    while (q--) {
        int n;std::cin >> n;
        std::string s;std::cin >> s;
        assert(!(s.find('r') != -1 && s.find('g') != -1 && s.find('b') != -1));
        if (s.find('r') != -1 && s.find('b') != -1) {
            std::cout << (s.find('r') + 1) << '\n';
        }
        else if (s.find('g') != -1 && s.find('r') != -1) {
            std::cout << (s.find('g') + 1) << '\n';
        }
        else if (s.find('b') != -1 && s.find('g') != -1) {
            std::cout << (s.find('b') + 1) << '\n';
        }
        else {
            std::cout << 1 << '\n';
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::string type;std::cin >> type;
    int t = 1;
    std::cin >> t;
    while (t--) {
        if (type == "first") {
            encode();
        }
        else {
            decode();
        }
    }
    return 0;
}