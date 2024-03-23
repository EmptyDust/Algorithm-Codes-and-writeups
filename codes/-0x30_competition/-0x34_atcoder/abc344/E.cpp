#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

struct node {
    int pre = -1, suf = -1;
} nodes[MAXN];

struct query {
    int op, x, y = -1;
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0;i < n;++i)
        std::cin >> nums[i];
    std::vector<int> ls(nums);
    int q;std::cin >> q;
    std::vector<query> qry(q);
    for (int i = 0;i < q;++i) {
        int op, x;std::cin >> op >> x;
        if (op == 1) {
            int y;std::cin >> y;
            qry[i] = { op,x,y };
            ls.push_back(y);
        }
        else {
            qry[i] = { op,x };
        }
    }
    std::vector<int> zbs(ls.size());
    iota(zbs.begin(), zbs.end(), 0);
    sort(zbs.begin(), zbs.end(), [&](int a, int b) {return ls[a] < ls[b];});
    std::map<int, int> mp;
    for (int i = 0;i < ls.size();++i)mp[ls[zbs[i]]] = i + 1;

    for (int i = 0;i < nums.size();++i) {
        if (i)nodes[mp[nums[i]]].pre = mp[nums[i - 1]];
        if (i != nums.size() - 1)nodes[mp[nums[i]]].suf = mp[nums[i + 1]];
    }
    nodes[mp[nums[0]]].pre = 0;
    nodes[0].suf = mp[nums[0]];
    nodes[mp[nums[nums.size() - 1]]].suf = 1e6;
    nodes[(int)1e6].pre = mp[nums[nums.size() - 1]];

    for (query q : qry) {
        if (q.op == 1) {
            nodes[mp[q.y]].suf = nodes[mp[q.x]].suf;
            nodes[mp[q.y]].pre = mp[q.x];
            nodes[mp[q.x]].suf = mp[q.y];
        }
        else {
            nodes[nodes[mp[q.x]].suf].pre = nodes[mp[q.x]].pre;
            nodes[nodes[mp[q.x]].pre].suf = nodes[mp[q.x]].suf;
        }
    }

    int x = 0;
    while (1) {
        x = nodes[x].suf;
        if (x == 1000000)break;
        std::cout << ls[zbs[x - 1]] << ' ';
    }
    return 0;
}