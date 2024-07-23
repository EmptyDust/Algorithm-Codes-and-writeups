#include <bits/stdc++.h>

#define int long long

//AC自动机
struct AhoCorasick {
    static constexpr int ALPHABET = 26;

    struct Node {
        int len;
        int link;
        std::array<int, ALPHABET> next;

        Node() : len{ 0 }, link{ 0 }, next{} {}
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
        for (auto c : a) {
            int x = c - 'a';
            if (t[p].next[x] == 0) {
                t[p].next[x] = newNode();
                t[t[p].next[x]].len = t[p].len + 1;
            }
            p = t[p].next[x];
        }
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

    int next(int p, int x) { return t[p].next[x]; }

    int link(int p) { return t[p].link; }

    int len(int p) { return t[p].len; }

    int size() { return t.size(); }
};

void solve() {
    std::string s;
    std::cin >> s;

    int n;
    std::cin >> n;

    AhoCorasick ac;

    std::vector<std::string> t(n);
    std::vector<int> end(n);
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
        end[i] = ac.add(t[i]);
    }
    ac.work();

    int p = 1;
    std::vector<int> f(ac.size());
    for (auto c : s) {
        p = ac.next(p, c - 'a');
        f[p]++;
    }

    std::vector<std::vector<int>> adj(ac.size());
    for (int i = 2; i < ac.size(); i++) {
        adj[ac.link(i)].push_back(i);
    }

    std::function<void(int)> dfs = [&](int x) -> void {
        for (auto y : adj[x]) {
            dfs(y);
            f[x] += f[y];
        }
        };
    dfs(1);
    for (int i = 0; i < n; i++) {
        std::cout << f[end[i]] << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    //std::cin >> T;
    while (T--) solve();
    return 0;
}