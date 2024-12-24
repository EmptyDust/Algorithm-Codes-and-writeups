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

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void insert_sort(std::vector<int> a) {
    int n = a.size();
    std::cout << "insert_sort\n";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < n;++i)
        for (int j = 0;j < i;++j)
            if (a[i] < a[j])
                std::swap(a[j], a[i]);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    std::cout << "Elapsed time: " << duration << " ms\n";
    // for (int x : a)std::cout << x << ' ';std::cout << '\n';
}

void bobble_sort(std::vector<int> a) {
    int n = a.size();
    std::cout << "bobble_sort\n";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < n;++i)
        for (int j = 0;j < n - 1;++j)
            if (a[j] > a[j + 1])
                std::swap(a[j], a[j + 1]);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    std::cout << "Elapsed time: " << duration << " ms\n";
    // for (int x : a)std::cout << x << ' ';std::cout << '\n';
}

void select_sort(std::vector<int> a) {
    int n = a.size();
    std::cout << "select_sort\n";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < n;++i)
        for (int j = i + 1;j < n;++j)
            if (a[i] > a[j])
                std::swap(a[i], a[j]);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    std::cout << "Elapsed time: " << duration << " ms\n";
    // for (int x : a)std::cout << x << ' ';std::cout << '\n';
}

void quick_sort(std::vector<int> a) {
    int n = a.size();
    std::cout << "quick_sort\n";
    auto dfs = [&](auto&& self, int l, int r) ->void {
        if (l >= r)return;
        int i = l - 1, j = r + 1, x = a[l + r >> 1];
        while (i < j)
        {
            do i++; while (a[i] < x);
            do j--; while (a[j] > x);
            if (i < j) std::swap(a[i], a[j]);
        }
        self(self, l, j), self(self, j + 1, r);
        };
    auto start = std::chrono::high_resolution_clock::now();
    dfs(dfs, 0, n - 1);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    std::cout << "Elapsed time: " << duration << " ms\n";
    // for (int x : a)std::cout << x << ' ';std::cout << '\n';
}

void heap_sort(std::vector<int> a) {
    int n = a.size();
    std::cout << "heap_sort\n";
    auto sift_down = [&](int start, int end) {
        int parent = start;
        int child = parent * 2 + 1;
        while (child <= end) {
            if (child + 1 <= end && a[child] < a[child + 1]) child++;
            if (a[parent] >= a[child])
                return;
            else {
                std::swap(a[parent], a[child]);
                parent = child;
                child = parent * 2 + 1;
            }
        }
        };

    auto heap_sort = [&](int len) {
        for (int i = (len - 1 - 1) / 2; i >= 0; i--) sift_down(i, len - 1);
        for (int i = len - 1; i > 0; i--) {
            std::swap(a[0], a[i]);
            sift_down(0, i - 1);
        }
        };

    auto start = std::chrono::high_resolution_clock::now();
    heap_sort(n);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    std::cout << "Elapsed time: " << duration << " ms\n";
}

void std_sort(std::vector<int> a) {
    int n = a.size();
    std::cout << "cpp_std_sort\n";
    auto start = std::chrono::high_resolution_clock::now();
    ranges::sort(a);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    std::cout << "Elapsed time: " << duration << " ms\n";
}

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)x = rng() % 100;
    insert_sort(a);
    bobble_sort(a);
    select_sort(a);
    quick_sort(a);
    heap_sort(a);
    std_sort(a);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}