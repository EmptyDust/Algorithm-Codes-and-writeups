#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

bool check(int h, int w, int n, std::vector<int>& A, std::vector<int>& B) {
    std::vector<std::vector<bool>> map(h, std::vector<bool>(w, false));
    int ID = 0;
    for (int a = 0;a < h;a++)for (int b = 0;b < w;b++)if (!map[a][b]) {
        if (ID == n)return false;
        if (a + A[ID] > h || b + B[ID] > w)return false;
        for (int c = a;c < a + A[ID];c++) {
            for (int d = b;d < b + B[ID];d++) {
                if (map[c][d])return false;
                map[c][d] = true;
            }
        }
        ID++;
    }
    return true;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, h, w;
    std::cin >> n >> h >> w;
    std::vector<int> A(n), B(n), idx(n);
    for (int i = 0;i < n;++i) {
        std::cin >> A[i] >> B[i];
        idx[i] = i;
    }
    std::vector<int> a(n), b(n);
    do {
        for (int i = 0;i < n;++i) {
            a[i] = A[idx[i]];
            b[i] = B[idx[i]];
        }
        for (int s = 0;s < (1 << n);++s) {
            for (int k = 0;k < n;++k)if (s & (1 << k))
                std::swap(a[k], b[k]);
            if (check(h, w, n, a, b)) {
                std::cout << "Yes";
                return 0;
            }
            for (int k = 0;k < n;++k)if (s & (1 << k))
                std::swap(a[k], b[k]);
        }
    } while (std::next_permutation(idx.begin(), idx.end()));
    std::cout << "No";
    return 0;
}