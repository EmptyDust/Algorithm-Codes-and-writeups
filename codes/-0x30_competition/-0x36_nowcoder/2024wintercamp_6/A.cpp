#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e2 + 10, mod = 1e9 + 7;
bool prime[MAXN];
vector<int> adj[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    for (int i = 0;i < 100;++i)prime[i] = 1;
    for (int i = 2;i < 100;++i)if (prime[i]) {
        for (int j = i;i * j < 100;++j) {
            prime[i * j] = 0;
        }
    }
    vector<int> primes;
    for (int i = 2;i < 100;++i)if (prime[i])primes.push_back(i);
    int l, r;
    cin >> l >> r;
    int n = primes.size();
    for (int i = 0;i < n;++i)
        for (int j = i + 1;j < n;++j)
            for (int k = j + 1;k < n;++k) {
                int num = primes[i] * primes[j] * primes[k];
                if (l <= num && num <= r) {
                    cout << num;
                    return 0;
                }
            }
    cout << -1;
    return 0;
}