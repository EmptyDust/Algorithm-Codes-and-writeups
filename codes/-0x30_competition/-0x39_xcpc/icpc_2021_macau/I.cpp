#include<bits/stdc++.h>

#define ranges std::ranges

using i64 = long long;
using pii = std::pair<int, int>;
using a2 = std::array<int, 2>;

struct dsu {
    std::vector<int> d;
    dsu(int n) { d.resize(n); std::iota(d.begin(), d.end(), 0); }
    int get_root(int u) { return d[u] = (d[u] == u ? u : get_root(d[u])); }
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            return true;
        }
        else return false;
    }
};

struct SAM {
    struct node {
        int len, link, size;
        std::set<a2> endpos;
        std::map<int, int> next;
        node() {
            len = link = -1;
            size = 0;;
            next = std::map<int, int>();
        }
    };

    std::vector<node> nodes;
    int last;
    int n;

    SAM(std::vector<int>& s) {
        n = s.size();
        nodes.reserve(2 * n);
        nodes.assign(1, node());

        nodes[0].len = 0;
        nodes[0].link = -1;
        last = 0;
        int cnt = 0;
        for (int i = 0;i < n;i++)
        {
            cnt++;
            if (s[i] < 0) cnt = 0;
            extend(s[i], i, cnt);
        }
    }

    void extend(int c, int pos, int vaild_len) {
        int cur = nodes.size();
        nodes.emplace_back();
        nodes[cur].len = nodes[last].len + 1;
        int p = last;
        while (p != -1 && !nodes[p].next.count(c)) {
            nodes[p].next[c] = cur;
            p = nodes[p].link;
        }
        if (p == -1 || c < 0) nodes[cur].link = 0;
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
        if (c >= 0) nodes[cur].endpos.insert({ -vaild_len, pos });
        nodes[cur].size = 1;
        last = cur;
    }

    i64 work(dsu& d) {
        std::vector<int> idx(nodes.size());
        std::iota(idx.begin(), idx.end(), 0);
        ranges::sort(idx, [&](int x, int y) {
            if (nodes[x].len == nodes[y].len) return x < y;
            return nodes[x].len > nodes[y].len;
            });
        i64 ans = 0;
        // for (auto x : idx)std::cout << x << ' ';
        for (int x : idx) {
            auto& endpos = nodes[x].endpos;
            // if (x == 271) { for (auto x : endpos)std::cerr << x[1] << ' ' << x[0] << ' ';std::cerr << '\n'; }
            // assert(endpos.size() > 0);
            std::vector<a2> tmp;
            // if (endpos.contains({ -17,90 })) std::cout << x << '\n';
            while (endpos.size()) {
                auto [vaild_len, pos] = *endpos.begin();
                vaild_len = -vaild_len;
                if (vaild_len < nodes[x].len) break;
                tmp.push_back({ -vaild_len, pos });
                endpos.erase(endpos.begin());
            }
            // if (x == 13) { for (auto x : tmp)std::cerr << x[1] << ' ';std::cerr << '\n'; }
            // ranges::sort(tmp, std::greater<a2>());
            for (int i = 1;i < tmp.size();++i) {
                // if (d.get_root(tmp[i - 1][1]) != d.get_root(tmp[i][1])) {
                //     std::cout << tmp[i - 1][1] << ' ' << tmp[i][1] << ' ' << nodes[x].len << '\n';
                // }
                if (d.merge(tmp[i - 1][1], tmp[i][1])) {
                    ans += nodes[x].len;
                }
            }
            // assert(0);
            if (tmp.size())nodes[x].endpos.insert(tmp[0]);
            // assert(0);
            int p = nodes[x].link;
            if (p != -1) {
                if (nodes[p].endpos.size() < nodes[x].endpos.size()) std::swap(nodes[p].endpos, nodes[x].endpos);
                // while (nodes[x].endpos.size()) {
                //     nodes[p].endpos.insert(nodes[x].endpos.begin());
                //     nodes[x].endpos.erase(nodes[x].endpos.begin());
                // }
                for (auto& it : nodes[x].endpos) {
                    nodes[p].endpos.insert(it);
                }
            }
            nodes[x].endpos.clear();
            // std::cout << ans << ' ';
        }
        return ans;
    };

    void debug() {
        int cnt = 0;
        for (auto x : nodes) {
            std::cerr << cnt++ << ' ';
            std::cerr << x.len << ' ';
            std::cerr << x.link << ' ';
            for (auto y : x.endpos) {
                std::cerr << y[1] << ' ';
            }
            std::cerr << '\n';
            // std::cerr << '\n';
            // std::cerr << '\n';
        }
    }
};

void solve() {
    int n;std::cin >> n;
    std::vector<std::string> a(n);
    int len = 0;
    for (auto& x : a)std::cin >> x, len += x.length() + 1;
    dsu d(len + 1);
    int cur = 0;
    std::vector<int> ints;
    for (auto& x : a) {
        for (auto ch : x) {
            ints.push_back(ch - 'a');
        }
        for (int i = cur + 1;i < ints.size();++i) {
            d.merge(i, i - 1);
        }
        ints.push_back(-1);
        cur = ints.size();
    }
    // assert(0);
    // std::cout << '\n';
    // for (auto x : length)std::cerr << x << ' ';
    // std::cout << s << '\n';
    // for (int i = 0;i < s.length();++i)std::cout << d.get_root(i) << ' ';
    SAM sam(ints);
    // sam.debug();
    std::cout << sam.work(d);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
}