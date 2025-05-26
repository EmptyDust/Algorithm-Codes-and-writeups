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
    struct Node {
        int value = 0;
        std::vector<int> hi, lo;
        a2 next = { 0, 0 };
        Node(int value) :value(value) {}
    };
    std::vector<Node> nodes;
    Trie() {
        nodes.assign(1, Node(0));
    }
    void insert(int x, int pos) {
        int p = 0;
        for (int s = 30;s >= 0;--s) {
            if (!nodes[p].next[x >> s & 1]) {
                nodes[p].next[x >> s & 1] = nodes.size();
                nodes.push_back(Node(0));
            }
            p = nodes[p].next[x >> s & 1];
            nodes[p].hi.push_back(pos);
        }
    }
    void work() {
        for (int p = 1;p < nodes.size();++p) {
            std::reverse(nodes[p].hi.begin(), nodes[p].hi.end());
        }
    }
    void del(int x, int pos) {
        int p = 0;
        for (int s = 30;s >= 0;--s) {
            p = nodes[p].next[x >> s & 1];
            nodes[p].hi.pop_back();
        }
    }
    void add(int x, int pos) {
        int p = 0;
        for (int s = 30;s >= 0;--s) {
            p = nodes[p].next[x >> s & 1];
            nodes[p].lo.push_back(pos);
        }
    }
    int cal(int x, int k, int pos) {
        int res = inf;
        int p = 0;
        for (int s = 30;s >= 0;--s) {
            if (k >> s & 1) {
                int f = (x >> s & 1) ^ 1;
                if (nodes[p].next[f]) {
                    p = nodes[p].next[f];
                    continue;
                }
                else {
                    return res;
                }
            }
            else {
                int f = (x >> s & 1) ^ 1;
                if (nodes[p].next[f]) {
                    int np = nodes[p].next[f];
                    // std::cout << nodes[np].hi.back << ' ' << nodes[np].lo.size() << '\n';
                    if (nodes[np].hi.size()) {
                        res = std::min(res, nodes[np].hi.back() - pos);
                        // std::cout << nodes[np].hi.back() << ' ' << pos << '\n';
                    }
                    if (nodes[np].lo.size()) {
                        res = std::min(res, pos - nodes[np].lo.back());
                        // std::cout << pos << ' ' << nodes[p].lo.back() << '\n';
                    }
                }
                f ^= 1;
                if (nodes[p].next[f]) {
                    p = nodes[p].next[f];
                    continue;
                }
                else {
                    return res;
                }
            }
        }
        if (nodes[p].hi.size()) {
            res = std::min(res, nodes[p].hi.back() - pos);
            // std::cout << nodes[p].hi.back() << ' ' << pos << '\n';
        }
        if (nodes[p].lo.size()) {
            res = std::min(res, pos - nodes[p].lo.back());
            // std::cout << pos << ' ' << nodes[p].lo.back() << '\n';
        }
        return res;
    }
};

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n), b(n + 1);
    for (auto& x : a)std::cin >> x;
    int ans = inf;
    Trie trie;
    for (int i = 0;i < n;++i) {
        trie.insert(a[i], i);
    }
    trie.work();
    for (int i = 0;i < n;++i) {
        int res = trie.cal(a[i], k, i);
        trie.del(a[i], i);
        trie.add(a[i], i);
        ans = std::min(ans, res);
    }
    if (ans == inf)ans = -1;else ans++;
    std::cout << ans;
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


