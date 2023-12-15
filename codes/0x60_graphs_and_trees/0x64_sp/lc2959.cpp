#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<int>> mp(n, vector<int>(n, INT_MAX / 2));
        for (auto road : roads) if (road[2] < mp[road[0]][road[1]]) {
            mp[road[0]][road[1]] = road[2];
            mp[road[1]][road[0]] = road[2];
        }

        for (int i = 0;i < n;++i)
            mp[i][i] = 0;

        vector<vector<int>> f(n);
        auto check = [&](int s)->bool {
            for (int i = 0;i < n;++i)if ((s >> i) & 1)
                f[i] = mp[i];
            for (int k = 0;k < n;++k) {
                if (((s >> k) & 1) == 0)continue;
                for (int i = 0;i < n;++i) {
                    if (((s >> i) & 1) == 0)continue;
                    for (int j = 0;j < n;++j) {
                        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                    }
                }
            }
            for (int i = 0;i < n;++i) {
                if (((s >> i) & 1) == 0)continue;
                for (int j = 0;j < n;++j)if ((s >> j) & 1 && f[i][j] > maxDistance) {
                    return false;
                }
            }
            return true;
            };

        int ans = 0;
        for (int i = 0;i < (1 << n);++i)
            ans += check(i);
        return ans;
    }
};