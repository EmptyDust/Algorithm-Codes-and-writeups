//2023.11.11
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int T; cin >> T;
    vector<int> nums(T);
    for (int i = 0; i < T; ++i)cin >> nums[i];
    vector<int> segment_tree(4 * T, 0);
    function<int(int, int, int)> set_up = [&](int id, int l, int r)->int {
        int& ret = segment_tree[id - 1];
        if (l == r)
            return ret = nums[l];
        return ret = set_up(id * 2, l, (l + r) >> 1) + set_up(id * 2 + 1, ((l + r) >> 1) + 1, r);
        };
    set_up(1, 0, T - 1);
    for (int num : segment_tree) {
        if (num == 0)break;
        cout << num << " ";
    }
    return 0;
}