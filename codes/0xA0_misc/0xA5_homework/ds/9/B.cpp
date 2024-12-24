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

struct Student_Tree
{
    struct Student
    {
        std::string name;
        std::string gender;
        int id = 0;
        std::string cls;
        i64 telephone_number;
        Student() {}
        Student(std::string name, std::string gender, int id, std::string cls, i64 telephone_number) :
            name(name), gender(gender), id(id), cls(cls), telephone_number(telephone_number) {
        }
        bool operator<(Student b) {
            return id < b.id;
        }
        void print() {
            std::cout << "name:" << name << '\n';
            std::cout << "gender:" << gender << '\n';
            std::cout << "id:" << id << '\n';
            std::cout << "class:" << cls << '\n';
            std::cout << "telephone:" << telephone_number << '\n';
        }
    };
    struct node
    {
        Student stu;
        int left;
        int right;
        node() {
            left = 0;
            right = 0;
        }
        node(Student stu) :stu(stu), left(0), right(0) {}
    };
    std::vector<node> table;

    Student_Tree() {
        table.assign(2, node());
    }

    void addStudent(std::string name, std::string gender, int id, std::string cls, i64 telephone_number) {
        Student stu(name, gender, id, cls, telephone_number);
        int cur = 1;
        while (1) {
            if (stu < table[cur].stu) {
                if (table[cur].left == 0) {
                    table[cur].left = table.size();
                    table.push_back(node(stu));
                    break;
                }
                else {
                    cur = table[cur].left;
                }
            }
            else {
                if (table[cur].right == 0) {
                    table[cur].right = table.size();
                    table.push_back(node(stu));
                    break;
                }
                else {
                    cur = table[cur].right;
                }
            }
        }
    }
    Student query(int id) {
        int cur = 1;
        while (1) {
            if (id < table[cur].stu.id) {
                cur = table[cur].left;
            }
            else if (id > table[cur].stu.id) {
                cur = table[cur].right;
            }
            else {
                return table[cur].stu;
            }
            if (cur == 0) {
                return Student();
            }
        }
    }
};


void solve() {
    Student_Tree stu_tree;
    stu_tree.addStudent("fengling", "man", 20231702, "202305Z", 114514);
    stu_tree.addStudent("baiyuxiu", "woman", 12345678, "202305Z", 1919810);
    stu_tree.addStudent("baomengjia", "WuZhuangZhiShengJi", 12345679, "202305Z", 1919810);
    auto res = stu_tree.query(12345679);
    res.print();
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