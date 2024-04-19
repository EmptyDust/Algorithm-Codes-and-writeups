#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

struct Matrix {
    std::vector<std::vector<i64>> matrix;
    int n, m;
    Matrix(int x) { _init(x, x);_build(); }
    Matrix(int n, int m) { _init(n, m); }
    void _init(int n, int m) { matrix.assign(n, std::vector<i64>(m, 0));this->n = n;this->m = m; }
    void _build() { assert(n == m); for (int i = 0;i < n;++i)matrix[i][i] = 1; }
    void input() { for (int i = 0;i < n;++i)for (int j = 0;j < m;++j)std::cin >> matrix[i][j]; }
    void print() { for (int i = 0;i < n;++i) { for (int j = 0;j < m;++j)std::cout << matrix[i][j] << ' ';std::cout << '\n'; } }
    void operator*=(Matrix& s) { *this = *this * s; }
    Matrix operator*(Matrix& s) {
        assert(m == s.n);
        Matrix res = *(new Matrix(n, s.m));
        for (int i = 0;i < n;++i)
            for (int j = 0;j < s.m;++j)
                for (int k = 0;k < m;++k)
                    res.matrix[i][j] = (res.matrix[i][j] + matrix[i][k] * s.matrix[k][j] % mod) % mod;
        return res;
    }
    void operator+=(Matrix& s) { *this = *this + s; }
    Matrix operator+(Matrix& s) {
        assert(m == s.m && n == s.n);
        Matrix res = *(new Matrix(n, m));
        for (int i = 0;i < n;++i)
            for (int j = 0;j < s.m;++j)
                res.matrix[i][j] = (matrix[i][j] + s.matrix[i][j]) % mod;
        return res;
    }
    Matrix qpow(i64 x) {
        assert(n == m);
        Matrix res = *(new Matrix(n)), tmp = (*this);
        while (x) {
            if (x & 1)res *= tmp;
            tmp *= tmp;
            x >>= 1;
        }
        return res;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 n, p;
    std::cin >> n >> p;
    Matrix x = *(new Matrix(n));x.input();
    x = x.qpow(p);x.print();
    return 0;
}