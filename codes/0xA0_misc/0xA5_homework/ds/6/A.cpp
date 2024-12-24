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

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

struct Binery_Tree
{
    int node_cnt = 0;
    int dep = 0;
    int leave_cnt = 0;
    struct node
    {
        int id;
        int data;
        // node() {
        //     data = rng();
        // }
        node* left, * right;
    }*root = new node();
    Binery_Tree() {
        init(root, 0);
    }
    bool rand(int p) {
        // 随机刷新子节点，刷新可能性随层数升高而降低。
        int c = cos(p / 4.0) * mod;
        int r = rng() % mod;
        return c > r;
    }
    void init(node* x, int p) {
        if (rand(p)) {
            x->left = new node();
            x->left->id = ++node_cnt;
            init(x->left, p + 1);
        }
        if (rand(p)) {
            x->right = new node();
            x->right->id = ++node_cnt;
            init(x->right, p + 1);
        }
        dep = std::max(dep, p);
        if (!x->right && !x->left)leave_cnt++;
    }
    void dfs1() {
        auto dfs = [&](auto&& self, node* r) ->void {
            std::cout << r->id << ' ';
            if (r->left)self(self, r->left);
            if (r->right)self(self, r->right);
            };
        dfs(dfs, root);
        std::cout << '\n';
    }
    void dfs2() {
        auto dfs = [&](auto&& self, node* r) ->void {
            if (r->left)self(self, r->left);
            std::cout << r->id << ' ';
            if (r->right)self(self, r->right);
            };
        dfs(dfs, root);
        std::cout << '\n';
    }
    void dfs3() {
        auto dfs = [&](auto&& self, node* r) ->void {
            if (r->left)self(self, r->left);
            if (r->right)self(self, r->right);
            std::cout << r->id << ' ';
            };
        dfs(dfs, root);
        std::cout << '\n';
    }
    void bfs() {
        std::queue<node*> c;
        c.push(root);
        while (c.size()) {
            auto x = c.front();
            std::cout << x->id << ' ';
            c.pop();
            if (x->left) c.push(x->left);
            if (x->right) c.push(x->right);
        }
        std::cout << '\n';
    }
    int depth() {
        return dep;
    }
    int find(int id) {
        std::queue<node*> c;
        c.push(root);
        while (c.size()) {
            auto x = c.front();
            if (x->id == id)return x->data;
            c.pop();
            if (x->left) c.push(x->left);
            if (x->right) c.push(x->right);
        }
        return 0;
    }
    bool complete() {
        return (1 << depth()) - 1 == node_cnt;
    }
};


void solve() {
    Binery_Tree bt;
    std::cout << bt.complete() << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}