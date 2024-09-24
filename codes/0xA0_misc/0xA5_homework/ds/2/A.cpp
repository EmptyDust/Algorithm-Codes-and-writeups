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


template<class T>
class List {
private:
    std::vector<T> data;
public:
    void clear() {
        data.clear();
    }
    int length() {
        return data.size();
    }
    int get(int i) {
        if (i >= data.size())return -1;
        return data[i - 1];
    }
    void insert(int i, T x) {
        if (i > data.size()) {
            std::cerr << "Array Index Out of Bounds\n";
            return;
        }
        int sz = data.size();
        data.resize(sz + 1);
        for (int j = sz - 1;j >= std::max(i - 1, 0);--j) {
            data[j + 1] = data[j];
        }
        data[i] = x;
    }
    void remove(int i) {
        if (i > data.size()) {
            std::cerr << "Array Index Out of Bounds\n";
            return;
        }
        --i;
        for (;i < (int)data.size() - 1;++i) {
            data[i] = data[i + 1];
        }
        data.pop_back();
    }
    int indexof(T x) {
        for (int i = 0;i < data.size();++i) {
            if (x == data[i])return i + 1;
        }
        return -1;
    }
    void reverse() {
        for (int i = 0, j = (int)data.size() - 1;i < j;++i, --j) {
            std::swap(data[i], data[j]);
        }
    }
    void display() {
        for (auto x : data)std::cout << x << ' ';
        std::cout << '\n';
    }
};

void solve() {
    List<int> list;
    for (int i = 1;i <= 10;++i)list.insert(0, i);
    list.display();
    list.reverse();
    list.display();
    std::cout << list.indexof(5) << '\n';
    list.remove(5);
    list.display();
    std::cout << list.get(5) << '\n';
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