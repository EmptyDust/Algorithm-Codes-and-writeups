#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e3, MAXN = 1e3 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

double multiple[MAXN][MAXN];
void init(double q) {
    multiple[0][0] = 1;
    for (int i = 0;i <= N;++i) {
        for (int j = 0;j <= N;++j) {
            if (!i && !j)continue;
            if (!i)multiple[i][j] = std::max(
                multiple[i][j - 1] * q,
                multiple[i][j - 1] * (1 - q)
            );
            else if (!j)multiple[i][j] = std::max(
                multiple[i - 1][j] * q,
                multiple[i - 1][j] * (1 - q)
            );
            else multiple[i][j] = std::max(
                multiple[i - 1][j] * (1 - q) + multiple[i][j - 1] * q,
                multiple[i - 1][j] * q + multiple[i][j - 1] * (1 - q)
            );
        }
    }
}

struct Trie {
    static constexpr int ALPHABET = 2;
    struct Node {
        int len;
        int link;
        std::array<int, ALPHABET> next;
        Node() : len{ 0 }, link{ 0 }, next{} {}
    };

    std::vector<Node> t;
    std::vector<int> cnt;

    Trie() {
        init();
    }

    void init() {
        t.assign(2, Node());
        cnt.assign(2, 0);
        t[0].next.fill(1);
        t[0].len = -1;
    }

    int newNode() {
        t.emplace_back();
        cnt.emplace_back();
        return t.size() - 1;
    }

    int add(const std::string& a) {
        int p = 1;
        cnt[1]++;
        for (auto c : a) {
            int x = c - '0';
            if (t[p].next[x] == 0) {
                t[p].next[x] = newNode();
                t[t[p].next[x]].len = t[p].len + 1;
            }
            p = t[p].next[x];
            cnt[p]++;
            // std::cout << p << ' ';
        }
        return p;
    }

    double work() {
        std::queue<int> q;
        q.push(1);
        double ans = 1;
        while (q.size()) {
            auto x = q.front();
            q.pop();
            if (cnt[t[x].next[0]] == 0 && cnt[t[x].next[1]] == 0)continue;
            int sum = cnt[x];
            int a = cnt[t[x].next[0]];
            int b = cnt[t[x].next[1]];
            // std::cout << sum << ' ' << a << ' ' << b << " " << multiple[a][b] << '\n';
            ans *= multiple[a][b];
            for (int i = 0;i < 2;++i)if (cnt[t[x].next[i]]) {
                q.push(t[x].next[i]);
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
    int n, m;double p;
    std::cin >> n >> m >> p;
    init(p);
    Trie trie;
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        trie.add(s);
    }
    std::cout.precision(12);
    std::cout << trie.work();

    return 0;
}