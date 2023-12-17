#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int a, b, c;
    a = b = c = 0;
    cin >> s;
    for (char ch : s) {
        if (ch == 'a')a++;
        if (ch == 'b')b++;
        if (ch == 'c')c++;
    }
    if (a == 1 && b == 1 && c == 1) {
        cout << "Yes";

    }
    else {
        cout << "No";
    }
}