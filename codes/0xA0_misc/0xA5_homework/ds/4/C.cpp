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
class IQueue {
    std::vector<T> data;
    int size = 0;
    int len = 0, head = 0, tail = 0;
public:
    IQueue(int size) {
        if (size < 0)size = 1;
        data.resize(size);
        this->size = size;
    }
    void clear() {
        head = tail = 0;
        len = 0;
    }
    bool isEmpty() {
        return len == 0;
    }
    int length() {
        return len;
    }
    T peek() {
        if (len == 0)return T();
        return data[tail];
    }
    T del() {
        if (len == 0)return T();
        auto r = data[tail];
        tail = (tail + 1) % size;
        len--;
        return r;
    }
    void insert(T x) {
        if (len == size)return;
        data[head] = x;
        head = (head + 1) % size;
        len++;
    }
    void display() {
        std::vector<T> res;
        for (int i = tail;i != head;i = (i + 1) % size) {
            res.push_back(data[i]);
        }
        ranges::reverse(res);
        for (T x : res)std::cout << x << " ";
    }
};

void solve() {
    IQueue<int> queue(3);
    std::cout << queue.isEmpty() << '\n';
    queue.insert(1);
    std::cout << queue.length() << '\n';
    queue.insert(2);
    queue.display();
    std::cout << '\n';
    std::cout << queue.peek() << '\n';
    queue.del();
    std::cout << queue.del() << '\n';
    queue.insert(3);
    std::cout << queue.length() << '\n';
    queue.clear();
    std::cout << queue.length() << '\n';
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