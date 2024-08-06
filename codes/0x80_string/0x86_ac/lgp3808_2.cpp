#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct AhoCorasick {
    static constexpr int ALPHABET = 26;
    static constexpr char ALPHACHAR = 'a';
    struct Node {
        int len;
        int link;
        int w;
        std::array<int, ALPHABET> next;
        Node() : len{ 0 }, link{ 0 }, w(0), next{} {}
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

    int add(const std::string& a) {
        int p = 1;
        for (auto& c : a) {
            int x = c - ALPHACHAR;
            if (t[p].next[x] == 0) {
                t[p].next[x] = newNode();
                t[t[p].next[x]].len = t[p].len + 1;
            }
            p = t[p].next[x];
        }
        t[p].w++;
        return p;
    }

    void get_fail() {
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

    int work(const std::string& s) {
        int p = 1;
        int ans = 0;

        std::unordered_set<int> st;
        for (auto& c : s) {
            p = next(p, c - ALPHACHAR);
            int x = p;
            while (x > 1 && !st.count(x)) {
                ans += t[x].w;
                st.insert(x);
                x = link(x);
            }
        }

        return ans;
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

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    AhoCorasick ac = AhoCorasick();
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        ac.add(s);
    }
    ac.get_fail();
    std::string t;std::cin >> t;
    std::cout << ac.work(t);
    return 0;
}
