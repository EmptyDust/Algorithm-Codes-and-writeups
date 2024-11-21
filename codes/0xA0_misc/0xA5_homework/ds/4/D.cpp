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
    struct node
    {
        T data;
        node* next;
        bool operator== (node x) {
            return this == &x;
        }
    }*head, * tail;
    int len = 0;
public:
    IQueue() {
        tail = head = new node();
    }
    void clear() {
        tail = head;
        len = 0;
    }
    bool isEmpty() {
        return head == tail;
    }
    int length() {
        return len;
    }
    T peek() {
        if (len == 0)return T();
        return tail->data;
    }
    T del() {
        if (len == 0)return T();
        auto r = tail->data;
        tail = tail->next;
        len--;
        return r;
    }
    void insert(T x) {
        head->data = x;
        // std::cout << tail->data << ' ' << x << '\n';
        head = head->next = new node();
        len++;
    }
    void display() {
        std::vector<T> res;
        for (auto i = tail;i != head;i = i->next) {
            res.push_back(i->data);
        }
        ranges::reverse(res);
        for (T x : res)std::cout << x << " ";
    }
};

void solve() {
    IQueue<int> queue;
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