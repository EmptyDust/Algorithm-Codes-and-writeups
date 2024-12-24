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


// 这种写法抛弃了同学们普遍使用的结点表示法，而是采用算法竞赛类型的modernC++写法，大量使用vector和lambda。
// 我认为这更加好看
struct haffman_tree {
    std::vector<int> data, Fa, Le, Ri;
    std::vector<char> chars;
    std::vector<std::string> code;
    int n = 0;
    int root = -1;
    haffman_tree(std::vector<int> wei) {
        for (int i = 0;i < 26;++i) {
            if (wei[i]) {
                data.push_back(wei[i]);
                chars.push_back(i + 'a');
            }
        }
        n = data.size();
        Fa.assign(n, -1);
        Le.assign(n, -1);
        Ri.assign(n, -1);
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
        for (int i = 0;i < n;++i) {
            pq.push({ data[i],i });
        }
        while (pq.size() > 1) {
            auto [a, ap] = pq.top();pq.pop();
            auto [b, bp] = pq.top();pq.pop();
            Fa[ap] = Fa[bp] = Fa.size();
            pq.push({ a + b,int(Fa.size()) });
            data.push_back(a + b);
            Fa.push_back(-1);
            Le.push_back(ap);
            Ri.push_back(bp);
        }
        for (int i = 0;i < Fa.size();++i)
            if (Fa[i] == -1)
                root = i;
        code.assign(n, "");
        auto dfs = [&](auto&& self, auto u, std::string s) {
            if (u == -1)return;
            if (u < n)code[u] = s;
            self(self, Le[u], s + "0");
            self(self, Ri[u], s + "1");
            };
        dfs(dfs, root, "");
    }
    void print() {
        for (int i = 0;i < n;++i) {
            std::cout << chars[i] << '\t' << data[i] << '\t' << code[i] << '\n';
        }
    }
    std::string encode(std::string str) {
        std::string res;
        for (auto ch : str)
            for (int i = 0;i < n;++i)
                if (ch == chars[i])
                    res += code[i];
        return res;
    }
    std::string decode(std::string str) {
        std::string res;
        int cur = root;
        for (char ch : str) {
            int b = ch - '0';
            if (b) cur = Ri[cur];
            else cur = Le[cur];
            if (cur < n) {
                res += chars[cur];
                cur = root;
            }
        }
        return res;
    }
};

void solve() {
    std::vector<int> wei(26);
    // int n;std::cin >> n;
    // for (int i = 0;i < n;++i) {
    //     char ch;int w;std::cin >> ch >> w;
    //     wei[ch - 'A'] += w;
    // }
    std::string s;std::cin >> s;
    for (char ch : s)wei[ch - 'a']++;
    haffman_tree hfmt(wei);
    hfmt.print();
    std::string enc = hfmt.encode(s);std::cout << enc << '\n';
    std::string dec = hfmt.decode(enc);std::cout << dec << '\n';
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