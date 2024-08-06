#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

std::string res[9] = {
    "      O O O",
    "      O O O",
    "      O O O",
    "B B B Y Y Y G G G W W W",
    "B B B Y Y Y G G G W W W",
    "B B B Y Y Y G G G W W W",
    "      R R R",
    "      R R R",
    "      R R R"
};

std::string str[9];

void print() {
    for (int i = 0;i < 9;++i)
        std::cout << str[i] << '\n';
}

bool cmp() {
    bool f = true;
    for (int i = 0;i < 9;++i)for (int j = 0;j < res[i].size();++j)
        if (res[i][j] != str[i][j]) {
            f = false;
            break;
        }
    return f;
}

void rotate(int x, int y) {
    char ch = str[x][y];
    str[x][y] = str[x + 2][y];
    str[x + 2][y] = str[x + 2][y + 4];
    str[x + 2][y + 4] = str[x][y + 4];
    str[x][y + 4] = ch;

    ch = str[x][y + 2];
    str[x][y + 2] = str[x + 1][y];
    str[x + 1][y] = str[x + 2][y + 2];
    str[x + 2][y + 2] = str[x + 1][y + 4];
    str[x + 1][y + 4] = ch;
}

void RX() {
    char ch1 = str[3][18], ch2 = str[4][18], ch3 = str[5][18];
    rotate(3, 12);
    str[3][18] = str[2][10];
    str[4][18] = str[1][10];
    str[5][18] = str[0][10];

    str[2][10] = str[5][10];
    str[1][10] = str[4][10];
    str[0][10] = str[3][10];

    str[5][10] = str[8][10];
    str[4][10] = str[7][10];
    str[3][10] = str[6][10];

    str[8][10] = ch1;
    str[7][10] = ch2;
    str[6][10] = ch3;
}

void UX() {
    char ch1 = str[3][12], ch2 = str[4][12], ch3 = str[5][12];
    rotate(3, 6);
    str[3][12] = str[2][6];
    str[4][12] = str[2][8];
    str[5][12] = str[2][10];

    str[2][6] = str[5][4];
    str[2][8] = str[4][4];
    str[2][10] = str[3][4];

    str[5][4] = str[6][10];
    str[4][4] = str[6][8];
    str[3][4] = str[6][6];

    str[6][10] = ch1;
    str[6][8] = ch2;
    str[6][6] = ch3;
}

void FX() {
    rotate(6, 6);
    str[5] = str[5].substr(18) + " " + str[5].substr(0, 17);
}

std::vector<std::string> ans;
bool dfs(int t) {
    if (t > 8)return false;
    if (cmp())return true;
    //R1
    RX();
    if (dfs(t + 1)) {
        ans.push_back("R1");
        return true;
    }
    RX();
    RX();
    if (dfs(t + 1)) {
        ans.push_back("R2");
        return true;
    }
    RX();
    UX();
    if (dfs(t + 1)) {
        ans.push_back("U1");
        return true;
    }
    UX();
    UX();
    if (dfs(t + 1)) {
        ans.push_back("U2");
        return true;
    }
    UX();
    FX();
    if (dfs(t + 1)) {
        ans.push_back("F1");
        return true;
    }
    FX();
    FX();
    if (dfs(t + 1)) {
        ans.push_back("F2");
        return true;
    }
    FX();
    return false;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    for (int i = 0;i < 9;++i) {
        std::getline(std::cin, str[i]);
    }
    dfs(0);
    std::reverse(ans.begin(), ans.end());
    std::cout << ans.size() << "\n";
    for (auto s : ans)std::cout << s << '\n';

    return 0;
}