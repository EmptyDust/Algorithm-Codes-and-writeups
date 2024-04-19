#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size();
        int m = andValues.size();
        vector<vector<int>> zb(n, vector<int>(30, -1));
        for (int s = 0;s < 30;++s) {
            int cur = -1;
            for (int i = 0;i < n;++i) {
                if (nums[i] >> s & 1) {
                    if (cur == -1)cur = i;
                    zb[i][s] = cur;
                }
                else cur = -1;
            }
        }

        vector<int> lg(n + 1);
        for (int i = 2;i <= n;i++) lg[i] = lg[i >> 1] + 1;

        vector<vector<int>> f(n, vector<int>(10, 1e9));
        int res = nums[0];
        for (int i = 0;i < n;++i) {
            res &= nums[i];
            if (res == andValues[0]) {
                f[i][0] = nums[i];
            }
            if (res < andValues[0])break;
        }
        for (int w = 1;w < m;++w) {
            vector<vector<int>> st(n, vector<int>(30, -1));
            for (int i = 0;i < n;++i) st[i][0] = f[i][w - 1];
            for (int s = 1;s <= lg[n];++s) {
                for (int i = 0;i < n;++i) {
                    if (i + (1 << (s - 1)) < n)
                        st[i][s] = std::min(st[i][s - 1], st[i + (1 << (s - 1))][s - 1]);
                    else
                        st[i][s] = st[i][s - 1];
                }
            }
            for (int i = 0;i < n;++i) {
                res = nums[i];
                int a = 0, b = i + 1;//a最早消失的需求位，b最晚消失的不要位
                bool ff = true;
                for (int s = 0;s < 30;++s) {
                    if (andValues[w] >> s & 1) {
                        if (zb[i][s] == -1) {
                            ff = false;
                            break;
                        }
                        a = std::max(a, zb[i][s]);
                    }
                    else {
                        if (zb[i][s] == -1)continue;
                        b = std::min(b, zb[i][s]);
                    }
                }
                if (!ff || a >= b || b < 2)continue;
                int l = std::max(a - 1, 0), r = b - 2;
                int len = lg[r - l + 1];
                f[i][w] = std::min(f[i][w], std::min(st[l][len], st[r - (1 << len) + 1][len]) + nums[i]);
            }
        }
        return (f[n - 1][m - 1] == 1e9 ? -1 : f[n - 1][m - 1]);
    }
};