#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, v;
    cin >> n >> v;
    vector<int> dp(v + 1, 0);
    while (n--) {
        int w, value, s;
        cin >> w >> value >> s;
        int j = 1;
        while (j <= s) {
            for (int i = v; i >= w; i--)
                if (w * j <= i) 
                    dp[i] = max(dp[i], dp[i - w * j] + value * j);
            s -= j;
            j <<= 1;
        }
        if (s > 0)
            for (int i = v; i >= w; i--)
                if(i >= w * s)
                    dp[i] = max(dp[i], dp[i - w * s] + value * s);
    }
    cout << dp[v];
    return 0;
}