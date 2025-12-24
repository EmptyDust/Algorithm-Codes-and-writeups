#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));

    for (int i = 0; i < n; ++i) {
        dp[i][1] = 1;
    }

    for (int l = 2; l <= k; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int p = 0; p < i; ++p) {
                if (a[p] < a[i]) {
                    dp[i][l] += dp[p][l - 1];
                }
            }
        }
    }

    long long total = 0;
    for (int i = 0; i < n; ++i) {
        total += dp[i][k];
    }

    cout << total << endl;

    return 0;
}