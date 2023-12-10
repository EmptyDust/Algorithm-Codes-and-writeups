#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n = word.length();
        int cnt = 0;
        for (int i = 1;i < n;++i) {
            if (abs(word[i] - word[i - 1]) <= 1) {
                word[i] = '0';
                cnt++;
            }
        }
        return cnt;
    }
};