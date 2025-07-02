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

std::vector<int> nums;
struct Trie {
    struct Node {
        int value = 0;
        int pos = 0;
        a2 next = { 0, 0 };
        bool tag = 0;
        Node() {}
    };
    std::vector<Node> nodes;
    std::vector<int> ans;
    int x0;
    Trie() {
        nodes.assign(1, Node());
        ans.assign(31, -1);
        x0 = 0;
    }
    void insert(int x, int pos) {
        int p = 0;
        for (int s = 30;s >= 0;--s) {
            if (!nodes[p].next[x >> s & 1]) {
                nodes[p].next[x >> s & 1] = nodes.size();
                nodes.push_back(Node());
            }
            p = nodes[p].next[x >> s & 1];
            // std::cout << p << ' ';
        }
        // std::cout << std::endl;
        nodes[p].value = x;
        nodes[p].pos = pos;
    }
    void work() {
        int x = -1;
        auto findmax = [&](auto&& self, int p, int pos, bool ok) {
            // std::cout << pos << ' ' << p << ' ' << ok << std::endl;
            if (x != -1 || nodes[p].tag) return;
            if (!nodes[p].next[0] && !nodes[p].next[1]) {
                if (ok) x = nodes[p].pos;
                return;
            }
            // std::cout << pos << " ";
            if (ans[pos] != -1) {
                if (nodes[p].next[0] && nodes[p].next[1]) {
                    self(self, nodes[p].next[!ans[pos]], pos - 1, ok);
                    self(self, nodes[p].next[ans[pos]], pos - 1, false);
                }
                else if (nodes[p].next[0]) self(self, nodes[p].next[0], pos - 1, ok);
                else if (nodes[p].next[1]) self(self, nodes[p].next[1], pos - 1, ok);
            }
            else if (nodes[p].next[0] && nodes[p].next[1]) {
                self(self, nodes[p].next[0], pos - 1, true);
            }
            else if (nodes[p].next[0]) {
                self(self, nodes[p].next[0], pos - 1, ok);
            }
            else if (nodes[p].next[1]) {
                self(self, nodes[p].next[1], pos - 1, ok);
            }
            if (x == -1)nodes[p].tag = 1;
            };
        int _ = 30;
        while (_--) {
            // for (int x : ans)std::cout << x << " ";
            // std::cout << std::endl;
            x = -1;
            findmax(findmax, 0, 30, false);
            if (x == -1)break;
            std::cout << "? " << x << std::endl;
            int y;std::cin >> y;
            x = nums[x - 1];
            if (y == -1) {
                int p = 0;
                for (int j = 30;j >= 0;--j) {
                    if (ans[j] == -1 && nodes[p].next[0] && nodes[p].next[1]) {
                        ans[j] = 1;
                        x0 |= 1ll << j;
                    }
                    p = nodes[p].next[x >> j & 1];
                }
                continue;
            }
            y = nums[y - 1];
            int p = 0;
            bool t = 1;
            for (int j = 30;j >= 0;--j) {
                if (t) {
                    if ((y >> j & 1) != (x >> j & 1)) {
                        t = 0;
                        if (ans[j] == -1 && nodes[p].next[0] && nodes[p].next[1]) {
                            ans[j] = 0;
                        }
                    }
                }
                else if (ans[j] == -1 && nodes[p].next[0] && nodes[p].next[1]) {
                    ans[j] = 1;
                    x0 |= 1ll << j;
                }
                p = nodes[p].next[x >> j & 1];
            }
        }
        std::cout << "! " << x0 << std::endl;
    }
};

// 11 8 9 14 15 12 13 2 3 0 
void solve() {
    int n, m;std::cin >> n >> m;
    nums.assign(n, 0);
    for (auto& x : nums) {
        std::cin >> x;
    }
    while (m--) {
        Trie trie;
        for (int i = 0;i < n;++i) {
            trie.insert(nums[i], i + 1);
        }
        trie.work();
        // std::cout << "end" << std::endl;
    }
}

signed main() {
    // for (int i = 1;i <= 9;++i)std::cout << (i ^ 1) << ' ';std::cout << std::endl;
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}