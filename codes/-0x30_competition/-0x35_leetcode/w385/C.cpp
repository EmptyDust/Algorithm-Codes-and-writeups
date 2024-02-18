#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int s = 1;
        for (int i = 0;i < max(n, m);++i)s *= 10;
        vector<bool> prime(s, true);
        for (int i = 2;i < sqrt(s);++i)if (prime[i])
            for (int j = i;i * j < s;++j)prime[i * j] = false;
        map<int, int> cnt;
        for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
            int num = 0;
            int x = i, y = j;
            while (x < n) {
                num = num * 10 + mat[x][y];
                if (prime[num])cnt[num]++;
                ++x;
            }
            num = 0;
            x = i, y = j;
            while (y < m) {
                num = num * 10 + mat[x][y];
                if (prime[num])cnt[num]++;
                ++y;
            }
            num = 0;
            x = i, y = j;
            while (x >= 0) {
                num = num * 10 + mat[x][y];
                if (prime[num])cnt[num]++;
                --x;
            }
            num = 0;
            x = i, y = j;
            while (y >= 0) {
                num = num * 10 + mat[x][y];
                if (prime[num])cnt[num]++;
                --y;
            }
            num = 0;
            x = i, y = j;
            while (x < n && y < m) {
                num = num * 10 + mat[x][y];
                if (prime[num])cnt[num]++;
                ++x, ++y;
            }
            num = 0;
            x = i, y = j;
            while (x >= 0 && y >= 0) {
                num = num * 10 + mat[x][y];
                if (prime[num])cnt[num]++;
                --x, --y;
            }
            num = 0;
            x = i, y = j;
            while (x >= 0 && y < m) {
                num = num * 10 + mat[x][y];
                if (prime[num])cnt[num]++;
                --x, ++y;
            }
            num = 0;
            x = i, y = j;
            while (x < n && y >= 0) {
                num = num * 10 + mat[x][y];
                if (prime[num])cnt[num]++;
                ++x, --y;
            }
        }
        int ans = -1, ccnt = 0;
        for (auto [i, f] : cnt) {
            if (i > 10 && f > ccnt)
                ans = i, ccnt = f;
            if (i > 10 && f == ccnt && i > ans)
                ans = i;
        }
        return ans;
    }
};