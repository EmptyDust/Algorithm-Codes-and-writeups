#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

struct Matrix
{
    std::vector<a3> data;
    int col, row;
    Matrix() {}
    Matrix(int col, int row) :col(col), row(row) {}
    Matrix(std::vector<a3> data, int col, int row) :data(data), col(col), row(row) {
        std::sort(data.begin(), data.end());
    }
    Matrix operator+(Matrix mat) {
        if (col != mat.col || row != mat.row)return Matrix();
        Matrix c(mat.data, col, row);
        for (auto& [a, b, x] : data) {
            bool f = true;
            for (auto& [A, B, X] : c.data) {
                if (a == A && b == B) {
                    X += x;
                    f = false;
                }
            }
            if (f)c.data.push_back({ a,b,x });
        }
        std::sort(c.data.begin(), c.data.end());
        return c;
    }
    bool operator==(Matrix& mat) {
        return data == mat.data && col == mat.col && row == mat.row;
    }
    bool symmetric(Matrix& mat) {
        for (auto& [a, b, x] : data) {
            bool f = false;
            for (auto& [A, B, X] : mat.data) {
                if (a == b && A == B && x == X) {
                    f = true;
                    break;
                }
            }
            if (!f)return false;
        }
        return true;
    }
    Matrix transpose() {
        Matrix c(row, col);
        for (auto& [a, b, x] : data) {
            c.data.push_back({ b,a,x });
        }
        return c;
    }
    void print() {
        for (auto [a, b, x] : data) {
            std::cout << a << ' ' << b << ' ' << x << '\n';
        }
    }
    void print2() {
        std::vector map(col, std::vector<int>(row));
        for (auto [a, b, x] : data) {
            map[a][b] = x;
        }
        for (auto& vt : map) {
            for (auto& x : vt) {
                std::cout << x << ' ';
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
};

Matrix input() {
    int n, col, row;std::cin >> n >> col >> row;
    std::vector<a3> A;
    for (int i = 0;i < n;++i) {
        int a, b, x;std::cin >> a >> b >> x;
        A.push_back({ a,b,x });
    }
    return Matrix(A, col, row);
}

void solve() {
    Matrix A = input();
    Matrix B = input();
    A.transpose().print2();
    B.transpose().print2();
    (A.transpose() + B.transpose()).print2();
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}