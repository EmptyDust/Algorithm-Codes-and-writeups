#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

struct AhoCorasick {
    static constexpr int ALPHABET = 26;
    struct Node {
        int len;
        int link;
        int id;
        std::array<int, ALPHABET> next;
        Node() :id(0), len{ 0 }, link{ 0 }, next{} {}
    };

    std::vector<Node> t;

    AhoCorasick() {
        init();
    }

    void init() {
        t.assign(2, Node());
        t[0].next.fill(1);
        t[0].len = -1;
    }

    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }

    int add(const std::string& a, int id) {
        int p = 1;
        for (auto c : a) {
            int x = c - 'a';
            if (t[p].next[x] == 0) {
                t[p].next[x] = newNode();
                t[t[p].next[x]].len = t[p].len + 1;
            }
            p = t[p].next[x];
        }
        t[p].id = id;
        return p;
    }

    void work() {
        std::queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int i = 0; i < ALPHABET; i++) {
                if (t[x].next[i] == 0) {
                    t[x].next[i] = t[t[x].link].next[i];
                }
                else {
                    t[t[x].next[i]].link = t[t[x].link].next[i];
                    q.push(t[x].next[i]);
                }
            }
        }
    }

    int next(int p, int x) {
        return t[p].next[x];
    }

    int link(int p) {
        return t[p].link;
    }

    int len(int p) {
        return t[p].len;
    }

    int size() {
        return t.size();
    }
};

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

void solve() {
    std::string s;std::cin >> s;
    int n = s.length();
    AhoCorasick ac;
    int q;std::cin >> q;
    int sq = std::sqrt(n);
    std::vector<int> ans(q + 1, inf), op(q + 1), len(q + 1);
    std::vector<std::vector<int>> doc(q + 1);
    for (int i = 1;i <= q;++i) {
        int k; std::string t;std::cin >> k >> t;
        int m = t.length();
        if (m >= sq) {
            auto z = z_function(t + s);
            for (int j = m;j < n + m;++j) {
                if (z[j] >= m) {
                    doc[i].push_back(j);
                    if (doc[i].size() >= k) {
                        ans[i] = std::min(ans[i], j - doc[i][doc[i].size() - k] + m);
                    }
                }
            }
            doc[i].clear();
        }
        else {
            ac.add(t, i);
            op[i] = k;
            len[i] = m;
        }
    }
    ac.work();
    for (int i = 0, p = 1;i < n;++i) {
        p = ac.next(p, s[i] - 'a');
        int u = p;
        while (u > 1) {
            if (ac.t[u].id) {
                int to = ac.t[u].id;
                doc[to].push_back(i - len[to] + 1);
                if (doc[to].size() >= op[to]) {
                    ans[to] = std::min(ans[to], i - doc[to][doc[to].size() - op[to]] + 1);
                }
            }
            u = ac.link(u);
        }
    }
    for (int i = 1;i <= q;++i) {
        if (ans[i] >= inf)std::cout << -1 << '\n';
        else std::cout << ans[i] << '\n';
    }
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