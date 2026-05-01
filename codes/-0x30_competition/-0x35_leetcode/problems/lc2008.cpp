#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long long> dp(n + 1);
        unordered_map<int, vector<vector<int>>> rideMap;
        for (const auto& ride : rides) {
            rideMap[ride[1]].push_back(ride);
        }
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            for (const auto& ride : rideMap[i]) {
                dp[i] = max(dp[i], dp[ride[0]] + ride[1] - ride[0] + ride[2]);
            }
        }
        return dp[n];
    }
};