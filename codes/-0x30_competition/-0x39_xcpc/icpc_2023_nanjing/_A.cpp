#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define SPACE ' '
#define endl '\n'

using i64 = long long;
using u64 = unsigned long long;

struct Block {
    int size, x, y;
    vector<pair<int, int>> cells;
    bool valid = true;
};

constexpr int dx[4] = { 1, -1, 0, 0 };
constexpr int dy[4] = { 0, 0, 1, -1 };

void solve() {
    int n, m; cin >> n >> m;
    vector mp(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        cin.get();
        for (int j = 0; j < m; j++) {
            mp[i][j] = (cin.get() == '.' ? 0 : 1);
        }
    }
    vector<Block> blocks;
    vector block_id(n, vector<int>(m, -1));
    auto bfs = [&](int init_x, int init_y) {
        queue<pair<int, int>> q;
        q.emplace(init_x, init_y);
        mp[init_x][init_y] = 2;
        int id = blocks.size();
        block_id[init_x][init_y] = id;
        int size = 0, min_x = init_x, min_y = init_y;
        vector<pair<int, int>> cells;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            cells.emplace_back(x, y);
            size++, min_x = min(min_x, x), min_y = min(min_y, y);
            for (int d = 0; d < 4; d++) {
                int tx = x + dx[d], ty = y + dy[d];
                if (tx >= n || ty >= m || mp[tx][ty]) continue;
                mp[tx][ty] = 2;
                block_id[tx][ty] = id;
                q.emplace(tx, ty);
            }
        }
        for (auto& [tx, ty] : cells) tx -= min_x, ty -= min_y;
        blocks.emplace_back(size, min_x, min_y, move(cells));
        };
    for (int x = 0; x < n; x++) for (int y = 0; y < m; y++) {
        if (!mp[x][y]) bfs(x, y);
    }
    int Bsize = blocks.size();
    // ranges::sort(blocks, {}, &Block::size);
    for (int i = 0; i < Bsize; i++) {
        if (!blocks[i].valid) continue;
        for (int j = 0; j < Bsize; j++) {
            if (i == j) continue;
            if (!blocks[j].valid) continue;
            if (blocks[i].size > blocks[j].size) continue;
            auto jx = blocks[j].x, jy = blocks[j].y;
            bool flag = false;
            for (auto& [ox, oy] : blocks[j].cells) {
                bool match = true;
                for (auto& [cx, cy] : blocks[i].cells) {
                    int tx = jx + cx + ox, ty = jy + cy + oy;
                    // cout << format("{} {} {}?{}", tx, ty, block_id[tx][ty], j) << endl;
                    if (tx >= n || ty >= m || block_id[tx][ty] != j) {
                        match = false;
                        break;
                    }
                }
                // cout << format("{} and {} is {}", i, j, match) << endl;
                if (match) { flag = true; break; }
            }
            if (flag) {
                blocks[i].valid = false;
                if (blocks[i].size == blocks[j].size) blocks[j].valid = false;
                break;
            }
        }
    }
    int ans = 0;
    for (auto& b : blocks) if (b.valid) ans += b.size;
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}