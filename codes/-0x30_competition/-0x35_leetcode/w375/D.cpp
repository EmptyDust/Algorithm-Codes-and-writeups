#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> bc(n);
        iota(bc.begin(), bc.end(), 0);
        sort(bc.begin(), bc.end(), [&](int a, int b) {return nums[a] < nums[b];});
        vector<vector<int>> vt;
        for (int i = 1;i < n;++i) {
            if (nums[bc[i]] == nums[bc[i - 1]]) {
                if (bc[i - 1] > bc[i])
                    swap(bc[i - 1], bc[i]);
                vt.push_back({ bc[i - 1],bc[i] });
            }
        }
        int k = vt.size();
        sort(vt.begin(), vt.end());
        if (vt.empty()) {
            return mmod(n - 1) % mod;
        }
        int cnt = vt[0][0];
        for (int i = 1;i < k;++i) {
            if (vt[i - 1][1] >= vt[i][0]) {
                vt[i][0] = min(vt[i][0], vt[i - 1][0]);
                vt[i][1] = max(vt[i][1], vt[i - 1][1]);
            }
            else {
                cnt += vt[i][0] - vt[i - 1][1];
            }
        }
        cnt += 1 + n - vt[k - 1][1] - 1;
        return mmod(cnt - 1) % mod;
    }
    long long mmod(int x) {
        if (x == 0)return 1;
        if (x == 1)return 2;
        if (x % 2 == 0)return ((mmod(x / 2) % mod) * (mmod(x / 2) % mod)) % mod;
        return ((((mmod(x / 2) % mod) * (mmod(x / 2) % mod)) % mod) * 2) % mod;
    }
};