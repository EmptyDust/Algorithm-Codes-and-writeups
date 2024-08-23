#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct AhoCorasick {
    static constexpr int ALPHABET = 2;
    static constexpr char ALPHACHAR = '0';
    struct Node {
        int len;
        int link;
        i64 cnt;
        bool end;
        std::array<int, ALPHABET> next;
        Node() : len{ 0 }, link{ 0 }, cnt(0), end(0), next{} {}
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
        t[p].end = true;
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
            t[x].cnt = t[x].end + t[t[x].link].cnt;
        }
    }

    i64 work(const std::string& s) {
        int p = 1;
        i64 ans = 0;

        for (auto& c : s) {
            p = next(p, c - ALPHACHAR);
            ans += t[p].cnt;
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

struct binery_group
{
    std::vector<AhoCorasick> acs;
    std::vector<std::vector<std::string>> strings;
    binery_group() {
        acs.resize(30);
        strings.resize(30);
    }
    void insert(std::string& s) {
        std::vector<std::string> ss{ s };
        for (int i = 0;i < 30;++i) {
            if (strings[i].size()) {
                for (auto& s : strings[i]) {
                    ss.push_back(s);
                }
                strings[i].clear();
            }
            else {
                acs[i] = AhoCorasick();
                for (auto& s : ss)acs[i].add(s);
                acs[i].get_fail();
                strings[i] = ss;
                break;
            }
        }
    }
    i64 query(const std::string& s) {
        i64 res = 0;
        for (int i = 0;i < 30;++i)if (strings[i].size()) {
            res += acs[i].work(s);
        }
        return res;
    }
};

void solve() {
    int n;std::cin >> n;
    binery_group bg;
    int lst = 0;
    while (n--) {
        char ch;std::cin >> ch;
        std::string s;std::cin >> s;
        int len = s.length();
        std::string t(len, '0');
        int shift = lst % len;
        for (int i = 0;i < len;++i) t[i] = s[(i + shift) % len];
        if (ch == '+') {
            bg.insert(t);
        }
        else {
            lst = bg.query(t);
            std::cout << lst << '\n';
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    int idx = 1;
    while (t--) {
        std::cout << "Case #" << idx << ":\n";
        solve();
        idx++;
    }
    return 0;
}