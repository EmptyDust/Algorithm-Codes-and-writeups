#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

int query(int pos, int lq, int rq) {
    std::cout << 0 << ' ';
    for (int i = 1;i <= pos;++i)std::cout << lq << ' ';
    for (int i = pos + 1;i <= n;++i)std::cout << rq << ' ';
    std::cout << std::endl;
    int num = -1;
    std::cin >> num;
    if (num == -1)exit(0);
    return num;
}

void solve(int l, int r, std::vector<int>& vt) {
    if (l > r)return;
    if (l == r) {
        nums[l] = vt.front();
        return;
    }
    std::vector<int> lvt, rvt, wait;
    int sz = vt.size();
    int mid = l + r >> 1;
    int llen = mid - l + 1, rlen = r - mid;
    for (int x : vt) {
        if (lvt.size() == llen) {
            rvt.push_back(x);
            continue;
        }
        if (rvt.size() == rlen) {
            lvt.push_back(x);
            continue;
        }
        if (wait.empty()) {
            wait.push_back(x);
            continue;
        }
        int status = query(mid, wait.back(), x);
        switch (status)
        {
        case 0:
            lvt.push_back(x);
            for (int y : wait)
                rvt.push_back(y);
            wait.clear();
            break;
        case 1:
            wait.push_back(x);
            break;
        case 2:
            rvt.push_back(x);
            for (int y : wait)
                lvt.push_back(y);
            wait.clear();
        }
    }
    solve(l, mid, lvt);
    solve(mid + 1, r, rvt);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    std::vector<int> vt(n);
    std::iota(vt.begin(), vt.end(), 1);
    solve(1, n, vt);
    std::cout << 1 << ' ';
    for (int i = 1;i <= n;++i)std::cout << nums[i] << ' ';
    std::cout << std::endl;
    return 0;
}