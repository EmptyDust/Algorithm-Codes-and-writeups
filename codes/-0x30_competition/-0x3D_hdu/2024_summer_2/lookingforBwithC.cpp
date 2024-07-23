#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct Trie
{
    std::vector<int> end;
    Trie* tries[26];
    Trie* fail;
    Trie* Fa;
    char ch;
    bool vis = false;
    void join_trie(std::string& s, int id) {
        Trie* cur = this;
        for (char ch : s) {
            int c = ch - 'a';
            if (!cur->tries[c]) {
                cur->tries[c] = new Trie();
                cur->tries[c]->Fa = cur;
                cur->tries[c]->ch = ch;
            }
            cur = cur->tries[c];
        }
        cur->end.push_back(id);
    }
    void get_fail() {
        fail = this;
        std::queue<Trie*> q;
        for (int i = 0;i < 26;++i)if (tries[i]) {
            q.push(tries[i]);
        }
        while (q.size()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0;i < 26;++i)if (cur->tries[i]) {
                q.push(cur->tries[i]);
            }
            cur->fail = this;
            if (cur->Fa == this)continue;
            auto next = cur->Fa->fail;
            // if (cur->Fa->ch == 'a' && cur->ch == 's')
            //     if (cur->Fa->fail == this)std::cout << "WIN\n";
            while (next) {
                if (next->tries[cur->ch - 'a']) {
                    cur->fail = next->tries[cur->ch - 'a'];
                    break;
                }
                if (next == this)break;
                next = next->fail;
            }
        }
    }
    std::vector<int> work(std::string s) {
        auto cur = this;
        std::vector<int> ans;
        for (char ch : s) {
            int c = ch - 'a';
            while (!cur->tries[c] && cur != this) {
                cur = cur->fail;
            }
            if (cur->tries[c]) {
                cur = cur->tries[c];
            }
            // cur->print();
            auto next = cur;
            while (!next->vis) {
                for (int x : next->end)ans.push_back(x);
                next->vis = true;
                next = next->fail;
            }
        }
        std::ranges::sort(ans);
        return ans;
    }
    void clear() {
        for (int i = 0;i < 26;++i)if (tries[i]) {
            tries[i]->clear();
        }
        delete this;
    }
    void print() {
        auto cur = this;
        std::string s;
        while (cur->fail != cur) {
            s.push_back(cur->ch);
            cur = cur->Fa;
        }
        std::reverse(s.begin(), s.end());
        std::cout << s << '\n';
    }
};

bool kmp(std::string& s, std::string& t) {
    if (t.length() > s.length())return false;
    std::vector<int> next(t.size());
    next[0] = -1;
    for (int i = 0, j = -1; i < (int)t.size();) {
        if (j == -1 || t[i] == t[j]) {
            ++i, ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }

    for (int i = 0, j = 0; i < (int)s.size() && j < (int)t.size();) {
        if (j == -1 || s[i] == t[j]) {
            ++i, ++j;
        }
        else
            j = next[j];
        if (j == (int)t.size())return true;
    }
    return false;
}

void solve() {
    int n;std::cin >> n;
    std::string a, c;std::cin >> a >> c;
    Trie* trie = new Trie();
    for (int i = 1;i <= n;++i) {
        std::string b, b_;
        std::cin >> b >> b_;
        if (kmp(b_, c)) {
            trie->join_trie(b, i);
        }
    }
    trie->get_fail();
    auto ans = trie->work(a);
    for (int i = 0;i < ans.size();++i)
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    trie->clear();
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}