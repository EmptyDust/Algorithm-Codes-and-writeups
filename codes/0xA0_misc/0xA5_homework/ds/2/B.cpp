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
    struct Info {
        T data;
        Info* next;
    };
    Info* head = new Info();
public:
    void clear() {
        Info* it1 = head->next;
        if (it1 == nullptr)return;
        auto it2 = it1->next;
        while (it2 != nullptr) {
            delete(it1);
            it1 = it2;
            it2 = it1->next;
        }
        delete(it1);
        head->next = nullptr;
    }
    int length() {
        int cnt = 0;
        auto it = head->next;
        while (it != nullptr) {
            cnt++;
            it = it->next;
        }
        return cnt;
    }
    int get(int i) {
        auto it = head->next;
        int cur = 1;
        while (it->next && cur < i) {
            it = it->next;
            cur++;
        }
        if (it)return it->data;
        else {
            std::cerr << "Array Index Out of Bounds\n";
            return -1;
        }
    }
    void insert(int i, T x) {
        auto it = head;
        int cur = 0;
        while (it->next && cur < i) {
            it = it->next;
            cur++;
        }
        if (it) {
            Info* newinfo = new Info{ x,it->next };
            it->next = newinfo;
        }
        else {
            std::cerr << "Array Index Out of Bounds\n";
        }
    }
    void remove(int i) {
        auto it = head->next;
        int cur = 1;
        while (it->next && cur < i - 1) {
            it = it->next;
            cur++;
        }
        if (it && it->next) {
            auto tmp = it->next;
            it->next = it->next->next;
            delete(tmp);
        }
        else {
            std::cerr << "Array Index Out of Bounds\n";
        }
    }
    int indexof(T x) {
        auto it = head->next;
        int cur = 1;
        while (it) {
            if (it->data == x)
                return cur;
            it = it->next;
        }
        std::cout << "Not found.\n";
        return -1;
    }
    void reverse() {
        auto it1 = head->next;
        if (!it1)return;
        auto it2 = it1->next;
        it1->next = nullptr;
        if (!it2)return;
        auto it3 = it2->next;
        while (it3) {
            it2->next = it1;
            it1 = it2;
            it2 = it3;
            it3 = it2->next;
        }
        it2->next = it1;
        head->next = it2;
    }
    void display() {
        auto it = head->next;
        while (it != nullptr) {
            std::cout << it->data << ' ';
            it = it->next;
        }
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