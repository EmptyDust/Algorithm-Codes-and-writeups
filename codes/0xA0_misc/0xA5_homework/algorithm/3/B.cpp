#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    // 读取 n
    if (!(cin >> n)) return;

    int m = 1 << n; 

    vector<vector<double>> P(m, vector<double>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> P[i][j];
        }
    }

    vector<double> dp(m, 1.0);

    for (int r = 0; r < n; ++r) {
        vector<double> next_dp(m, 0.0);
        int half_size = 1 << r;

        for (int i = 0; i < m; ++i) {
            int start = (i ^ half_size) & ~(half_size - 1);
            int end = start + half_size;

            double win_prob = 0.0;
            for (int k = start; k < end; ++k) {
                win_prob += dp[k] * P[i][k];
            }

            next_dp[i] = dp[i] * win_prob;
        }
        dp = next_dp;
    }

    int best_team = 0;
    for (int i = 1; i < m; ++i) {
        if (dp[i] > dp[best_team]) {
            best_team = i;
        }
    }

    cout << best_team + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}