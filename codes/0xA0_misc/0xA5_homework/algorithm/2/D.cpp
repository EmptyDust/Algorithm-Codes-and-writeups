#include <bits/stdc++.h>
using namespace std;

string m[] = {
    "4",    // A
    "|3",   // B
    "(",    // C
    "|)",   // D
    "3",    // E
    "|=",   // F
    "6",    // G
    "#",    // H
    "|",    // I
    "_|",   // J
    "|<",   // K
    "|_",   // L
    "|\\/|",// M 
    "|\\|", // N
    "0",    // O
    "|0",   // P
    "(,)",  // Q
    "|?",   // R
    "5",    // S
    "7",    // T
    "|_|",  // U
    "\\/",  // V
    "\\/\\/",// W
    "><",   // X
    "-/",   // Y
    "2"     // Z
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    if (!(cin >> s)) return 0;

    string t = "";
    for (char c : s) {
        t += m[c - 'A'];
    }

    int n = t.size();
    vector<long long> d(n + 1, 0);
    d[0] = 1;

    for (int i = 0; i < n; ++i) {
        if (d[i] == 0) continue;

        for (int j = 0; j < 26; ++j) {
            int len = m[j].size();
            if (i + len <= n && t.substr(i, len) == m[j]) {
                d[i + len] += d[i];
            }
        }
    }

    cout << d[n] << endl;

    return 0;
}